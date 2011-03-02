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
import java.util.logging.Level;
import java.util.logging.Logger;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;

/**
 * Stores information about applications that PDV handles
 * @author Derek Kulinski
 */
public class Application implements iApplication {
	/**
	 * Identifier for the application
	 */
	final String name;

	final private ContentName _base_name;

	/**
	 * Database
	 */
	final private Database _db;

	private Map<String, DataStream> _data_stream = new HashMap<String, DataStream>();

	Application(String name)
	{
		PDCConfigStore config = PDCConfigStore.getInstance();

		this.name = name;
		try {
			_base_name = config.getRoot().append(name);
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
		return _base_name;
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

	DBCollection get_db_collection(String id)
	{
		return _db.getDatabase().getCollection(id);
	}
}
