/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc;

import edu.ucla.cens.pdc.libpdc.DataStream;
import edu.ucla.cens.pdc.libpdc.transport.PDCPublisher;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;

/**
 *
 * @author Derek Kulinski
 */
public class PDCConfigStore {
	private static PDCConfigStore _instance;

	private Map<String, Application> _applications;
	private Map<String, DataStream> _stream_lookup_cache;

	private ContentName _root = null;

	/**
	 * Constructor
	 */
	private PDCConfigStore()
	{
		_applications = new HashMap<String, Application>();
		_stream_lookup_cache = new HashMap<String, DataStream>();
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

	synchronized DataStream uri2dataStream(ContentName stream)
	{
		DataStream ds, result = null;
		Application app;
		String app_id, ds_id;
		Iterator<DataStream> dsi;
		PDCPublisher publisher;
		int components;
		ContentName publisher_uri;

		//The URI should be like this: ccnx:/some/path/to/pdv/<app>/<ds>
		components = stream.count();
		if (components < 2)
			return null;

		ds_id = stream.stringComponent(--components);
		app_id = stream.stringComponent(--components);
		publisher_uri = stream.cut(components);

		app = getApplication(app_id);
		if (app == null)
			return null;

		dsi = app.getDataStreamsIterator();
		while (dsi.hasNext()) {
			ds = dsi.next();
			publisher = ds.getPublisher();

			if (publisher == null)
				continue;

			if (!publisher.uri.equals(publisher_uri))
				continue;

			if (!publisher.getStream_id().equals(ds_id))
				continue;

			result = ds;
		}

		return result;
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
