package edu.ucla.cens.pdc.transducer.secman;
import java.io.*;	

class test{

	public static void main(String args[]) {
		SecurityManager sm = new TransducerSecMan();
		System.setSecurityManager(sm);
		try{
		FileWriter out = new FileWriter("Gauresh.txt");
		}catch(IOException e){
		}
	}

}
