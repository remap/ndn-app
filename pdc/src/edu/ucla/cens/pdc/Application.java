/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc;

import com.mongodb.DBCollection;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Stores information about applications that PDV handles
 * @author Derek Kulinski
 */
public class Application {
	/**
	 * Identifier for the application
	 */
	final String name;
	/**
	 * Database
	 */
	final private Database _db;
	//XXX: not thread safe
	private Map<String, DataStream> _data_stream = new HashMap<String, DataStream>();
	//XXX: not thread safe

	Application(String name)
	{
		this.name = name;
		_db = new Database(Database.db_type.DATA, name);
	}

	/**
	 * Check if given data stream exists
	 * @param id
	 * @return
	 */
	boolean data_stream_exists(String id)
	{
		return _data_stream.containsKey(id);
	}

	DataStream data_stream_get(String id)
	{
		return _data_stream.get(id);
	}

	DataStream data_stream_add(DataStream ds)
	{
		return _data_stream.put(ds.data_stream_id, ds);
	}

	DBCollection get_db_collection(String id) {
		return _db.getDatabase().getCollection(id);
	}
}
