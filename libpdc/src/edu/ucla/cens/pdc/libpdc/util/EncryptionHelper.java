/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc.util;

import edu.ucla.cens.pdc.libpdc.GlobalConfig;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.security.InvalidKeyException;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.KeyStore;
import java.security.NoSuchAlgorithmException;
import java.security.SignatureException;
import java.security.cert.CertificateEncodingException;
import java.security.cert.X509Certificate;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.ccnx.ccn.KeyManager;
import org.ccnx.ccn.config.UserConfiguration;
import org.ccnx.ccn.impl.security.crypto.util.MinimalCertificateGenerator;
import org.ccnx.ccn.impl.security.keys.BasicKeyManager;
import org.ccnx.ccn.impl.security.keys.SecureKeyCache;
import org.ccnx.ccn.protocol.CCNTime;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.PublisherPublicKeyDigest;

/**
 *
 * @author Derek Kulinski
 */
public class EncryptionHelper {
	public static KeyPair generateKeys()
	{
		KeyPairGenerator kpg;
		KeyPair key_pair;

		try {
			kpg = KeyPairGenerator.getInstance(UserConfiguration.defaultKeyAlgorithm());
			key_pair = kpg.generateKeyPair();
		}
		catch (NoSuchAlgorithmException ex) {
			throw new Error("Unable to obtain a key generator", ex);
		}

		return key_pair;
	}

	public static X509Certificate generateSSCert(KeyPair key_pair,
					ContentName name)
	{
		try {
			return MinimalCertificateGenerator.GenerateUserCertificate(key_pair,
							"CN=" + name.toString(),
							MinimalCertificateGenerator.MSEC_IN_YEAR);
		}
		catch (Exception ex) {
			throw new Error("Unable to generate certificate", ex);
		}
	}

	/**
	 * generates a new asymmetric keys
	 * @return digest of public key or null if problem saving the key
	 */
	public static PublisherPublicKeyDigest generatePublisherKeys()
	{
		final GlobalConfig config = GlobalConfig.getInstance();
		final CCNTime version = CCNTime.now();
		final KeyPair key_pair = generateKeys();
		KeyManager keymgr;
		
		keymgr = config.getKeyManager();
		assert keymgr != null;

		keymgr.getSecureKeyCache().addMyPrivateKey(SecureKeyCache.getKeyIdentifier(
						key_pair.getPublic()), key_pair.getPrivate());

		try {
			//Let's hope this will save everything needed
			keymgr.saveSecureKeyCache();
		}
		catch (IOException ex) {
			Log.error("Error while writing data to the keystore: " + ex.getLocalizedMessage());
			return null;
		}

		keymgr.getPublicKeyCache().remember(key_pair.getPublic(), version);

		return new PublisherPublicKeyDigest(key_pair.getPublic());
	}
}
