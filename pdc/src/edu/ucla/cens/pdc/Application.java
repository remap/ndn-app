/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc;

import com.mongodb.DBCollection;
import edu.ucla.cens.pdc.libpdc.DataStream;
import edu.ucla.cens.pdc.libpdc.iApplication;
import java.util.HashMap;
import java.util.Map;

/**
 * Stores information about applications that PDV handles
 * @author Derek Kulinski
 */
public class Application implements iApplication {
	/**
	 * Identifier for the application
	 */
	final String name;

	/**
	 * Database
	 */
	final private Database _db;

	private Map<String, DataStream> _data_stream = new HashMap<String, DataStream>();

	Application(String name)
	{
		this.name = name;
		_db = new Database(Database.db_type.DATA, name);
	}

	public String getAppName()
	{
		return name;
	}

	/**
	 * Check if given data stream exists
	 * @param id
	 * @return
	 */
	synchronized public boolean data_stream_exists(String id)
	{
		return _data_stream.containsKey(id);
	}

	synchronized public DataStream data_stream_get(String id)
	{
		return _data_stream.get(id);
	}

	synchronized public DataStream data_stream_add(DataStream ds)
	{
		return _data_stream.put(ds.data_stream_id, ds);
	}

	DBCollection get_db_collection(String id)
	{
		return _db.getDatabase().getCollection(id);
	}
}
