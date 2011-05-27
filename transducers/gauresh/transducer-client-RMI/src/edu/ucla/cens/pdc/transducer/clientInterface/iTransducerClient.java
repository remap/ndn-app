/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.transducer.clientInterface;
import edu.ucla.cens.pdc.libpdc.datastructures.DataRecord;
import java.rmi.*;
import java.rmi.Remote;
import java.rmi.RemoteException;


/**
 *
 * @author gauresh
 */
public interface iTransducerClient extends Remote{
        StreamInfo[] getInputStreamList() throws RemoteException;

	StreamInfo[] getOutputStreamList() throws RemoteException;

	//first dimension is record entry
	//second dimension is stream number
	DataRecord[][] processData(DataRecord[][] input) throws RemoteException;

	String helloWorld() throws RemoteException;
}
