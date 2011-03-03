/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc;

import edu.ucla.cens.pdc.libpdc.exceptions.PDCEncryptionException;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCException;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCParseException;
import edu.ucla.cens.pdc.libpdc.util.Log;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.bouncycastle.crypto.BlockCipher;
import org.bouncycastle.crypto.BufferedBlockCipher;
import org.bouncycastle.crypto.DataLengthException;
import org.bouncycastle.crypto.InvalidCipherTextException;
import org.bouncycastle.crypto.RuntimeCryptoException;
import org.bouncycastle.crypto.engines.NullEngine;
import org.bouncycastle.crypto.engines.TwofishEngine;
import org.bouncycastle.crypto.modes.CBCBlockCipher;
import org.bouncycastle.crypto.paddings.PaddedBufferedBlockCipher;
import org.bouncycastle.crypto.params.KeyParameter;

/**
 *
 * @author Derek Kulinski
 */
public class DataEncryptor {
	private BufferedBlockCipher _cipher;

	private byte[] _encrypt_key;

	private byte[] _encrypt_iv;

	private byte[] _decrypt_key;

	private byte[] _decrypt_iv;

	public DataEncryptor()
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

	public void setEncryptKey(byte[] key)
	{
		this._encrypt_key = key;
	}

	public void setDecryptKey(byte[] key)
	{
		this._decrypt_key = key;
	}

	public byte[] encryptRecord(iBSONExportable record)
					throws PDCEncryptionException
	{
		return encryptData(record.toBSON());
	}

	public byte[] encryptData(byte[] data)
					throws PDCEncryptionException
	{
		byte[] cipherText;
		int outputLen;

		if (_encrypt_key == null)
			throw new PDCEncryptionException("No encryption key set");


		_cipher.init(true, new KeyParameter(_encrypt_key));
//		_cipher.reset();

//		byte[] iv = generateIV(application, stream);
//		Log.debug(new String(iv));
//		_cipher.init(true, new ParametersWithIV(new KeyParameter(aclkey), iv));

		cipherText = new byte[_cipher.getOutputSize(data.length)];
		outputLen = _cipher.processBytes(data, 0, data.length, cipherText, 0);

		try {
			_cipher.doFinal(cipherText, outputLen);
			return cipherText;
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
}
