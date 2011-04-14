/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc;

import edu.ucla.cens.pdc.libpdc.stream.DataEncryptor;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCDatabaseException;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.URI;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.ccnx.ccn.KeyManager;
import com.mongodb.BasicDBObject;
import com.mongodb.DBObject;
import java.security.KeyPairGenerator;
import java.security.KeyPair;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import org.bouncycastle.util.encoders.Base64;
import org.bouncycastle.util.encoders.Hex;
import org.bson.BSONEncoder;
import org.ccnx.ccn.config.ConfigurationException;
import org.ccnx.ccn.config.UserConfiguration;
import org.ccnx.ccn.impl.security.keys.PublicKeyCache;
import org.ccnx.ccn.impl.security.keys.SecureKeyCache;
import org.ccnx.ccn.io.content.PublicKeyObject;
import org.ccnx.ccn.profiles.security.access.AccessControlManager;
import org.ccnx.ccn.protocol.CCNTime;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.KeyLocator;
import org.ccnx.ccn.protocol.PublisherPublicKeyDigest;
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Ignore;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author takeda
 */
public class DataEncryptorTest {
	private static DataEncryptor encryptor;

	static class TestKeyManager extends KeyManager {
		private KeyPair keypair;

		@Override
		public void close()
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public void initialize()
						throws InvalidKeyException, IOException, ConfigurationException
		{
			KeyPairGenerator kpg = null;
			try {
				kpg = KeyPairGenerator.getInstance(
								UserConfiguration.defaultKeyAlgorithm());
			}
			catch (NoSuchAlgorithmException ex) {
				Logger.getLogger(DataEncryptorTest.class.getName()).
								log(Level.SEVERE, null, ex);
			}

			kpg.initialize(UserConfiguration.defaultKeyLength());
			keypair = kpg.generateKeyPair();
		}

		@Override
		public boolean initialized()
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public void clearSavedConfigurationState()
						throws FileNotFoundException, IOException
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public PublisherPublicKeyDigest getDefaultKeyID()
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public PublicKeyCache getPublicKeyCache()
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public SecureKeyCache getSecureKeyCache()
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public void saveSecureKeyCache()
						throws FileNotFoundException, IOException
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public void saveConfigurationState()
						throws FileNotFoundException, IOException
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public URI getConfigurationDataURI()
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public PrivateKey getDefaultSigningKey()
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public PublicKey getDefaultPublicKey()
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public ContentName getDefaultKeyName(PublisherPublicKeyDigest keyID)
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public ContentName getDefaultKeyNamePrefix()
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public KeyLocator getKeyLocator(PublisherPublicKeyDigest publisherKeyID)
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public KeyLocator getKeyLocator(PrivateKey signingKey)
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public boolean haveStoredKeyLocator(PublisherPublicKeyDigest keyID)
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public KeyLocator getStoredKeyLocator(PublisherPublicKeyDigest keyID)
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public void clearStoredKeyLocator(PublisherPublicKeyDigest keyID)
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public void setKeyLocator(PublisherPublicKeyDigest publisherKeyID,
						KeyLocator keyLocator)
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public PublicKey getPublicKey(PublisherPublicKeyDigest publisher)
		{
			return keypair.getPublic();
		}

		@Override
		public PublisherPublicKeyDigest getPublisherKeyID(PrivateKey signingKey)
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public PrivateKey getSigningKey(PublisherPublicKeyDigest publisherKeyID)
		{
			return keypair.getPrivate();
		}

		@Override
		public PrivateKey[] getSigningKeys()
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public PublisherPublicKeyDigest[] getAvailableIdentities()
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public CCNTime getKeyVersion(PublisherPublicKeyDigest keyID)
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public PublicKey getPublicKey(PublisherPublicKeyDigest publisherKeyID,
						KeyLocator keyLocator, long timeout)
						throws IOException
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public PublicKeyObject getPublicKeyObject(
						PublisherPublicKeyDigest desiredKeyID,
						KeyLocator locator, long timeout)
						throws IOException
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public PublicKeyObject publishKey(ContentName keyName,
						PublicKey keyToPublish, PublisherPublicKeyDigest signingKeyID,
						KeyLocator signingKeyLocator, boolean learnKeyLocator)
						throws InvalidKeyException, IOException
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public PublicKeyObject publishKeyToRepository(ContentName keyName,
						PublisherPublicKeyDigest keyToPublish, long timeToWaitForPreexisting)
						throws InvalidKeyException, IOException
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public PublicKeyObject publishSelfSignedKeyToRepository(ContentName keyName,
						PublicKey theKey, PublisherPublicKeyDigest keyToPublish,
						long timeToWaitForPreexisting)
						throws InvalidKeyException, IOException
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public AccessControlManager getAccessControlManagerForName(
						ContentName contentName)
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		@Override
		public void rememberAccessControlManager(AccessControlManager acm)
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}
	}

	static class TestConfigStorage implements iConfigStorage {
		public ByteArrayInputStream loadEntry(String group, String name)
						throws IOException
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		public void saveEntry(String obj_group, String obj_key,
						ByteArrayOutputStream byte_out)
						throws IOException
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}

		public void removeEntry(String group, String name)
						throws IOException
		{
			throw new UnsupportedOperationException("Not supported yet.");
		}
	}

	public DataEncryptorTest()
	{
	}

	@BeforeClass
	public static void setUpClass()
					throws Exception
	{
		GlobalConfig config;
		KeyManager keymgr;

		keymgr = new TestKeyManager();
		keymgr.initialize();

		GlobalConfig.setConfigStorage(TestConfigStorage.class);
		config = GlobalConfig.getInstance();
		config.setKeyManager(keymgr);

		encryptor = new DataEncryptor();
	}

	@AfterClass
	public static void tearDownClass()
					throws Exception
	{
	}

	@Before
	public void setUp()
	{
	}

	@After
	public void tearDown()
	{
	}

	/**
	 * Test of encryptRecord method, of class DataEncryptor.
	 */
	@Ignore
	@Test
	public void testEncryptRecord()
					throws Exception
	{
		System.out.println("encryptRecord");
		iBSONExportable record = null;
		DataEncryptor instance = new DataEncryptor();
		byte[] expResult = null;
		byte[] result = instance.encryptRecord(record);
		assertEquals(expResult, result);
		// TODO review the generated test code and remove the default call to fail.
		fail("The test case is a prototype.");
	}

	/**
	 * Test of encryptData method, of class DataEncryptor.
	 */
	@Ignore
	@Test
	public void testEncryptData()
					throws Exception
	{
		System.out.println("encryptData");
		byte[] data = null;
		DataEncryptor instance = new DataEncryptor();
		byte[] expResult = null;
		byte[] result = instance.encryptData(data);
		assertEquals(expResult, result);
		// TODO review the generated test code and remove the default call to fail.
		fail("The test case is a prototype.");
	}

	/**
	 * Test of decryptRecord method, of class DataEncryptor.
	 */
	@Ignore
	@Test
	public void testDecryptRecord()
					throws Exception
	{
		System.out.println("decryptRecord");
		byte[] cipherText = null;
		DataEncryptor instance = new DataEncryptor();
		DataRecord expResult = null;
		DataRecord result = instance.decryptRecord(cipherText);
		assertEquals(expResult, result);
		// TODO review the generated test code and remove the default call to fail.
		fail("The test case is a prototype.");
	}

	/**
	 * Test of decryptData method, of class DataEncryptor.
	 */
	@Ignore
	@Test
	public void testDecryptData()
					throws Exception
	{
		System.out.println("decryptData");
		byte[] cipherText = null;
		DataEncryptor instance = new DataEncryptor();
		byte[] expResult = null;
		byte[] result = instance.decryptData(cipherText);
		assertEquals(expResult, result);
		// TODO review the generated test code and remove the default call to fail.
		fail("The test case is a prototype.");
	}

	@Test
	public void testKeyWrapping()
					throws Exception
	{
		GlobalConfig config = GlobalConfig.getInstance();
		KeyManager keymgr = config.getKeyManager();
		KeyGenerator kg;
		SecretKey sec_key;

		System.out.println("keyWrapping");

		kg = KeyGenerator.getInstance("AES");
		kg.init(128);
		sec_key = kg.generateKey();

		byte[] wrappedKey = encryptor.wrapKey(keymgr.getPublicKey(null), sec_key);
		SecretKey unwrappedKey = encryptor.unwrapKey(keymgr.getSigningKey(null), wrappedKey);

		assertTrue(unwrappedKey.equals(sec_key));
	}

	/**
	 * Test of decryptAsymData method, of class DataEncryptor.
	 */
	@Test
	public void testAsymData()
					throws Exception
	{
		System.out.println("decryptAsymData");

		GlobalConfig config = GlobalConfig.getInstance();
		BSONEncoder encoder = new BSONEncoder();
		KeyManager keymgr = config.getKeyManager();

		DBObject object = new BasicDBObject(1);
		object.put("enc_key", new byte[]{'t', 'e', 's', 't', 'k', 'e', 'y', 0});
		object.put("enc_key1", new byte[]{'t', 'e', 's', 't', 'k', 'e', 'y', 0});
		object.put("enc_key2", new byte[]{'t', 'e', 's', 't', 'k', 'e', 'y', 0});
		object.put("enc_key3", new byte[]{'t', 'e', 's', 't', 'k', 'e', 'y', 0});
		object.put("enc_key4", new byte[]{'t', 'e', 's', 't', 'k', 'e', 'y', 0});
		object.put("enc_key5", new byte[]{'t', 'e', 's', 't', 'k', 'e', 'y', 0});

		byte[] input = encoder.encode(object);
		byte[] expResult = input.clone();

		byte[] cipherText = encryptor.encryptAsymData(keymgr.getPublicKey(null),
						input);
		System.out.println(new String(Base64.encode(cipherText)));
		byte[] decrypted = encryptor.decryptAsymData(cipherText);

		assertArrayEquals(expResult, decrypted);
	}
}
