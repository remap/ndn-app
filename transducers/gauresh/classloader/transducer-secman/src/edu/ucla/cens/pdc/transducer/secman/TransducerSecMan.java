package edu.ucla.cens.pdc.transducer.secman;

import java.security.*;
import java.net.URL;

public class TransducerSecMan extends SecurityManager{

	public TransducerSecMan() {
		super();
		System.out.println("Helloz");
	}

	public void checkPackageAccess(String pkg){
		super.checkPackageAccess(pkg);
		//check the codesource or from protection domain get the code source...

		//Class[] currentClasses  = getClassContext();

//		for(Class c : getClassContext())
//			System.out.println("Class : " + c.getName()); 
		if(currentClassLoader() !=  null)
			System.out.println("Current Class Loader : " + currentClassLoader().toString());
		if(currentClassLoader() == null)
			System.out.println("asdasdadasd");
		/*ProtectionDomain pd = this.getClass().getProtectionDomain();
		
		URL urlBase = pd.getCodeSource().getLocation();
		//if the codesource is not one of transducer server then check what package is in question
		System.out.println("Came Here" + urlBase.getPath() + "Name of class:" + this.getClass().getName() + "Classloader" + this.getClass().getClassLoader().toString());
	
		if(urlBase.getPath().compareTo("/home/gauresh/spring2011/cs219estrin/project/ndn-app/transducers/gauresh/classloader/transducer-secman/src/") == 0){
			System.out.println("Entered :" + pkg);
			if(pkg.compareTo("java.lang") != 0 && this.getClass().getName().compareTo("edu.ucla.cens.pdc.transducer.secman.TransducerSecMan") != 0)
				throw new SecurityException("Accessing packages other than java.lang not allowed");
		}
		
		System.out.println("Came out");*/
		//if anything other than java.lang throw security exception
	
		//else return ok	
	}
}
