/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc;

import com.mongodb.BasicDBObject;
import com.mongodb.DB;
import com.mongodb.DBCollection;
import com.mongodb.DBObject;
import com.mongodb.Mongo;
import com.mongodb.MongoException;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCDatabaseException;
import edu.ucla.cens.pdc.libpdc.iState;
import edu.ucla.cens.pdc.libpdc.iConfigStorage;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.UnknownHostException;

/**
 *
 * @author Derek Kulinski
 */
final public class MongoConfigStorage implements iConfigStorage {
	private static Mongo _mongo;

	private static DB _db;

	private static String _prefix = null;

	public MongoConfigStorage()
					throws PDCDatabaseException
	{
		setupClass();
	}

	private void setupClass()
					throws PDCDatabaseException
	{
		String name;

		if (_db != null)
			return;

		if (_mongo == null)
			try {
				_mongo = new Mongo();
			}
			catch (UnknownHostException ex) {
				throw new PDCDatabaseException("Unable to setup mongo connection", ex);
			}
			catch (MongoException ex) {
				throw new PDCDatabaseException("Unable to setup mongo connection", ex);
			}

		name = (_prefix == null ? "" : _prefix).concat("settings");

		_db = _mongo.getDB(name);
	}

	static public void setPrefix(String prefix)
	{
		_prefix = prefix;
	}

	public ByteArrayInputStream loadEntry(String group, String name)
					throws IOException
	{
		boolean exists;
		DBCollection coll;
		DBObject query = new BasicDBObject();
		DBObject db_response;

		exists = _db.collectionExists(group);
		coll = _db.getCollection(group);
		if (!exists)
			coll.ensureIndex("name");

		query.put("name", name);

		try {
			db_response = coll.findOne(query);
		}
		catch (MongoException ex) {
			throw new IOException("Unable to fetch data object", ex);
		}

		if (db_response == null)
			return null;

		return new ByteArrayInputStream((byte[]) db_response.get("object"));
	}

	public void saveEntry(String obj_group, String obj_key,
					ByteArrayOutputStream byte_out)
					throws IOException
	{
		boolean exists;
		DBCollection coll;
		DBObject query = new BasicDBObject();
		DBObject new_data = new BasicDBObject();

		exists = _db.collectionExists(obj_group);
		coll = _db.getCollection(obj_group);
		if (!exists)
			coll.ensureIndex("name");

		query.put("name", obj_key);
		new_data.put("name", obj_key);
		new_data.put("object", byte_out.toByteArray());

		try {
			coll.findAndModify(query, null, null, false, new_data, false, true);
		}
		catch (RuntimeException ex) {
			throw new IOException("Unable to insert data record", ex);
		}
	}

	public void removeEntry(String group, String name)
	{
		throw new UnsupportedOperationException("Not supported yet.");
	}
}
