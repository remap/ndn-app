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
import org.bouncycastle.crypto.engines.TwofishEngine;
import org.bouncycastle.crypto.modes.CBCBlockCipher;
import org.bouncycastle.crypto.modes.CTSBlockCipher;
import org.bouncycastle.crypto.params.KeyParameter;
import pdc.util.Log;

/**
 *
 * @author takeda
 */
public class DataEncryptor {
	private BufferedBlockCipher _cipher;

	public DataEncryptor()
	{
//		_cipher = new DESEngine();
//		_cipher = new PaddedBufferedBlockCipher(new CBCBlockCipher(engine));
//		BlockCipher engine = new AESEngine();

		BlockCipher engine = new TwofishEngine();

		BlockCipher mode = new CBCBlockCipher(engine);
//		BlockCipher mode = new SICBlockCipher(engine);

//		_cipher = new BufferedBlockCipher(mode);
		_cipher = new CTSBlockCipher(mode);
//		_cipher = new PaddedBufferedBlockCipher(mode);

//		// This version doesn't do any encryption
//		BlockCipher engine = new NullEngine();
//		_cipher = new BufferedBlockCipher(engine);
	}

	byte[] encryptData(DataStream stream, byte[] data)
	{
		byte[] cipherText;
		int outputLen;

		if (stream.key == null) {
			Log.error("Data stream key is not set");
			return null;
		}


		_cipher.init(true, new KeyParameter(stream.key));

//		byte[] iv = generateIV(application, stream);
//		Log.debug(new String(iv));
//		_cipher.init(true, new ParametersWithIV(new KeyParameter(aclkey), iv));

		cipherText = new byte[_cipher.getOutputSize(data.length)];
		outputLen = _cipher.processBytes(data, 0, data.length, cipherText, 0);

		try {
			_cipher.doFinal(cipherText, outputLen);
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

		return cipherText;
	}

	byte[] decryptData(DataStream stream, byte[] cipherText)
	{
		byte[] decrypted;
		int outputLen;

		if (stream.key == null)
			return null;

		_cipher.init(false, new KeyParameter(stream.key));

//		byte[] iv = generateIV(app, acl);
//		_cipher.init(false, new ParametersWithIV(new KeyParameter(aclkey), iv));

		decrypted = new byte[_cipher.getOutputSize(cipherText.length)];
		outputLen = _cipher.processBytes(cipherText, 0, cipherText.length, decrypted,
						0);

		try {
			_cipher.doFinal(decrypted, outputLen);
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

		return decrypted;
	}

	/**
	 * @deprecated 
	 * @param app
	 * @param stream_id
	 * @param cipherText
	 * @return
	 */
	byte[] decryptData(Application app, String stream_id, byte[] cipherText)
	{
		DataStream stream = app.data_stream_get(stream_id);
		assert stream != null;

		return decryptData(stream, cipherText);
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
