/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc.util;

import org.ccnx.ccn.impl.support.DataUtils;
import org.ccnx.ccn.protocol.ContentName;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author takeda
 */
public class SignedInterestTest {
	@Test
	public void testEncryption()
			throws Exception
	{
		byte[] text, ciphertext, output;
		String ciphertext2;

		System.out.println("encryption");
		text = "ala ma kota a kot ma wpierdol".getBytes();
		SignedInterest instance = new SignedInterest();

		ciphertext = instance.encrypt(text);
		output = instance.decrypt(ciphertext);

		assertArrayEquals(text, output);
		
		ciphertext2 = new String(DataUtils.base64Encode(instance.encrypt(text)));
		output = instance.decrypt(DataUtils.base64Decode(ciphertext2.getBytes()));
		
		assertArrayEquals(text, output);
	}

	/**
	 * Test of signing and veifying interests.
	 */
	@Test
	public void testSignName()
			throws Exception
	{
		ContentName signed_name, unsigned_name;

		System.out.println("signed interest");

		SignedInterest instance = new SignedInterest();

		final ContentName name = ContentName.fromNative(
				"/ucla.edu/apps/pdv1/manage/myapp/list");
		final ContentName name1 = name.subname(0, 4);
		final ContentName name2 = name.postfix(name1);

		signed_name = ContentName.fromNative(name1, instance.signName(name2));
		signed_name = signed_name.postfix(name1);
		unsigned_name = instance.verifyName(signed_name.lastComponent());

		assertNotNull("Name verification failed", unsigned_name);

		unsigned_name = name1.append(unsigned_name);
		assertTrue("Name doesn't match", name.equals(unsigned_name));
	}
}
