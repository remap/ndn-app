/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc.util;

import javax.crypto.SecretKey;
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author takeda
 */
public class EncryptionHelperTest {
	public EncryptionHelperTest()
	{
	}

	@BeforeClass
	public static void setUpClass()
			throws Exception
	{
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

//	/**
//	 * Test of generateSymKey method, of class EncryptionHelper.
//	 */
//	@Test
//	public void testGenerateSymKey()
//			throws Exception
//	{
//		System.out.println("generateSymKey");
//		SecretKey expResult = null;
//		SecretKey result = EncryptionHelper.generateSymKey();
//		assertEquals(expResult, result);
//		// TODO review the generated test code and remove the default call to fail.
//		fail("The test case is a prototype.");
//	}

	/**
	 * Test of encryptSymData method, of class EncryptionHelper.
	 */
	@Test
	public void testEncryptSymData()
			throws Exception
	{
		SecretKey key;
		byte[] data, ciphertext, result;
		System.out.println("encryptSymData");

		key = EncryptionHelper.generateSymKey();
		data = "Kra kre mija, lis ma nore a ja nos tre".getBytes();

		ciphertext = EncryptionHelper.encryptSymData(key, data);
		result = EncryptionHelper.decryptSymData(key, ciphertext);

		assertArrayEquals(data, result);
	}

//	/**
//	 * Test of decryptSymData method, of class EncryptionHelper.
//	 */
//	@Test
//	public void testDecryptSymData()
//			throws Exception
//	{
//		System.out.println("decryptSymData");
//		SecretKey key = null;
//		byte[] input = null;
//		byte[] expResult = null;
//		byte[] result = EncryptionHelper.decryptSymData(key, input);
//		assertEquals(expResult, result);
//		// TODO review the generated test code and remove the default call to fail.
//		fail("The test case is a prototype.");
//	}
//
//	/**
//	 * Test of wrapKey method, of class EncryptionHelper.
//	 */
//	@Test
//	public void testWrapKey()
//			throws Exception
//	{
//		System.out.println("wrapKey");
//		PublicKey public_key = null;
//		SecretKey secret_key = null;
//		byte[] expResult = null;
//		byte[] result = EncryptionHelper.wrapKey(public_key, secret_key);
//		assertEquals(expResult, result);
//		// TODO review the generated test code and remove the default call to fail.
//		fail("The test case is a prototype.");
//	}
//
//	/**
//	 * Test of unwrapKey method, of class EncryptionHelper.
//	 */
//	@Test
//	public void testUnwrapKey()
//			throws Exception
//	{
//		System.out.println("unwrapKey");
//		PrivateKey private_key = null;
//		byte[] wrapped_key = null;
//		SecretKey expResult = null;
//		SecretKey result = EncryptionHelper.unwrapKey(private_key, wrapped_key);
//		assertEquals(expResult, result);
//		// TODO review the generated test code and remove the default call to fail.
//		fail("The test case is a prototype.");
//	}
//
//	/**
//	 * Test of encryptAsymData method, of class EncryptionHelper.
//	 */
//	@Test
//	public void testEncryptAsymData()
//			throws Exception
//	{
//		System.out.println("encryptAsymData");
//		PublicKey public_key = null;
//		byte[] data = null;
//		byte[] expResult = null;
//		byte[] result = EncryptionHelper.encryptAsymData(public_key, data);
//		assertEquals(expResult, result);
//		// TODO review the generated test code and remove the default call to fail.
//		fail("The test case is a prototype.");
//	}
//
//	/**
//	 * Test of decryptAsymData method, of class EncryptionHelper.
//	 */
//	@Test
//	public void testDecryptAsymData()
//			throws Exception
//	{
//		System.out.println("decryptAsymData");
//		PrivateKey private_key = null;
//		byte[] cipherText = null;
//		byte[] expResult = null;
//		byte[] result = EncryptionHelper.decryptAsymData(private_key, cipherText);
//		assertEquals(expResult, result);
//		// TODO review the generated test code and remove the default call to fail.
//		fail("The test case is a prototype.");
//	}
}
