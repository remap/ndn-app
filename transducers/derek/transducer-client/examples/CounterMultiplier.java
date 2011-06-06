/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.transducer.client;

import edu.ucla.cens.pdc.libpdc.datastructures.DataRecord;
import java.io.File;

/**
 * Null transducer
 * @author Derek Kulinski
 */
public class CounterMultiplier implements iTransducerClient {
	@Override
	public void configure(String[] args)
	{
	}

	@Override
	public StreamInfo[] getInputStreamList()
	{
		final StreamInfo[] ret = {new StreamInfo("input", 1)};

		return ret;
	}

	@Override
	public StreamInfo[] getOutputStreamList()
	{
		final StreamInfo[] ret = {new StreamInfo("output", 1)};

		return ret;
	}

	@Override
	public DataRecord[][] processData(DataRecord[][] input)
	{
		final DataRecord record = input[0][0];
		final int counter = (Integer) record.get(_counter_field);

		if (counter == 5) {
			final File file = new File("testfile.txt");
			try {
				file.createNewFile();
			}
			catch (Exception ex) {
				System.err.println("Got an exception: " + ex);
			}
		}

		record.put(_counter_field, counter * _multiplier);

		return input;
	}

	private final String _counter_field = "counter";

	private final int _multiplier = 2;
}
