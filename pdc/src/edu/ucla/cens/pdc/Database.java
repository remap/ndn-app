/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc;

import com.mongodb.Mongo;
import com.mongodb.DB;
import com.mongodb.DBCollection;
import java.net.UnknownHostException;
import java.util.HashMap;
import java.util.Map;

/**
 * Interface between PDV and database
 * @author Derek Kulinski
 */
public class Database {
	/**
	 * Prefix for databases
	 * (useful when multiple PDVs run with one database; mostly for testing)
	 */
	private static String _prefix = null;

	private static Mongo _connection;

	private final static Map<String, DB> _dbs = new HashMap<String, DB>();

	public enum db_type {
		/**
		 * Application data
		 */
		DATA

	}

	public static DB getDatabase(db_type type, String db_name)
	{
		DB result;
		String name;

		name = type2name(type) + "_" + db_name;
		if (_prefix != null)
			name = _prefix.concat(name);

		try {
			if (_connection == null)
				_connection = new Mongo();

			result = _dbs.get(name);
			if (result == null)
				result = _connection.getDB(name);
		}
		catch (UnknownHostException ex) {
			throw new Error("Unable to make connection with MongoDB", ex);
		}

		return result;
	}

	public static DBCollection getDBCollection(db_type type, String db_name,
					String collection_id)
	{
		DB db;

		db = getDatabase(type, db_name);

		return db.getCollection(collection_id);
	}

	private static String type2name(db_type type)
	{
		switch (type) {
		case DATA:
			return "data";
		}

		throw new RuntimeException("unknown type");
	}

	/**
	 * Set prefix for database names
	 * Should be useful if you run more than one PDV that uses the same database
	 * @param prefix string prefix
	 */
	public static void setPrefix(String prefix)
	{
		_prefix = prefix;
	}
}
