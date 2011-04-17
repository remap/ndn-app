/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc.core;

import edu.ucla.cens.pdc.libpdc.util.Log;
import java.io.IOException;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.NoSuchAlgorithmException;
import java.security.cert.X509Certificate;
import org.ccnx.ccn.config.ConfigurationException;
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
public class PDCKeyManager extends BasicKeyManager {
	public PDCKeyManager(String name)
					throws ConfigurationException, IOException
	{
		super(null, "pdv_keys", name.concat(".conf"), name.concat(".key"), null,
						null, null);
	}

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
	public PublisherPublicKeyDigest generatePublisherKeys()
	{
		final CCNTime version = CCNTime.now();
		final KeyPair key_pair = generateKeys();

		getSecureKeyCache().addMyPrivateKey(SecureKeyCache.getKeyIdentifier(key_pair.
						getPublic()), key_pair.getPrivate());

		try {
			//Let's hope this will save everything needed
			saveSecureKeyCache();
		}
		catch (IOException ex) {
			Log.error("Error while writing data to the keystore: " + ex.
							getLocalizedMessage());
			return null;
		}

		getPublicKeyCache().remember(key_pair.getPublic(), version);

		return new PublisherPublicKeyDigest(key_pair.getPublic());
	}
}
