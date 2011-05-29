package edu.ucla.cens.pdc.transducer.clientStub;

import edu.ucla.cens.pdc.transducer.clientInterface.iTransducerClient;
import java.rmi.*;
import java.rmi.registry.*;
//import edu.ucla.cens.pdc.transducer.server.*;
/*
 * 
 * @author gauresh
 */
public class TransducerClientStub {
    public static void callServer(){
        if (System.getSecurityManager() == null) {
            System.setSecurityManager(new SecurityManager());
        }
        try {
            String name = "iTransducerClient";
            Registry registry = LocateRegistry.getRegistry("localhost");
            iTransducerClient comp = (iTransducerClient) registry.lookup(name);
            System.out.println(comp.helloWorld());
            
        } catch (Exception e) {
            System.err.println("TransducerClient exception:");
            e.printStackTrace();
        }
    }
}
