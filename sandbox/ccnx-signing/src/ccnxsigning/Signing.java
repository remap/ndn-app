/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ccnxsigning;

import java.io.IOException;
import java.security.InvalidKeyException;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.KeyStore;
import java.security.NoSuchAlgorithmException;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.security.SignatureException;
import java.security.cert.CertificateEncodingException;
import java.security.cert.X509Certificate;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.crypto.SecretKey;
import org.ccnx.ccn.CCNFilterListener;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.CCNInterestListener;
import org.ccnx.ccn.KeyManager;
import org.ccnx.ccn.config.ConfigurationException;
import org.ccnx.ccn.impl.security.crypto.ContentKeys;
import org.ccnx.ccn.impl.security.crypto.util.MinimalCertificateGenerator;
import org.ccnx.ccn.impl.security.keys.BasicKeyManager;
import org.ccnx.ccn.impl.security.keys.RepositoryKeyManager;
import org.ccnx.ccn.io.CCNOutputStream;
import org.ccnx.ccn.io.CCNVersionedOutputStream;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.ContentObject;
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.protocol.KeyLocator;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import org.ccnx.ccn.protocol.PublisherPublicKeyDigest;
import org.ccnx.ccn.protocol.SignedInfo;
import org.ccnx.ccn.utils.CreateUserData;

/**
 *
 * @author Derek Kulinski
 */
class Signing implements CCNFilterListener {
	final ContentName root;

	final CCNHandle ccn_handle = CCNHandle.getHandle();

//	KeyPair keys;
	PublicKey pub_key;
	PrivateKey priv_key;
//
//	X509Certificate cert;

	PublisherPublicKeyDigest digest;
	KeyManager keymgr;

	ContentName keystorename, keyname;

	KeyStore ks;

	public Signing(String root)
					throws MalformedContentNameStringException
	{
		this.root = ContentName.fromURI(root);
		this.keystorename = ContentName.fromURI("ccnx:/keys");
		this.keyname = keystorename.append("mykey");
	}

	public void setupKeys()
					throws ConfigurationException, IOException, InvalidKeyException
	{
		keymgr = new BasicKeyManager("tescik", "~/test_keystore", null, null, null,
						null, null);

		keymgr.initialize();

		digest = keymgr.getDefaultKeyID();

		keymgr.publishKeyToRepository(keyname, null);

		priv_key = keymgr.getSigningKey(digest);

//		try {
//			KeyPairGenerator kpg = KeyPairGenerator.getInstance("RSA");
//			log("Generating keys ...");
//			kpg.initialize(512);
//			keys = kpg.generateKeyPair();
//
//			log("Generating certificate ...");
//			cert = MinimalCertificateGenerator.GenerateUserCertificate(keys,
//							"CN=mykey", MinimalCertificateGenerator.MSEC_IN_YEAR);
//
//			log("Setting up key manager ...");
//			digest = new PublisherPublicKeyDigest(keys.getPublic());
//
//			KeyLocator locator = new KeyLocator(keys.getPublic());
//
//			keymgr = new RepositoryKeyManager(null, keystorename, digest,
//							"haslo".toCharArray(), ccn_handle);
//			keymgr.initialize();
//			keymgr.publishKey(keyname, keys.getPublic(), digest, locator, true);
//			keymgr.saveSecureKeyCache();
//
////			keymgr.publishKey(keyname, digest, digest, locator);
////			keymgr.publishSelfSignedKey(keyname, digest, true);
//		}
//		catch (ConfigurationException ex) {
//			Logger.getLogger(Signing.class.getName()).log(Level.SEVERE, null, ex);
//		}
//		catch (IOException ex) {
//			Logger.getLogger(Signing.class.getName()).log(Level.SEVERE, null, ex);
//		}
//		catch (CertificateEncodingException ex) {
//			Logger.getLogger(Signing.class.getName()).log(Level.SEVERE, null, ex);
//		}
//		catch (InvalidKeyException ex) {
//			Logger.getLogger(Signing.class.getName()).log(Level.SEVERE, null, ex);
//		}
//		catch (IllegalStateException ex) {
//			Logger.getLogger(Signing.class.getName()).log(Level.SEVERE, null, ex);
//		}
//		catch (SignatureException ex) {
//			Logger.getLogger(Signing.class.getName()).log(Level.SEVERE, null, ex);
//		}
//		catch (NoSuchAlgorithmException ex) {
//			Logger.getLogger(Signing.class.getName()).log(Level.SEVERE, null, ex);
//		}
	}

	public void startListening()
					throws IOException
	{
		ccn_handle.registerFilter(root, this);
	}

	public boolean handleInterest(Interest interest)
	{
		String text = "Hello!\n";
		ccn_handle.setKeyManager(keymgr);

//		KeyLocator locator = keymgr.getDefaultKeyLocator();

		KeyLocator locator = new KeyLocator(keyname, digest);

		SignedInfo si = new SignedInfo(digest, SignedInfo.ContentType.DATA, locator,
						1, null);

		log(si);

		ContentObject co;
		try {
			co = new ContentObject(interest.name(), si, text.getBytes(),
							priv_key);
			ccn_handle.put(co);
			return true;
		}
		catch (IOException ex) {
			Logger.getLogger(Signing.class.getName()).log(Level.SEVERE, null, ex);
		}
		catch (InvalidKeyException ex) {
			Logger.getLogger(Signing.class.getName()).log(Level.SEVERE, null, ex);
		}
		catch (SignatureException ex) {
			Logger.getLogger(Signing.class.getName()).log(Level.SEVERE, null, ex);
		}

//		CCNOutputStream os = null;
//		try {
////			os = new CCNVersionedOutputStream(root, digest, ccn_handle);
//			os = new CCNVersionedOutputStream(root, locator, digest, null,
//							ccn_handle);
//			os.addOutstandingInterest(interest);
//			os.setFreshnessSeconds(1);
//			os.write(text.getBytes(), 0, text.getBytes().length);
//			os.close();
//			return true;
//		}
//		catch (IOException ex) {
//			Logger.getLogger(Signing.class.getName()).log(Level.SEVERE, null, ex);
//		}
//		finally {
//			try {
//				os.close();
//			}
//			catch (IOException ex) {
//				Logger.getLogger(Signing.class.getName()).log(Level.SEVERE, null, ex);
//			}
//		}
		return false;
	}

	private void log(Object o)
	{
		System.out.println(o);
	}
}
