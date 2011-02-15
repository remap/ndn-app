/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pdc;

import java.util.logging.Level;
import java.util.logging.Logger;
import org.bouncycastle.crypto.BlockCipher;
import org.bouncycastle.crypto.BufferedBlockCipher;
import org.bouncycastle.crypto.DataLengthException;
import org.bouncycastle.crypto.InvalidCipherTextException;
import org.bouncycastle.crypto.engines.NullEngine;
import org.bouncycastle.crypto.engines.TwofishEngine;
import org.bouncycastle.crypto.modes.CBCBlockCipher;
import org.bouncycastle.crypto.paddings.PaddedBufferedBlockCipher;
import org.bouncycastle.crypto.params.KeyParameter;
import pdc.exceptions.PDCException;
import pdc.util.Log;

/**
 *
 * @author Derek Kulinski
 */
public class DataEncryptor {
	private BufferedBlockCipher _cipher;

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

	byte[] encryptData(DataStream stream, byte[] data)
					throws PDCException
	{
		byte[] cipherText;
		int outputLen;

		if (stream.key == null)
			throw new PDCException("Data stream key is not set");

		_cipher.init(true, new KeyParameter(stream.key));

//		byte[] iv = generateIV(application, stream);
//		Log.debug(new String(iv));
//		_cipher.init(true, new ParametersWithIV(new KeyParameter(aclkey), iv));

		cipherText = new byte[_cipher.getOutputSize(data.length)];
		outputLen = _cipher.processBytes(data, 0, data.length, cipherText, 0);

		try {
			_cipher.doFinal(cipherText, outputLen);
			return cipherText;
		}
		catch (DataLengthException ex) {
			Logger.getLogger(DataEncryptor.class.getName()).log(Level.SEVERE, null, ex);
		}
		catch (IllegalStateException ex) {
			Logger.getLogger(DataEncryptor.class.getName()).log(Level.SEVERE, null, ex);
		}
		catch (InvalidCipherTextException ex) {
			Logger.getLogger(DataEncryptor.class.getName()).log(Level.SEVERE, null, ex);
		}

		return null;
	}

	byte[] decryptData(DataStream stream, byte[] cipherText)
	{
		byte[] buffer, decrypted;
		int outputLen;

		if (stream.key == null) {
			Log.error("Data stream key is not set");
			return null;
		}

		_cipher.init(false, new KeyParameter(stream.key));

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
		catch (DataLengthException ex) {
			Logger.getLogger(DataEncryptor.class.getName()).log(Level.SEVERE, null, ex);
		}
		catch (IllegalStateException ex) {
			Logger.getLogger(DataEncryptor.class.getName()).log(Level.SEVERE, null, ex);
		}
		catch (InvalidCipherTextException ex) {
			Logger.getLogger(DataEncryptor.class.getName()).log(Level.SEVERE, null, ex);
		}

		return null;
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

	private byte[] generateIV(Application app, String data_stream)
	{
		return repeat(_cipher.getBlockSize(), data_stream.concat(app.name));
	}
}
