/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pdc;

import com.mongodb.Mongo;
import com.mongodb.DB;
import com.mongodb.DBCollection;
import com.mongodb.BasicDBObject;
import com.mongodb.DBObject;
import com.mongodb.DBCursor;
import com.mongodb.MongoException;
import java.net.UnknownHostException;

/**
 *
 * @author takeda
 */
public class Database {

	private static Mongo _connection;
	private DB _database;

	public Database(String name) throws MongoException, UnknownHostException {
		if (_connection == null)
			_connection = new Mongo();

		_database = _connection.getDB(name);
	}
	
}
