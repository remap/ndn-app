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
import com.mongodb.util.JSON;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCDatabaseException;
import edu.ucla.cens.pdc.libpdc.iState;
import edu.ucla.cens.pdc.libpdc.iConfigStorage;
import edu.ucla.cens.pdc.libpdc.util.Log;
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

	public Object loadEntry(String group, String name)
					throws IOException
	{
		boolean exists;
		DBCollection coll;
		DBObject query = new BasicDBObject();
		DBObject db_response;
		ByteArrayInputStream byte_in;
		ObjectInputStream obj_in;
		iState result;

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

		byte_in = new ByteArrayInputStream((byte[]) db_response.get("object"));
		try {
			obj_in = new ObjectInputStream(byte_in);
			byte_in.close();
			result = (iState) obj_in.readObject();
			result.postLoadState(obj_in);
			obj_in.close();

			return result;
		}
		catch (ClassNotFoundException ex) {
			throw new IOException("Invalid data", ex);
		}
		catch (IOException ex) {
			throw new IOException("Problem parsing data", ex);
		}
	}

	public void saveEntry(iState object)
					throws IOException
	{
		boolean exists;
		DBCollection coll;
		ByteArrayOutputStream byte_out;
		ObjectOutputStream obj_out;
		DBObject query = new BasicDBObject();
		DBObject new_data = new BasicDBObject();

		exists = _db.collectionExists(object.getStateGroupName());
		coll = _db.getCollection(object.getStateGroupName());
		if (!exists)
			coll.ensureIndex("name");

		byte_out = new ByteArrayOutputStream(1024);
		obj_out = new ObjectOutputStream(byte_out);
		obj_out.writeObject(object);
		object.postStoreState(obj_out);
		obj_out.close();

		query.put("name", object.getStateKey());
		new_data.put("name", object.getStateKey());
		new_data.put("object", byte_out.toByteArray());

		byte_out.close();

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
