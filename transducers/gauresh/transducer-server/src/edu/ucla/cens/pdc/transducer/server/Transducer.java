package edu.ucla.cens.pdc.transducer.server;
import java.rmi.*;
import java.rmi.registry.*;
import java.rmi.server.*;
import edu.cens.pdc.transducer.server.iTransducerClient;

public class Transducer implements iTransducerClient{
	
	public Transducer() {
		super();
	}

	/*public StreamInfo[] getInputStreamList() {
	
	}

	public StreamInfo[] getOuputStreamList() {
	
	}

	public DataRecord[][] processData(DataRecord[][] input) {

	}*/
	
	public String getData() {

		return "Hello World !!";
	}
	
	public static void main(String args[]){
		if(System.getSecurityManager() == null)
			System.setSecurityManager(new SecurityManager());

		try {
			String = "iTransducerClient";
			iTransducerClient engine = new Transducer();
			iTransducerClient stub = (iTransducerClient) UnicastRemoteObject.exportObject(engine,0);
			Registry registry = LocateRegistry.getRegistry();
			registry.rebind(name,stub);
			


		} catch(Exception e) {
			System.err.println("Eroor");
		}
		
	}	
}
