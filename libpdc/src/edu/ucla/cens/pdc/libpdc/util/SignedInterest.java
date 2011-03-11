/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc.util;

import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.security.Key;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;
import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.zip.Adler32;
import java.util.zip.Checksum;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import org.bouncycastle.crypto.BlockCipher;
import org.bouncycastle.crypto.BufferedBlockCipher;
import org.bouncycastle.crypto.DataLengthException;
import org.bouncycastle.crypto.InvalidCipherTextException;
import org.bouncycastle.crypto.engines.AESEngine;
import org.bouncycastle.crypto.modes.CBCBlockCipher;
import org.bouncycastle.crypto.paddings.PaddedBufferedBlockCipher;
import org.bouncycastle.crypto.params.KeyParameter;
import org.bouncycastle.util.encoders.Base64;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;

/**
 *
 * @author Derek Kulinski
 */
public class SignedInterest {
	private SecureRandom _random;
	private Key _symmetricKey = null;
	private BufferedBlockCipher _cipher;
	private Set<String> _nonces = new LinkedHashSet<String>();

	public SignedInterest()
					throws NoSuchAlgorithmException
	{
		this(genKey());
	}

	public SignedInterest(Key key)
					throws NoSuchAlgorithmException
	{
		_random = SecureRandom.getInstance("SHA1PRNG");

		BlockCipher engine = new AESEngine();
		BlockCipher mode = new CBCBlockCipher(engine);
		_cipher = new PaddedBufferedBlockCipher(mode);

		_symmetricKey = key;
	}

	public String signName(ContentName name)
	{
		ContentName result;
		String nonce, crc;
		byte[] encrypted;

		assert name != null;

		try {
			// prepend nonce
			nonce = genNonce();
			result = ContentName.ROOT.append(nonce).append(name);

			// prepend crc
			crc = genChecksum(result.toString());
			result = ContentName.ROOT.append(crc).append(result);

			encrypted = encrypt(result.toString().getBytes());

			return new String(encrypted);
		}
		catch (MalformedContentNameStringException ex) {
			throw new Error("Error while appeding a nonce", ex);
		}
	}

	public ContentName verifyName(String name)
	{
		byte[] decrypted;
		ContentName decName;
		String crc, nonce;

		// Decrypt the command
		decrypted = decrypt(name.getBytes());
		try {
			decName = ContentName.fromNative(new String(decrypted));
		}
		catch (MalformedContentNameStringException ex) {
			return null;
		}

		// Make sure we have at least 3 components
		// <hash>/<nonce>/<name>
		if (decName.count() < 3)
			return null;

		// Verify checksum
		crc = genChecksum(decName.subname(1, decName.count() - 1).toString());
		if (!crc.equals(decName.stringComponent(0)))
			return null;

		// Check the nonce
		nonce = decName.stringComponent(1);
		if (_nonces.contains(nonce))
			return null;

		_nonces.add(nonce);

		return decName.subname(2, decName.count() - 2);
	}

	public Key getKey()
	{
		assert _symmetricKey != null;
		return _symmetricKey;
	}

	private static Key genKey()
					throws NoSuchAlgorithmException
	{
		KeyGenerator kg = KeyGenerator.getInstance("AES");
		return kg.generateKey();
	}

	private String genChecksum(String text)
	{
		byte[] input = text.getBytes();
		Checksum cksum = new Adler32();

		cksum.reset();
		cksum.update(input, 0, input.length);

		// Generate base64 encoding
		ByteArrayOutputStream bos = new ByteArrayOutputStream();
		DataOutputStream dos = new DataOutputStream(bos);
		try {
			dos.writeLong(cksum.getValue());
			dos.flush();
			return new String(Base64.encode(bos.toByteArray()));
		}
		catch (IOException ex) {
			throw new Error("Unable to generate base64 encoding", ex);
		}

//		return Long.toHexString(cksum.getValue());
	}

	private String genNonce()
	{
		byte[] nonce = new byte[8];

		_random.nextBytes(nonce);

		return new String(nonce);
	}

	private byte[] encrypt(byte[] input)
	{
		byte[] buffer;
		int outputLen;

		assert _symmetricKey != null;

		_cipher.init(true, new KeyParameter(_symmetricKey.getEncoded()));
		buffer = new byte[_cipher.getOutputSize(input.length)];

		try {
			outputLen = _cipher.processBytes(input, 0, input.length, buffer, 0);
			outputLen += _cipher.doFinal(buffer, outputLen);

			return buffer;
		}
		catch (DataLengthException ex) {
			Logger.getLogger(SignedInterest.class.getName()).log(Level.SEVERE, null,
							ex);
		}
		catch (IllegalStateException ex) {
			Logger.getLogger(SignedInterest.class.getName()).log(Level.SEVERE, null,
							ex);
		}
		catch (InvalidCipherTextException ex) {
			Logger.getLogger(SignedInterest.class.getName()).log(Level.SEVERE, null,
							ex);
		}

		return null;
	}

	private byte[] decrypt(byte[] input)
	{
		byte[] buffer, decrypted;
		int outputLen;

		assert _symmetricKey != null;

		_cipher.init(false, new KeyParameter(_symmetricKey.getEncoded()));
		buffer = new byte[_cipher.getOutputSize(input.length)];

		try {
			outputLen = _cipher.processBytes(input, 0, input.length, buffer, 0);
			outputLen += _cipher.doFinal(buffer, outputLen);
			decrypted = new byte[outputLen];
			System.arraycopy(buffer, 0, decrypted, 0, outputLen);

			return decrypted;
		}
		catch (DataLengthException ex) {
			Logger.getLogger(SignedInterest.class.getName()).log(Level.SEVERE, null,
							ex);
		}
		catch (IllegalStateException ex) {
			Logger.getLogger(SignedInterest.class.getName()).log(Level.SEVERE, null,
							ex);
		}
		catch (InvalidCipherTextException ex) {
			Logger.getLogger(SignedInterest.class.getName()).log(Level.SEVERE, null,
							ex);
		}
		return null;
	}
}
