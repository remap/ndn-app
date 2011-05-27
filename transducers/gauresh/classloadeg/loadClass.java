protected Class loadClass(String name, boolean resolve) 
{ 	
	Class c; 
	SecurityManager sm = System.getSecurityManager(); 
	// Step 1 -- Check for a previously loaded 
	class c = findLoadedClass(name); 
	if (c != null) 
		return c; 
	// Step 2 -- Check to make sure that we can access this class 
	if (sm != null) 
	{ 
		int i = name.lastIndexOf('.'); 
		if (i >= 0) 
			sm.checkPackageAccess(name.substring(0, i)); 
	} 
	// Step 3 -- Check for system class first 
	try { 
	// In 1.2 only, defer to another class loader if available 
		if (parent != null) 
			c = parent.loadClass(name, resolve); 
		else 
		// Call this method in both 1.1 and 1.2 
			c = findSystemClass(name); 
		if (c != null) 
			return c; 
	} catch (ClassNotFoundException cnfe) { 
		// Not a system class, simply continue 
	}
	// Step 4 -- Check to make sure that we can define this class 
	if (sm != null) { 
		int i = name.lastIndexOf('.'); 
		if (i >= 0) 
			sm.checkPackageDefinition(name.substring(0, i)); 
	} 
	// Step 5 -- Read in the class 
	file byte data[] = lookupData(name); 
	// Step 6 and 7 -- Define the class from the data; this also 
	//passes the data through the bytecode verifier 
	c = defineClass(name, data, 0, data.length); 
	// Step 8 -- Resolve the internal references of the class 
	if (resolve) 
		resolveClass(c); 
	return c; 
}
