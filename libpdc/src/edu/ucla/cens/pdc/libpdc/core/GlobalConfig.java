/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc.core;

import edu.ucla.cens.pdc.libpdc.Application;
import edu.ucla.cens.pdc.libpdc.SystemState;
import edu.ucla.cens.pdc.libpdc.iApplication;
import edu.ucla.cens.pdc.libpdc.iConfigStorage;
import edu.ucla.cens.pdc.libpdc.iState;
import edu.ucla.cens.pdc.libpdc.stream.Storage;
import edu.ucla.cens.pdc.libpdc.stream.DataStream;
import edu.ucla.cens.pdc.libpdc.transport.PDCPublisher;
import edu.ucla.cens.pdc.libpdc.util.StringUtil;
import java.io.IOException;
import java.lang.reflect.Constructor;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import org.ccnx.ccn.config.ConfigurationException;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.KeyLocator;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import org.ccnx.ccn.protocol.PublisherPublicKeyDigest;

/**
 *
 * @author Derek Kulinski
 */
public class GlobalConfig implements iState {
	@SuppressWarnings("LeakingThisInConstructor")
	private GlobalConfig()
	{
		_config_storage = setupConfigStorage();
		try {
			_instance = this;
			setupObject();
		}
		catch (IOException ex) {
			_instance = null;
			throw new Error("Cannot instantiate config", ex);
		}
		catch (RuntimeException ex) {
			_instance = null;
			throw ex;
		}
		catch (Error ex) {
			_instance = null;
			throw ex;
		}
	}

	@SuppressWarnings("LeakingThisInConstructor")
	private GlobalConfig(SystemState.GlobalConfig state)
					throws IOException
	{
		assert _instance == null;
		assert state != null;
		assert state.hasRoot();

		try {
			_root = ContentName.fromNative(state.getRoot());
		}
		catch (MalformedContentNameStringException ex) {
			throw new Error("Unable to parse previously stored root", ex);
		}

		try {
			_config_storage = setupConfigStorage();
			_instance = this;
			setupObject();

			for (String app_name : state.getApplicationsList()) {
				Application app = new Application(app_name, true);
				addApplication(app);
			}
		}
		catch (IOException ex) {
			_instance = null;
			throw ex;
		}
		catch (RuntimeException ex) {
			_instance = null;
			throw new Error("Failure when initializing the object", ex);
		}
		catch (Error ex) {
			_instance = null;
			throw new Error("Failure when initializing the object", ex);
		}
	}

	private void setupObject()
					throws IOException
	{
		PDCKeyManager keymanager;

		try {
			keymanager = new PDCKeyManager();
			keymanager.initialize();

			setKeyManager(keymanager);
		}
		catch (ConfigurationException ex) {
			throw new Error("Unable to setup keymanager", ex);
		}

//		locator = new KeyLocator(keyname);
//		digest = keymanager.getDefaultKeyID();
//		keymanager.setKeyLocator(digest, locator);

//		keymanager.publishKeyToRepository(keyname, digest);

//		config.getApplication("myapp").getDataStream("myds").getTransport().
//						getEncryptor().setStreamKeyDigest(digest);
		//XXX: remove this code
	}

	/**
	 * Provide class responsible for handling data storage
	 * @param name class name
	 */
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

		assert app != null;
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

	/**
	 * Provide class responsible for handling configuration storage
	 */
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
	public final synchronized void addApplication(Application app)
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

	/**
	 * Provide proper DataStream object based on the given URI
	 * @param stream <app>/<ds> component of the name
	 * @return object associated with the name
	 */
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

			if (!publisher.getStreamId().equals(ds_id))
				continue;

			result = ds;
		}

		return result;
	}

	/**
	 * Return Key Manager
	 * @return Key Manager
	 */
	public PDCKeyManager getKeyManager()
	{
		return _key_manager;
	}

	public void setKeyManager(PDCKeyManager key_manager)
	{
		this._key_manager = key_manager;
	}

	/**
	 * load configuration binary data
	 * @param group group under the configuration is held
	 * @param name unique identifier within the group
	 * @return binary encoded data or null if no entry exists
	 * @throws IOException when there's an issue accessing the data
	 */
	public byte[] loadConfig(String group, String name)
					throws IOException
	{
		return _config_storage.loadEntry(group, name);
	}

	public void saveConfig(iState object)
					throws IOException
	{
		_config_storage.saveEntry(object.getStateGroupName(), object.getStateKey(),
						object.stateToByteArray());
	}

	public void saveConfig(String group, String name, byte[] byte_out)
					throws IOException
	{
		_config_storage.saveEntry(group, name, byte_out);
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

// <editor-fold defaultstate="collapsed" desc="class serialization">
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
		saveConfig(this);
	}

	public void storeStateRecursive()
					throws IOException
	{
		assert _key_manager != null : "Storing state needs to be done after key manager is instantienated";
		_key_manager.storeStateRecursive();

		for (Application app : _applications.values())
			app.storeStateRecursive();

		storeState();
	}

	public static GlobalConfig loadState()
					throws IOException
	{
		byte[] byte_in;
		SystemState.GlobalConfig state;

		// Bootstrapping the process
		final iConfigStorage storage = GlobalConfig.setupConfigStorage();

		byte_in = storage.loadEntry("main", "global");
		if (byte_in == null)
			return null;

		state = SystemState.GlobalConfig.parseFrom(byte_in);
		return new GlobalConfig(state);
	}

	SystemState.GlobalConfig getObjectState()
	{
		SystemState.GlobalConfig.Builder builder = SystemState.GlobalConfig.
						newBuilder();

		if (_root == null)
			throw new RuntimeException("Root is not set");

		builder.setRoot(_root.toString());
		builder.addAllApplications(_applications.keySet());

		return builder.build();
	}

	public byte[] stateToByteArray()
	{
		return getObjectState().toByteArray();
	}
// </editor-fold>

	private static GlobalConfig _instance;

	private static Class<? extends Storage> _data_storage_class = null;

	private static Class<? extends iConfigStorage> _config_storage_class = null;

	private transient iConfigStorage _config_storage;

	private transient ContentName _root = null;

	private transient final Map<String, Application> _applications = new HashMap<String, Application>();

	private transient PDCKeyManager _key_manager = null;
}
