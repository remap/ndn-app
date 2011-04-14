/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc;

import com.mongodb.BasicDBList;
import com.mongodb.DBObject;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCEncryptionException;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCParseException;
import edu.ucla.cens.pdc.libpdc.util.EncryptionHelper;
import edu.ucla.cens.pdc.libpdc.util.Log;
import edu.ucla.cens.pdc.libpdc.util.StringUtil;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.Serializable;
import java.security.InvalidAlgorithmParameterException;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.security.SecureRandom;
import java.util.LinkedList;
import java.util.List;
import javax.crypto.BadPaddingException;
import javax.crypto.Cipher;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.KeyGenerator;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.SecretKey;
import javax.crypto.spec.IvParameterSpec;
import org.bouncycastle.crypto.BlockCipher;
import org.bouncycastle.crypto.BufferedBlockCipher;
import org.bouncycastle.crypto.engines.TwofishEngine;
import org.bouncycastle.crypto.modes.CBCBlockCipher;
import org.bouncycastle.crypto.paddings.PaddedBufferedBlockCipher;
import org.bouncycastle.crypto.params.KeyParameter;
import org.bson.BSONDecoder;
import org.bson.BSONEncoder;
import org.bson.BSONObject;
import org.ccnx.ccn.KeyManager;
import org.ccnx.ccn.protocol.PublisherPublicKeyDigest;

/**
 *
 * @author Derek Kulinski
 */
public class DataEncryptor implements Serializable {
	private static final long serialVersionUID = -8548399076599734736L;

	private transient BufferedBlockCipher _cipher;

	private byte[] _encrypt_key;

	private transient byte[] _encrypt_iv;

	private byte[] _decrypt_key;

	private transient byte[] _decrypt_iv;

	/**
	 * keys associated with our stream
	 */
	protected PublisherPublicKeyDigest _stream_key_digest;

	public DataEncryptor()
	{
		classSetup();
	}

	private void classSetup()
	{
		BlockCipher engine = new TwofishEngine();

		//TODO: Make use of CTR/SIC mode (needs a good iv)
//		BlockCipher mode = new SICBlockCipher(engine);
		BlockCipher mode = new CBCBlockCipher(engine);

//		_cipher = new BufferedBlockCipher(mode);
//		_cipher = new CTSBlockCipher(mode);
		_cipher = new PaddedBufferedBlockCipher(mode);

//		// This version doesn't do any encryption
//		BlockCipher engine = new NullEngine();
//		_cipher = new BufferedBlockCipher(engine);
	}

	public byte[] getEncryptKey()
	{
		return _encrypt_key;
	}

	public byte[] getDecryptKey()
	{
		return _decrypt_key;
	}

	public void setEncryptKey(byte[] key)
	{
		this._encrypt_key = key;
	}

	public void setDecryptKey(byte[] key)
	{
		this._decrypt_key = key;
	}

	public PublisherPublicKeyDigest getStreamKeyDigest()
	{
		return _stream_key_digest;
	}

	/**
	 *
	 * @param digest
	 * @deprecated this won't be needed later, as the keys will be automatically
	 * generated
	 */
	public void setStreamKeyDigest(PublisherPublicKeyDigest digest)
	{
		this._stream_key_digest = digest;
	}

	public PublisherPublicKeyDigest generateStreamKeys()
	{
		_stream_key_digest = EncryptionHelper.generatePublisherKeys();

		return _stream_key_digest;
	}

	public byte[] encryptRecord(iBSONExportable record)
					throws PDCEncryptionException
	{
		return encryptData(record.toBSON());
	}

	public byte[] encryptData(byte[] data)
					throws PDCEncryptionException
	{
		byte[] ciphertext;
		int output_len;

		if (_encrypt_key == null)
			throw new PDCEncryptionException("No encryption key set");


		_cipher.init(true, new KeyParameter(_encrypt_key));
//		_cipher.reset();

//		byte[] iv = generateIV(application, stream);
//		Log.debug(new String(iv));
//		_cipher.init(true, new ParametersWithIV(new KeyParameter(aclkey), iv));

		ciphertext = new byte[_cipher.getOutputSize(data.length)];
		output_len = _cipher.processBytes(data, 0, data.length, ciphertext, 0);

		try {
			_cipher.doFinal(ciphertext, output_len);
			return ciphertext;
		}
		catch (Exception ex) {
			throw new PDCEncryptionException("Unable to encrypt stream", ex);
		}
	}

	public DataRecord decryptRecord(byte[] cipherText)
					throws PDCEncryptionException
	{
		byte[] decrypted;

		decrypted = decryptData(cipherText);

		try {
			return new DataRecord().fromBSON(decrypted);
		}
		catch (PDCParseException ex) {
			throw new PDCEncryptionException("Got invalid BSON", ex);
		}
	}

	public byte[] decryptData(byte[] cipherText)
					throws PDCEncryptionException
	{
		byte[] buffer, decrypted;
		int outputLen;

		if (_decrypt_key == null)
			throw new PDCEncryptionException("No decryption key set");

		_cipher.init(false, new KeyParameter(_decrypt_key));

//		byte[] iv = generateIV(app, acl);
//		_cipher.init(false, new ParametersWithIV(new KeyParameter(aclkey), iv));

		buffer = new byte[_cipher.getOutputSize(cipherText.length)];
		outputLen = _cipher.processBytes(cipherText, 0, cipherText.length, buffer,
						0);

		try {
			outputLen += _cipher.doFinal(buffer, outputLen);

			decrypted = new byte[outputLen];
			System.arraycopy(buffer, 0, decrypted, 0, outputLen);

			return decrypted;
		}
		catch (Exception ex) {
			throw new PDCEncryptionException("Unable to decrypt the data", ex);
		}
	}

	public static byte[] wrapKey(PublicKey public_key, SecretKey secret_key)
					throws PDCEncryptionException
	{
		String alg;
		Cipher cipher;

		//CBC/PKCS1Padding or ISO9796d1Encoding, not sure what's better?
		//XXX: why CBC or CFB are bad?
		alg = public_key.getAlgorithm() + "/ECB/PKCS1Padding";

		try {
			cipher = Cipher.getInstance(alg);
			cipher.init(Cipher.WRAP_MODE, public_key);
			return cipher.wrap(secret_key);
		}
		catch (IllegalBlockSizeException ex) {
			throw new PDCEncryptionException("Unable to wrap key in " + public_key.
							toString(), ex);
		}
		catch (InvalidKeyException ex) {
			throw new PDCEncryptionException("Unable to wrap key in " + public_key.
							toString(), ex);
		}
		catch (NoSuchAlgorithmException ex) {
			throw new PDCEncryptionException("Unable to wrap key in " + public_key.
							toString(), ex);
		}
		catch (NoSuchPaddingException ex) {
			throw new PDCEncryptionException("Unable to wrap key in " + public_key.
							toString(), ex);
		}
	}

	public static SecretKey unwrapKey(PrivateKey private_key, byte[] wrapped_key)
					throws PDCEncryptionException
	{
		String alg;
		Cipher cipher;
		SecretKey secret_key;

		alg = private_key.getAlgorithm() + "/ECB/PKCS1Padding";
		try {
			cipher = Cipher.getInstance(alg);
			cipher.init(Cipher.UNWRAP_MODE, private_key);
			secret_key = (SecretKey) cipher.unwrap(wrapped_key, "AES",
							Cipher.SECRET_KEY);

			return secret_key;
		}
		catch (NoSuchPaddingException ex) {
			throw new PDCEncryptionException("Unable to unwrap key", ex);
		}
		catch (InvalidKeyException ex) {
			throw new PDCEncryptionException("Unable to unwrap key", ex);
		}
		catch (NoSuchAlgorithmException ex) {
			throw new PDCEncryptionException("Unable to unwrap key", ex);
		}
	}

	public static byte[] encryptAsymData(PublicKey public_key, byte[] data)
					throws PDCEncryptionException
	{
		BSONEncoder encoder = new BSONEncoder();
		DBObject obj = new BasicDBList();
		SecureRandom random = new SecureRandom();
		KeyGenerator kg;
		Cipher cipher;
		SecretKey secret_key;
		byte[] ciphertext;
		byte[] iv;

		try {
			kg = KeyGenerator.getInstance("AES");
		}
		catch (NoSuchAlgorithmException ex) {
			throw new PDCEncryptionException("No AES available", ex);
		}

		kg.init(128, random);
		secret_key = kg.generateKey();

		obj.put("0", wrapKey(public_key, secret_key));

		try {
			cipher = Cipher.getInstance("AES/CTR/PKCS7Padding");

			iv = new byte[cipher.getBlockSize()];
			random.nextBytes(iv);
			obj.put("1", iv);

			cipher.init(Cipher.ENCRYPT_MODE, secret_key, new IvParameterSpec(iv));

			ciphertext = cipher.doFinal(data);
			obj.put("2", ciphertext);

			return encoder.encode(obj);
		}
		catch (InvalidAlgorithmParameterException ex) {
			throw new PDCEncryptionException("Unable to encrypt message to " + public_key.
							toString(), ex);
		}
		catch (BadPaddingException ex) {
			throw new PDCEncryptionException("Unable to encrypt message to " + public_key.
							toString(), ex);
		}
		catch (IllegalBlockSizeException ex) {
			throw new PDCEncryptionException("Unable to encrypt message to " + public_key.
							toString(), ex);
		}
		catch (InvalidKeyException ex) {
			throw new PDCEncryptionException("Unable to encrypt message to " + public_key.
							toString(), ex);
		}
		catch (NoSuchAlgorithmException ex) {
			throw new PDCEncryptionException("Unable to encrypt message to " + public_key.
							toString(), ex);
		}
		catch (NoSuchPaddingException ex) {
			throw new PDCEncryptionException("Unable to encrypt message to " + public_key.
							toString(), ex);
		}
	}

	public static byte[] decryptAsymData(PrivateKey private_key, byte[] cipherText)
					throws PDCEncryptionException
	{
		BSONDecoder decoder = new BSONDecoder();
		Cipher cipher;
		BSONObject obj;
		SecretKey secret_key;
		byte[] aes_ciphertext, iv;

		assert private_key != null;

		try {
			obj = decoder.readObject(cipherText);
		}
		catch (RuntimeException ex) {
			throw new PDCEncryptionException("invalida data", ex);
		}

		secret_key = unwrapKey(private_key, (byte[]) obj.get("0"));
		iv = (byte[]) obj.get("1");
		try {
			cipher = Cipher.getInstance("AES/CTR/PKCS7Padding");
			cipher.init(Cipher.DECRYPT_MODE, secret_key, new IvParameterSpec(iv));

			aes_ciphertext = (byte[]) obj.get("2");

			return cipher.doFinal(aes_ciphertext);
		}
		catch (InvalidAlgorithmParameterException ex) {
			throw new PDCEncryptionException("Unable to decrypt message", ex);
		}
		catch (IllegalBlockSizeException ex) {
			throw new PDCEncryptionException("Unable to decrypt message", ex);
		}
		catch (BadPaddingException ex) {
			throw new PDCEncryptionException("Unable to decrypt message", ex);
		}
		catch (InvalidKeyException ex) {
			throw new PDCEncryptionException("Unable to decrypt message", ex);
		}
		catch (NoSuchAlgorithmException ex) {
			throw new PDCEncryptionException("Unable to decrypt message", ex);
		}
		catch (NoSuchPaddingException ex) {
			throw new PDCEncryptionException("Unable to decrypt message", ex);
		}
	}

	public byte[] decryptAsymData(byte[] cipherText)
					throws PDCEncryptionException
	{
		GlobalConfig config = GlobalConfig.getInstance();
		KeyManager keymgr;
		PrivateKey private_key;

		Log.debug("Decrypting data using my key: " + _stream_key_digest);

		keymgr = config.getKeyManager();
		assert keymgr != null;

		private_key = keymgr.getSigningKey(_stream_key_digest);
		assert private_key != null;

		return decryptAsymData(private_key, cipherText);
	}

	private byte[] repeat(int size, String pattern)
	{
		byte[] result = new byte[size];
		byte[] pat = pattern.getBytes();
		int result_pos, pat_pos;

		for (result_pos = 0, pat_pos = 0; result_pos < size; result_pos++) {
			result[result_pos] = pat[pat_pos];

			pat_pos++;
			pat_pos %= pat.length;
		}

		return result;
	}

	private byte[] generateIV(iApplication app, String data_stream)
	{
		return repeat(_cipher.getBlockSize(), data_stream.concat(app.getAppName()));
	}

	@Override
	public String toString()
	{
		List<String> data = new LinkedList<String>();
		StringBuilder sb = new StringBuilder();

		sb.append(this.getClass().getSimpleName());
		sb.append('[');
		data.add(_cipher.toString());
		data.add(_decrypt_iv == null ? null : "set");
		data.add(_decrypt_key == null ? null : "set");
		data.add(_encrypt_iv == null ? null : "set");
		data.add(_encrypt_key == null ? null : "set");
		data.add(_stream_key_digest == null ? null : _stream_key_digest.toString());
		sb.append(StringUtil.join(data, "; "));
		sb.append(']');

		return sb.toString();
	}

// <editor-fold defaultstate="collapsed" desc="serialization code">
	private void readObject(ObjectInputStream in)
					throws IOException, ClassNotFoundException
	{
		in.defaultReadObject();
		classSetup();
	}
// </editor-fold>
}
