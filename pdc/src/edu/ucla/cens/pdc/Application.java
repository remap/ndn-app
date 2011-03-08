/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc;

import com.mongodb.DBCollection;
import edu.ucla.cens.pdc.libpdc.DataStream;
import edu.ucla.cens.pdc.libpdc.iApplication;
import edu.ucla.cens.pdc.libpdc.util.Log;
import java.lang.String;
import java.lang.reflect.Field;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedHashSet;
import java.util.Map;
import java.util.Set;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.bson.BSONObject;
import org.bson.types.ObjectId;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;

/**
 * Stores information about applications that PDV handles
 * @author Derek Kulinski
 */
public class Application implements iApplication, iConfig {
	/**
	 * Identifier for the application
	 */
	final String name;

	final private ContentName _base_uri;

	private ObjectId _id;

	/**
	 * Database
	 */
	final private Database _db;

	private Map<String, DataStream> _data_stream = new HashMap<String, DataStream>();

	final static private Map<String, String> _db_map = new HashMap<String, String>();

	static {
		_db_map.put("_id", "_id");
		_db_map.put("name", "name");
	}

	Application(String name)
	{
		PDCConfigStore config = PDCConfigStore.getInstance();

		this.name = name;
		try {
			_base_uri = config.getRoot().append(name);
			_db = new Database(Database.db_type.DATA, name);
		}
		catch (MalformedContentNameStringException ex) {
			throw new Error("Unable to set base name", ex);
		}
	}

	public String getAppName()
	{
		return name;
	}

	public ContentName getBaseName()
	{
		return _base_uri;
	}

	/**
	 * Check if given data stream exists
	 * @param id
	 * @return
	 */
	synchronized public boolean isDataStream(String id)
	{
		return _data_stream.containsKey(id);
	}

	synchronized public DataStream getDataStream(String id)
	{
		return _data_stream.get(id);
	}

	synchronized public DataStream addDataStream(DataStream ds)
	{
		return _data_stream.put(ds.data_stream_id, ds);
	}

	synchronized Iterator<DataStream> getDataStreamsIterator()
	{
		return _data_stream.values().iterator();
	}

	DBCollection get_db_collection(String id)
	{
		return _db.getDatabase().getCollection(id);
	}

	public String getCollectionName()
	{
		return "applications";
	}

	public String getConfigKey()
	{
		return name;
	}

	public void markAsPartialObject()
	{
		throw new UnsupportedOperationException("Not supported yet.");
	}

	public boolean isPartialObject()
	{
		throw new UnsupportedOperationException("Not supported yet.");
	}

	public Object put(String key, Object v)
	{
		Log.debug("Putting: " + key + " " + v.toString());

		Field field = getField(key);
		if (field != null)
			try {
				field.set(this, v);
				return v;
			}
			catch (IllegalArgumentException ex) {
				return null;
			}
			catch (IllegalAccessException ex) {
				return null;
			}

		throw new UnsupportedOperationException("Not supported yet.");
	}

	public void putAll(BSONObject o)
	{
		throw new UnsupportedOperationException("Not supported yet.");
	}

	@SuppressWarnings("rawtypes")
	public void putAll(Map m)
	{
		throw new UnsupportedOperationException("Not supported yet.");
	}

	private Field getField(String key)
	{
		String f;

		f = _db_map.get(key);
		if (f == null)
			return null;

		try {
			return Application.class.getDeclaredField(f);
		}
		catch (NoSuchFieldException ex) {
			return null;
		}
		catch (SecurityException ex) {
			return null;
		}
	}

	public Object get(String key)
	{
		Log.debug("Getting: " + key);

		Field field = getField(key);
		if (field != null)
			try {
				return field.get(this);
			}
			catch (IllegalArgumentException ex) {
				return null;
			}
			catch (IllegalAccessException ex) {
				return null;
			}

//		if (key.equals("_id"))
//			return _id;
//
//		if (key.equals("name"))
//			return name;

		if (key.equals("base_uri"))
			return _base_uri.toURIString();

		return null;
//		throw new UnsupportedOperationException("Not supported yet.");
	}

	@SuppressWarnings("rawtypes")
	public Map toMap()
	{
		throw new UnsupportedOperationException("Not supported yet.");
	}

	public Object removeField(String key)
	{
		throw new UnsupportedOperationException("Not supported yet.");
	}

	public boolean containsKey(String s)
	{
		throw new UnsupportedOperationException("Not supported yet.");
	}

	public boolean containsField(String s)
	{
		Object value;
		Field field = getField(s);

		if (field != null)
			try {
				value = field.get(this);
				return value != null;
			}
			catch (IllegalArgumentException ex) {
				return false;
			}
			catch (IllegalAccessException ex) {
				return false;
			}

		if (s.equals("base_uri"))
			return true;

		return false;
	}

	public Set<String> keySet()
	{
		Set<String> set = new LinkedHashSet<String>();

		for (String field : _db_map.keySet()) {
			if (containsField(field))
				set.add(field);
		}

		set.add("base_uri");

		return set;
	}
}
