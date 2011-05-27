package edu.ucla.cens.pdc.transducer.client;

import edu.ucla.cens.pdc.transducer.clientStub.TransducerClientStub;
import java.io.*;
/*
*
*@author gauresh
*/

public class TransducerClient {

 public static void main(String args[]) {
	
	TransducerClientStub.callServer();
	//File file = new File("Gauresh.txt");
	try {
		FileWriter outFile = new FileWriter("Gauresh.txt");
		PrintWriter out = new PrintWriter(outFile);
		out.println("This is line 1");
		out.println("This is line 2");
		out.close();
	} catch( IOException e) {
  		e.printStackTrace();
	}
	System.out.println("Secured");	

 }

}
