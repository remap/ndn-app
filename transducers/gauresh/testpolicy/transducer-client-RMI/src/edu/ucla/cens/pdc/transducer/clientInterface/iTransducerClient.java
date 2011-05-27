/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.transducer.clientInterface;
import edu.ucla.cens.pdc.libpdc.datastructures.DataRecord;
import edu.ucla.cens.pdc.transducer.server.StreamInfo;
//import java.rmi.*;
//import java.rmi.Remote;
//import java.rmi.RemoteException;


/**
 *
 * @author gauresh
 */
public interface iTransducerClient {
        StreamInfo[] getInputStreamList();

	StreamInfo[] getOutputStreamList();

	//first dimension is record entry
	//second dimension is stream number
	DataRecord[][] processData(DataRecord[][] input);

	String helloWorld();
}
