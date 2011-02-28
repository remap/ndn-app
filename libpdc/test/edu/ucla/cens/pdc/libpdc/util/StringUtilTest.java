/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc.util;

import java.util.LinkedList;
import java.util.Collection;
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
public class StringUtilTest {
	/**
	 * Test of join method, of class StringUtil.
	 */
	@Test
	public void testJoin()
	{
		System.out.println("join");
		Collection<String> list = null;
		String delimiter = "";
		String expResult = "";
		String result = StringUtil.join(list, delimiter);
		assertEquals(expResult, result);

		list = new LinkedList();
		delimiter = ",";
		expResult = "";
		result = StringUtil.join(list, delimiter);
		assertEquals(expResult, result);

		list.add("one");
		delimiter = ",";
		expResult = "one";
		result = StringUtil.join(list, delimiter);
		assertEquals(expResult, result);

		list.add("two");
		list.add("three");
		delimiter = ", ";
		expResult = "one, two, three";
		result = StringUtil.join(list, delimiter);
		assertEquals(expResult, result);
	}

	/**
	 * Test of stripPrefixChar method, of class StringUtil.
	 */
	@Test
	public void testStripPrefixChar()
	{
		System.out.println("stripPrefixChar");
		String s = "////test////";
		String prefix = "/";
		String expResult = "///test////";
		String result = StringUtil.stripPrefixChar(s, prefix);
		assertEquals(expResult, result);

		s = "test////";
		prefix = "/";
		expResult = "test////";
		result = StringUtil.stripPrefixChar(s, prefix);
		assertEquals(expResult, result);
	}
}
