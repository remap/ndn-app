/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.transducer.client;

import edu.ucla.cens.pdc.libpdc.datastructures.DataRecord;

/**
 *
 * @author Derek Kulinski
 */
public interface iTransducerClient {
	StreamInfo[] getInputStreamList();

	StreamInfo[] getOutputStreamList();

	//first dimension is record entry
	//second dimension is stream number
	DataRecord[][] processData(DataRecord[][] input);
}
