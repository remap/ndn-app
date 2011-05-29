package edu.ucla.cens.pdc.transducer.loader;

import java.lang.reflect.*;
import edu.ucla.cens.pdc.transducer.loader.TransducerLoader;
import edu.ucla.cens.pdc.transducer.secman.TransducerSecMan;

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
		Class argList[] = new Class[] {String[].class};

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

	static Object[] getArgs(String args[]) 
	{  
 		return new Object[] {new String[]{"abc"}};
	} 

	public static void main(String args[]) throws ClassNotFoundException { 

		//Class self = Class.forName("JavaRunner");

		System.setSecurityManager(new TransducerSecMan()); 
		System.out.println("After Security Manager is set");
		//Parse the XMl
		//Loop till all the nodes are traversed do below thing
		{
		//you would have to figure out how to send the Datarecord object's here DERek ca help...i assume you create a ArrayList of "in" Datarecords and another arrayList of "out" Datarecords, get the data	into the "in" datarecord that you want to pass to the transducer....make a map so that you can keep track of what Datarecords array you have passed to each of the transducer....use similar map for out datarecords...basically keep track of what you are passing...the t.join thing will wait for the threads to finsh and then you can loop to the next level of the nodes


		TransducerLoader jrl = new TransducerLoader("file:/home/gauresh/spring2011/cs219estrin/project/ndn-app/transducers/gauresh/classloader/testclasses/"); 
		ThreadGroup tg = new ThreadGroup("JavaRunner Threadgroup"); 
		Thread t = new Thread(tg, new JavaRunner(jrl, "edu.ucla.cens.pdc.transducer.test.Test", getArgs(args))); 
		t.start(); 
		try { t.join(); } 
		catch (InterruptedException ie) 
		{ System.out.println("Thread was interrupted"); 
	}
} 
} 
}
