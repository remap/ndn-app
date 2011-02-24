/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc;

import java.util.HashMap;
import java.util.Map;

/**
 *
 * @author Derek Kulinski
 */
public class PDCConfigStore {

	private static PDCConfigStore _instance;
	private Map<String, Application> _applications;

	/**
	 * Constructor
	 */
	private PDCConfigStore()
	{
		_applications = new HashMap<String, Application>();
	}

	/**
	 * Add application to the config store
	 * @param app
	 */
	void add_application(Application app)
	{
		_applications.put(app.name, app);
	}

	/**
	 * Retrieve application from the config store
	 * @param name name of the application
	 * @return application instance or null if doesn't exist
	 */
	Application get_application(String name)
	{
		if (_applications.containsKey(name))
			return _applications.get(name);

		return null;
	}

	/**
	 * get instance of our configuration class
	 * @return instance of the class
	 */
	static PDCConfigStore get_instance()
	{
		if (_instance == null)
			_instance = new PDCConfigStore();

		return _instance;
	}
}
