/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pdc;

import java.util.HashMap;
import java.util.Map;

/**
 *
 * @author takeda
 */
public class PDCConfigStore {

	private static PDCConfigStore _instance;
	private Map<String, Application> _applications = new HashMap<String, Application>();

	void addApplication(Application app) {
		_applications.put(app.name, app);
	}
	
	Application getApplication(String name) {
		if (_applications.containsKey(name))
			return _applications.get(name);

		return null;
	}

	/**
	 * get instance of our configuration class
	 * @return
	 */
	static PDCConfigStore get_instance() {
		if (_instance == null)
			_instance = new PDCConfigStore();

		return _instance;
	}
}
