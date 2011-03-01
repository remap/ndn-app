/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc;

import java.util.HashMap;
import java.util.Map;
import org.ccnx.ccn.protocol.ContentName;

/**
 *
 * @author Derek Kulinski
 */
public class PDCConfigStore {
	private static PDCConfigStore _instance;

	private Map<String, Application> _applications;

	private ContentName _root = null;

	/**
	 * Constructor
	 */
	private PDCConfigStore()
	{
		_applications = new HashMap<String, Application>();
	}

	void setRoot(ContentName root)
	{
		if (_root != null)
			throw new UnsupportedOperationException("You can't change the root");

		_root = root;
	}

	ContentName getRoot()
	{
		assert _root != null : "Root wasn't set";

		return _root;
	}

	/**
	 * Add application to the config store
	 * @param app
	 */
	synchronized void addApplication(Application app)
	{
		assert _root != null : "Root wasn't set";

		_applications.put(app.name, app);
	}

	/**
	 * Retrieve application from the config store
	 * @param name name of the application
	 * @return application instance or null if doesn't exist
	 */
	synchronized Application getApplication(String name)
	{
		assert _root != null : "Root wasn't set";

		if (_applications.containsKey(name))
			return _applications.get(name);

		return null;
	}

	/**
	 * get instance of our configuration class
	 * @return instance of the class
	 */
	static PDCConfigStore getInstance()
	{
		if (_instance == null)
			_instance = new PDCConfigStore();

		return _instance;
	}
}
