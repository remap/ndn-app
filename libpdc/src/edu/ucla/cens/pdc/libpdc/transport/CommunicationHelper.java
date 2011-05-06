/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc.transport;

import edu.ucla.cens.pdc.libpdc.datastructures.Authenticator;
import edu.ucla.cens.pdc.libpdc.Constants;
import edu.ucla.cens.pdc.libpdc.stream.DataEncryptor;
import edu.ucla.cens.pdc.libpdc.stream.DataStream;
import edu.ucla.cens.pdc.libpdc.core.GlobalConfig;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCEncryptionException;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCParseException;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCTransmissionException;
import edu.ucla.cens.pdc.libpdc.util.EncryptionHelper;
import java.io.IOException;
import java.security.PrivateKey;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.KeyManager;
import org.ccnx.ccn.config.SystemConfiguration;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.ContentObject;
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.protocol.KeyLocator;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import org.ccnx.ccn.protocol.PublisherPublicKeyDigest;
import org.ccnx.ccn.protocol.SignedInfo;

/**
 *
 * @author Derek Kulinski
 */
public class CommunicationHelper {
	public static Authenticator requestAuthenticator(CCNHandle handle,
					DataStream ds, PDCReceiver publisher)
					throws PDCTransmissionException
	{
		GlobalConfig config = GlobalConfig.getInstance();
		KeyManager keymgr;
		ContentName uri;
		ContentObject response;
		byte[] decoded;
		PublisherPublicKeyDigest digest;
		PrivateKey private_key;
		Authenticator authenticator;

		digest = ds.app.getKeyDigest();
		assert digest != null : "No key set for application";

		keymgr = config.getKeyManager();
		assert keymgr != null : "No key manager";

		private_key = keymgr.getSigningKey(digest);
		assert private_key != null : "No key in key manager";

		try {
			uri = ds.getPublisherStreamURI().
							append(Constants.STR_CONTROL).append("authenticator");
			response = handle.get(uri, SystemConfiguration.MEDIUM_TIMEOUT);

			if (response == null)
				return null;

			//XXX: do verification

			decoded = EncryptionHelper.decryptAsymData(private_key, response.content());

			authenticator = new Authenticator().fromBSON(decoded);

			return authenticator;
		}
		catch (PDCParseException ex) {
			throw new PDCTransmissionException("Errror while processing the message",
							ex);
		}
		catch (PDCEncryptionException ex) {
			throw new PDCTransmissionException("Error while decoding the message", ex);
		}
		catch (IOException ex) {
			throw new PDCTransmissionException(
							"Error while sending authenticator interest", ex);
		}
		catch (MalformedContentNameStringException ex) {
			throw new Error("Unable to construct URI to request authenticator");
		}
	}

	public static boolean publishEncryptedData(CCNHandle handle,
					Interest interest, PublisherPublicKeyDigest sender_identity,
					byte[] data, int freshness)
					throws PDCTransmissionException
	{
		GlobalConfig config;
		SignedInfo si;
		ContentObject co;
		KeyManager keymgr;
		KeyLocator key_locator;
		PrivateKey signing_key;

		assert interest != null;
		assert sender_identity != null;
		assert data != null;

		config = GlobalConfig.getInstance();
		keymgr = config.getKeyManager();
		assert keymgr != null;

		signing_key = keymgr.getSigningKey(sender_identity);
		assert signing_key != null : "no signing key for " + sender_identity;

		key_locator = keymgr.getKeyLocator(sender_identity);
		assert key_locator != null;

		try {
			si = new SignedInfo(sender_identity, SignedInfo.ContentType.ENCR,
							key_locator, freshness, null);
			co = new ContentObject(interest.name(), si, data, signing_key);

			handle.put(co);

			return true;
		}
		catch (Exception ex) {
			throw new PDCTransmissionException("Error while publishing data", ex);
		}
	}
}
