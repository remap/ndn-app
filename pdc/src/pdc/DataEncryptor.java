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
import org.bouncycastle.crypto.params.ParametersWithIV;

/**
 *
 * @author takeda
 */
class DataEncryptor {

	private BufferedBlockCipher _cipher;

	public DataEncryptor() {
//		_cipher = new DESEngine();
//		_cipher = new PaddedBufferedBlockCipher(new CBCBlockCipher(engine));
//		BlockCipher engine = new AESEngine();

		BlockCipher engine = new TwofishEngine();
		_cipher = new PaddedBufferedBlockCipher(new CBCBlockCipher(engine));

		// This version doesn't do any encryption
//		BlockCipher engine = new NullEngine();
//		_cipher = new BufferedBlockCipher(engine);
	}

	byte[] encryptData(Application application, DataStream stream, byte[] data) {
		return encryptData(application, stream.id, data);
	}

	byte[] encryptData(Application application, String stream, byte[] data) {
		byte[] aclkey = application.data_stream_get_key(stream);

		if (aclkey == null)
			return null;

		byte[] iv = generateIV(application, stream);

		//XXX: for performance we might just keep multiple ciphers in memory
		_cipher.init(true, new ParametersWithIV(new KeyParameter(aclkey), iv));
//		_cipher.init(true, new KeyParameter(aclkey));

		byte[] cipherText = new byte[_cipher.getOutputSize(data.length)];
		int outputLen = _cipher.processBytes(data, 0, data.length, cipherText, 0);
		try {
			_cipher.doFinal(cipherText, outputLen);
		} catch (DataLengthException ex) {
			Logger.getLogger(DataEncryptor.class.getName()).log(Level.SEVERE, null, ex);
		} catch (IllegalStateException ex) {
			Logger.getLogger(DataEncryptor.class.getName()).log(Level.SEVERE, null, ex);
		} catch (InvalidCipherTextException ex) {
			Logger.getLogger(DataEncryptor.class.getName()).log(Level.SEVERE, null, ex);
		}

		return cipherText;
	}

	byte[] decryptData(Application app, String acl, byte[] cipherText) {
		byte[] aclkey = app.data_stream_get_key(acl);

		if (aclkey == null)
			return null;

		byte[] iv = generateIV(app, acl);
		_cipher.init(false, new ParametersWithIV(new KeyParameter(aclkey), iv));

		byte[] data = new byte[_cipher.getOutputSize(cipherText.length)];
		int outputLen = _cipher.processBytes(cipherText, 0, cipherText.length, data, 0);
		try {
			_cipher.doFinal(data, outputLen);
		} catch (DataLengthException ex) {
			Logger.getLogger(DataEncryptor.class.getName()).log(Level.SEVERE, null, ex);
		} catch (IllegalStateException ex) {
			Logger.getLogger(DataEncryptor.class.getName()).log(Level.SEVERE, null, ex);
		} catch (InvalidCipherTextException ex) {
			Logger.getLogger(DataEncryptor.class.getName()).log(Level.SEVERE, null, ex);
		}

		return data;
	}

	private byte[] repeat(int size, String pattern) {
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

	private byte[] generateIV(Application app, String acl) {
		return repeat(_cipher.getBlockSize(), acl.concat(app.name));
	}
}
