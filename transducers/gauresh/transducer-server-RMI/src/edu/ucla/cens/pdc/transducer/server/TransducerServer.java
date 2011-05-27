/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.transducer.server;

import edu.ucla.cens.pdc.libpdc.datastructures.DataRecord;
import java.rmi.registry.*;
import java.rmi.server.UnicastRemoteObject;
import java.rmi.*;

import edu.ucla.cens.pdc.transducer.clientInterface.iTransducerClient;
/**
 *
 * @author gauresh
 */
public class TransducerServer implements iTransducerClient{
    
    public TransducerServer(){
        super();
    }
    @Override	
    public StreamInfo[] getInputStreamList() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override	 
    public StreamInfo[] getOutputStreamList() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public DataRecord[][] processData(DataRecord[][] input) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public String helloWorld() {
        return "Hello World !!";
    }
    

    public static void main(String args[]) {
         if (System.getSecurityManager() == null) {
            System.setSecurityManager(new RMISecurityManager());
        }
         try {
            String name = "iTransducerClient";
            iTransducerClient engine = new TransducerServer();
            iTransducerClient stub = (iTransducerClient) UnicastRemoteObject.exportObject(engine, 30000);
               
            Registry registry = LocateRegistry.getRegistry();
            registry.rebind(name, stub);
            System.out.println("ComputeEngine bound");
        } catch (Exception e) {
            System.err.println("ComputeEngine exception:");
            e.printStackTrace();
        }
    }
}

class RMISecurityManager extends SecurityManager {
   
    
    @Override
    public void checkConnect(String host, int port) {
        if(!host.contentEquals("localhost"))
             System.out.println("What are you doing?");
        if(port != 30000 || port != 1099)
               System.out.println("Accessing wrong port");  
    }
}