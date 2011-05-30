package edu.ucla.cens.pdc.transducer.loader;

import java.lang.reflect.*;
import edu.ucla.cens.pdc.transducer.loader.TransducerLoader;
import edu.ucla.cens.pdc.transducer.secman.TransducerSecMan;
import edu.ucla.cens.pdc.transducer.datastructures.StreamData;
import edu.ucla.cens.pdc.*;
import org.ccnx.ccn.config.ConfigurationException;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCDatabaseException;
import java.security.InvalidKeyException;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCTransmissionException;
import org.xmlpull.v1.XmlPullParserException;
import edu.ucla.cens.pdc.xmlparser.*;
import java.util.*;
import java.io.FileNotFoundException;

public class JavaRunner implements Runnable { 
	
	final static int numArgs = 2; 
	ClassLoader cl; 
	String className; 
	Object args[]; 

	JavaRunner(ClassLoader cl, String className, Object args[]) 
	{ 
		this.cl = cl; this.className = className; this.args = args; 
	} 
	
	void invokeInit(Class clazz) 
	{ 
		//Here you invoke create the init method of transducer which will be a static method
		Class argList[] = new Class[] {StreamData[].class};

		Method mainMethod = null;
		try {
			/*for(Method var : clazz.getMethods()){
				System.out.println(var.getName()); 
				if(var.getName().equals("main"))
					argList = var.getParameterTypes();
			}*/
			mainMethod = clazz.getMethod("main",argList);
			System.out.println("Got the method" + argList.length);
		}catch(NoSuchMethodException nsme){
			System.out.println("No such method exists");
		}
                try{
			mainMethod.invoke(null,args);
		}catch (Exception e) { 

			Throwable t; 
			if (e instanceof InvocationTargetException) 
				t = ((InvocationTargetException) e) .getTargetException(); 
			else 
				t = e; System.out.println("Procedure exited with exception " + t); 
				t.printStackTrace(); 
			} 
	} 

	public void run() 
	{ 

		Class target = null; 
		try { 
			target = cl.loadClass(className); 
			invokeInit(target); 
		} catch (ClassNotFoundException cnfe){ 
			System.out.println("Can't load " + className); 
		}	 

	} 

	static Object[] getArgs(TransducerConfig transducer,String AppId) 
	{  
 		StreamData[] args = new StreamData[transducer.inputStreamsize()];
		for(int i = 0;i < transducer.inputStreamsize();i++)
			args[i] = StreamData.getStream(AppId,transducer.getInputStreamName(i));
		
		return new Object[] {args};
		//return new Object[] {new String[]{"abc"}};
	} 

	public static void main(String args[]) throws ClassNotFoundException,org.ccnx.ccn.protocol.MalformedContentNameStringException,java.io.IOException,
			ConfigurationException, PDCTransmissionException, PDCDatabaseException, InvalidKeyException 
	{ 
		System.out.println("I reached here");

		//Setting up Global Instance of PDV
		System.out.println(Main.main(new String[]{"database"}));

		//Setting Up Security Manager
		System.setSecurityManager(new TransducerSecMan()); 
		System.out.println("After Security Manager is set");

		//Instantiating XML Parser
		XMLParser parser = new	XMLParser();

		System.out.println("Argument length: " + args.length);
	
		//Running multiple configurations

		for(int i = 0; i < args.length; i ++) {

			try{
				//Parse the XMl
				String configFile = args[i];
				System.out.println(args[i]);

				parser.setFileName(configFile);

				//parse the configuration file
				Configuration config = parser.parse();

				//get TransducerList
				ArrayList<TransducerConfig> transducerList = (ArrayList<TransducerConfig>) config.getTransducerConfigList(); 
			
				//Creating a ThreadGroup
				ThreadGroup tg = new ThreadGroup("Transducer AppID : " + config.getAppId() + " threadgroup");

				for(TransducerConfig transducer: transducerList) {

					TransducerLoader jrl = new TransducerLoader(transducer.getCodeSource()); 
					Thread t = new Thread(tg, new JavaRunner(jrl, transducer.getTransducerId(), getArgs(transducer,config.getAppId()))); 

					//Starting The Thread
					t.start(); 
					try { 
						t.join(); 
					} catch (InterruptedException ie) { 
						System.out.println("Thread was interrupted"); 
					}
				}

				System.out.println(config.getAppId());
				System.out.println(transducerList.get(0).getTransducerId());
				System.out.println(transducerList.get(0).inputStreamsize());

			} catch (XmlPullParserException e) {
        	                e.printStackTrace();
                	} catch (FileNotFoundException e) {
                        	// TODO Auto-generated catch block
	                        e.printStackTrace();
                	}
		}
		System.out.println("Completed Execution");
	} 
}
