/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc.core;

import edu.ucla.cens.pdc.libpdc.exceptions.PDCEncryptionException;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCTransmissionException;
import edu.ucla.cens.pdc.libpdc.iBSONExportable;
import edu.ucla.cens.pdc.libpdc.util.EncryptionHelper;
import java.security.InvalidKeyException;
import java.security.PrivateKey;
import java.security.SignatureException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.crypto.SecretKey;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.KeyManager;
import org.ccnx.ccn.impl.security.keys.BasicKeyManager;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.ContentObject;
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.protocol.KeyLocator;
import org.ccnx.ccn.protocol.PublisherPublicKeyDigest;
import org.ccnx.ccn.protocol.SignedInfo;

/**
 *
 * @author Derek Kulinski
 */
public final class PDCWebClient {
	public PDCWebClient()
	{
		_config = GlobalConfig.getInstance();
		assert _config != null;

		final KeyManager keymgr = _config.getKeyManager();
		assert keymgr != null;

		_pdc_identity = keymgr.getDefaultKeyID();
		assert _pdc_identity != null;

		_pdc_key = keymgr.getDefaultSigningKey();
		assert _pdc_key != null;

		_pdc_key_locator = keymgr.getDefaultKeyLocator();
		assert _pdc_key_locator != null;
	}

	public boolean sendEncryptedResponse(Interest interest, iBSONExportable data)
			throws PDCTransmissionException, PDCEncryptionException
	{
		assert _WCSymmKey != null;

		final byte[] encrypted;
		encrypted = EncryptionHelper.encryptSymData(_WCSymmKey, data.toBSON());

		return sendResponse(interest, encrypted);
	}

	private boolean sendResponse(Interest interest, byte[] data)
			throws PDCTransmissionException
	{
		assert _pdc_identity != null;
		assert _pdc_key != null;
		assert _pdc_key_locator != null;

		CCNHandle handle = _config.getCCNHandle();
		assert handle != null;

		SignedInfo si = new SignedInfo(_pdc_identity, SignedInfo.ContentType.ENCR,
				_pdc_key_locator, 1, null);

		try {
			ContentObject co = new ContentObject(interest.name(), si, data, _pdc_key);
			return handle.put(co) != null;
		}
		catch (Exception ex) {
			throw new PDCTransmissionException("Error while publishing data: " + ex.
					getLocalizedMessage(), ex);
		}
	}

	public SecretKey getWCSymmKey() //TODO will want to add userID parameter
	{
		return this._WCSymmKey;
	}

	public void setWCSymmKey(SecretKey key) //TODO will want to add userID parameter
	{
		this._WCSymmKey = key;
	}
	//TODO will eventually want a map of users to keys

	private SecretKey _WCSymmKey;

	private final GlobalConfig _config;

	private final PublisherPublicKeyDigest _pdc_identity;

	private final PrivateKey _pdc_key;

	private final KeyLocator _pdc_key_locator;
}
