/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.transducer.client;

import edu.ucla.cens.pdc.libpdc.datastructures.DataRecord;

/**
 * Null transducer
 * @author Derek Kulinski
 */
public class NOOPTransducer implements iTransducerClient {
	@Override
	public StreamInfo[] getInputStreamList()
	{
		final StreamInfo[] ret = {
			new StreamInfo("input", 1),
		};

		return ret;
	}

	@Override
	public StreamInfo[] getOutputStreamList()
	{
		final StreamInfo[] ret = {
			new StreamInfo("output", 1),
		};

		return ret;
	}

	@Override
	public DataRecord[][] processData(DataRecord[][] input)
	{
		return input;
	}
}
