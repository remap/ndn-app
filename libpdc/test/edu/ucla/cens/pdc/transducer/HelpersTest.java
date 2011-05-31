/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.transducer;

import edu.ucla.cens.pdc.libpdc.datastructures.DataRecord;
import edu.ucla.cens.pdc.transducer.Helpers;
import edu.ucla.cens.pdc.transducer.TransducerMsg.Message;
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
public class HelpersTest {
	/**
	 * Test of serializeData and deserializeData methods, of class Helpers.
	 */
	@Test
	public void testSerializeData()
			throws Exception
	{
		System.out.println("serializeData");

		DataRecord[][] input = new DataRecord[2][2];
		for (int i = 0; i < input.length; i++)
			for (int j = 0; j < input[i].length; j++)
				input[i][j] = new DataRecord();

		input[0][0].put("zero", "0");
		input[0][1].put("one", "1");
		input[1][0].put("two", "2");
		input[1][1].put("three", "3");

		final Message encoded = Helpers.serializeData(input);
		final DataRecord[][] decoded = Helpers.deserializeData(encoded);

		for (int i = 0; i < input.length; i++)
			for (int j = 0; j < input[i].length; j++) {
				System.out.println("Testing " + i + ", " + j);
				assertEquals(decoded[i][j].toMap(), input[i][j].toMap());
			}
	}
}
