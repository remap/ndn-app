/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pdc;

import com.mongodb.Mongo;
import com.mongodb.DB;
import com.mongodb.MongoException;
import java.net.UnknownHostException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author takeda
 */
public class Database {

	private static String _prefix = null;
	private static Mongo _connection;
	private DB _database;

	public enum db_type {
		DATA
	}

	public DB getDatabase() {
		return _database;
	}

	public Database(db_type type, String app) throws MongoException {
		String name = type2name(type) + "_" + app;

		try {
			if (_connection == null)
				_connection = new Mongo();

			if (_prefix != null)
				name = _prefix.concat(name);

			_database = _connection.getDB(name);
		} catch (UnknownHostException ex) {
			Logger.getLogger(Database.class.getName()).log(Level.SEVERE, null, ex);
		}
	}

	private String type2name(db_type type) {
		switch (type) {
			case DATA:
				return "data";
		}

		throw new RuntimeException("unknown type");
	}

	/**
	 * Set prefix for database names
	 * Should be useful if you run more than one pdv that uses the same database
	 * @param prefix
	 */
	public static void setPrefix(String prefix) {
		_prefix = prefix;
	}
}
