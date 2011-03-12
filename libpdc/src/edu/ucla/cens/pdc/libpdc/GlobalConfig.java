/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc;

import edu.ucla.cens.pdc.libpdc.transport.PDCPublisher;
import edu.ucla.cens.pdc.libpdc.util.Log;
import edu.ucla.cens.pdc.libpdc.util.StringUtil;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;

/**
 *
 * @author Derek Kulinski
 */
public class GlobalConfig implements iState {
	private static final long serialVersionUID = -7308017340474869649L;

	private static GlobalConfig _instance;

	private static Class<? extends Storage> _data_storage_class = null;

	private static Class<? extends iConfigStorage> _config_storage_class = null;

	private transient iConfigStorage _config_storage;

	private transient ContentName _root = null;

	private transient final Map<String, Application> _applications = new HashMap<String, Application>();

	@SuppressWarnings("LeakingThisInConstructor")
	private GlobalConfig()
	{
		_config_storage = setupConfigStorage();
	}

	public static void setDataStorage(Class<? extends Storage> name)
	{
		if (_data_storage_class != null)
			throw new Error("You shouldn't change data storage type");

		_data_storage_class = name;
	}

	public static Storage setupDataStorage(iApplication app, String data_stream_id)
	{
		Constructor<? extends Storage> constructor;
		Storage store;

		assert _data_storage_class != null;

		try {
			constructor = _data_storage_class.getConstructor(app.getClass(),
							String.class);
			store = constructor.newInstance(app, data_stream_id);
		}
		catch (Exception ex) {
			throw new Error("Unable instantiate the storage class", ex);
		}

		return store;
	}

	public static void setConfigStorage(Class<? extends iConfigStorage> name)
	{
		if (_config_storage_class != null)
			throw new Error("You shouldn't change config storage type");

		_config_storage_class = name;
	}

	public static iConfigStorage setupConfigStorage()
	{
		if (_config_storage_class == null)
			throw new Error("You need to provide the storage class first");

		try {
			return _config_storage_class.newInstance();
		}
		catch (Exception ex) {
			throw new Error("Error while instantiating storage object", ex);
		}
	}

	/**
	 * Set the PDC's root
	 * @param root PDC's root
	 */
	public void setRoot(ContentName root)
	{
		if (_root != null)
			throw new UnsupportedOperationException(
							"You can't change the root once it is already set");

		_root = root;
	}

	/**
	 * Get the PDC's root
	 * @return PDC's root
	 */
	public ContentName getRoot()
	{
		assert _root != null : "Root wasn't set";

		return _root;
	}

	/**
	 * Add application to the config store
	 * @param app
	 */
	public synchronized void addApplication(Application app)
	{
		assert _root != null : "Root wasn't set";

		_applications.put(app.name, app);
	}

	/**
	 * Retrieve application from the config store
	 * @param name name of the application
	 * @return application instance or null if doesn't exist
	 */
	public synchronized Application getApplication(String name)
	{
		assert _root != null : "Root wasn't set";

		return _applications.get(name);
	}

	public synchronized DataStream uri2dataStream(ContentName stream)
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

	public Object loadConfig(String group, String name)
					throws IOException
	{
		return _config_storage.loadEntry(group, name);
	}

	public void saveConfig(iState object)
					throws IOException
	{
		_config_storage.saveEntry(object);
	}

	/**
	 * get instance of our configuration class
	 * @return instance of the class
	 */
	public static GlobalConfig getInstance()
	{
		if (_instance == null)
			_instance = new GlobalConfig();

		return _instance;
	}

	@Override
	public String toString()
	{
		List<String> data = new LinkedList<String>();
		StringBuilder sb = new StringBuilder();

		sb.append(this.getClass().getSimpleName());
		sb.append('[');
		data.add(_root == null ? null : _root.toURIString());
		data.add(_applications.toString());
		sb.append(StringUtil.join(data, "; "));
		sb.append(']');

		return sb.toString();
	}

	private void writeObject(ObjectOutputStream out)
					throws IOException
	{
		out.defaultWriteObject();

		out.writeUTF(_root.toURIString());
	}

	public void postStoreState(ObjectOutputStream out)
					throws IOException
	{
		int app_count = _applications.size();

		out.writeInt(app_count);
		for (String name : _applications.keySet()) {
			Log.debug("Saving app: " + name);
			out.writeUTF(name);
		}
	}

	private void readObject(ObjectInputStream in)
					throws IOException, ClassNotFoundException
	{
		int app_count;

		in.defaultReadObject();

		try {
			_root = ContentName.fromURI(in.readUTF());
		}
		catch (MalformedContentNameStringException ex) {
			throw new IOException("Error while parsing URI", ex);
		}

		_instance = this;
		_config_storage = setupConfigStorage();

		// Ugh! Force the compiler to do what we want.
		try {
			Field fld = GlobalConfig.class.getDeclaredField("_applications");
			fld.setAccessible(true);
			fld.set(this, new HashMap<String, Application>());
		}
		catch (Exception ex) {
			throw new Error("Unable to override access restrictions.", ex);
		}
	}

	public void postLoadState(ObjectInputStream in)
					throws IOException
	{
		int app_count = in.readInt();

		for (int i = 0; i < app_count; i++) {
			String name = in.readUTF();
			Log.debug("app: " + name);

			// the loadState should also add applications to our list at
			// the right time
			Application.loadState(name);
		}
	}

	public String getStateGroupName()
	{
		return "main";
	}

	public String getStateKey()
	{
		return "global";
	}

	public void storeState()
					throws IOException
	{
		_config_storage.saveEntry(this);
	}

	public void storeStateRecursive()
					throws IOException
	{
		for (Application app : _applications.values())
			app.storeStateRecursive();

		storeState();
	}

	public static GlobalConfig loadState()
					throws IOException
	{
		// Bootstrapping the process
		iConfigStorage storage = GlobalConfig.setupConfigStorage();
		GlobalConfig config = (GlobalConfig) storage.loadEntry("main", "global");

		return config;
	}
}
