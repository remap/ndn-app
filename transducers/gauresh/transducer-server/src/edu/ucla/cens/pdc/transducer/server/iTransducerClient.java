package edu.ucla.cens.pdc.transducer.server;

import edu.ucla.cens.pdc.libpdc.datastructures.DataRecord;
import java.rmi.*;
/**
*
* @author Gauresh Rane
*/
public interface iTransducerClient {
	/*StreamInfo[] getInputStreamList() throws RemoteException;

	StreamInfo[] getOutputStreamList() throws RemoteException;

	//first dimension is record entry
	//second dimension is stream number
	DataRecord[][] processData(DataRecord[][] input);*/

	String getData();

}
