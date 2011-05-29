package edu.ucla.cens.pdc.transducer.client;

import edu.ucla.cens.pdc.transducer.clientStub.TransducerClientStub;
/*
*
*@author gauresh
*/

public class TransducerClient {

 public static void main(String args[]) {
	
	TransducerClientStub.callServer();
	System.out.println("Secured");	

 }

}
