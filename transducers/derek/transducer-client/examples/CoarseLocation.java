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
public class CoarseLocation implements iTransducerClient {
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
		long t_lat, t_long;
		final DataRecord record = input[0][0];

		double latitude = (Double) record.get(_lat_field);
		double longitude = (Double) record.get(_long_field);

		latitude *= _lat_mult;
		longitude *= _long_mult;

		t_lat = Math.round(latitude);
		t_long = Math.round(longitude);

		latitude = t_lat / _lat_mult;
		longitude = t_long / _long_mult;

		record.put(_lat_field, latitude);
		record.put(_long_field, longitude);

		return input;
	}

	private String _lat_field = "latitude";

	private String _long_field = "longitude";

	private int _lat_mult;

	private int _long_mult;
}
