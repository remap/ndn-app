/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc;

import edu.ucla.cens.pdc.libpdc.Application;
import com.mongodb.BasicDBObject;
import com.mongodb.DBCollection;
import com.mongodb.DBCursor;
import com.mongodb.DBObject;
import com.mongodb.MongoException;
import edu.ucla.cens.pdc.libpdc.datastructures.DataRecord;
import edu.ucla.cens.pdc.libpdc.stream.Storage;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCDatabaseException;
import edu.ucla.cens.pdc.libpdc.util.Log;
import java.util.LinkedList;
import java.util.List;
import org.bson.types.ObjectId;

/**
 *
 * @author Derek Kulinski
 */
final public class MongoDataStorage extends Storage {
	final private DBCollection _coll;

	private static String _prefix = null;

	private String _last_entry = null;

	public boolean insert_caching = true;

	public MongoDataStorage(Application app, String data_stream_id)
	{
		super(app, data_stream_id);

		_coll = Database.getDBCollection(Database.db_type.DATA, app.name,
						data_stream_id);

		_coll.setObjectClass(DataRecord.class);
	}

	public static void setPrefix(String prefix)
	{
		_prefix = prefix;
	}

	public static String getPrefix()
	{
		return _prefix;
	}

	@Override
	synchronized public String getLastEntry()
					throws PDCDatabaseException
	{
		DataRecord record;
		DBObject fields, sort;
		DBCursor cur;
		String last_entry;

		if (insert_caching && _last_entry != null)
			return _last_entry;

		fields = new BasicDBObject("_id", 1);
		sort = new BasicDBObject("$natural", -1);

		// Get _id of the first newest row
		cur = _coll.find(null, fields);
		cur.sort(sort);
		cur.limit(1);

		if (!cur.hasNext()) {
			Log.debug(
							"Doesn't look like we have anything in the database -> no last_entry");
			return null;
		}

		try {
			record = (DataRecord) cur.next();
		}
		catch (RuntimeException ex) {
			throw new PDCDatabaseException("Unable to fetch record", ex);
		}
		last_entry = record.getId().toStringMongod();
		Log.debug("Last entry is: " + last_entry);

		_last_entry = last_entry;

		return last_entry;
	}

	@Override
	public List<String> getRangeIds()
					throws PDCDatabaseException
	{
		DBCursor cur = _coll.find();

		return getRangeIds(cur);
	}

	@Override
	public List<String> getRangeIds(String start)
					throws PDCDatabaseException
	{
		try {
			ObjectId startid = new ObjectId(start);

			DBObject criteria = new BasicDBObject("$gt", startid);
			DBObject query = new BasicDBObject("_id", criteria);

			DBCursor cur = _coll.find(query);

			return getRangeIds(cur);
		}
		catch (IllegalArgumentException ex) {
			throw new PDCDatabaseException("Invalid start id", ex);
		}
	}

	@Override
	public List<String> getRangeIds(String start, String end)
					throws PDCDatabaseException
	{
		try {
			ObjectId startid = new ObjectId(start);
			ObjectId endid = new ObjectId(end);

			DBObject criteria = new BasicDBObject("$gte", startid).append("$lte",
							endid);
			DBObject query = new BasicDBObject("_id", criteria);

			DBCursor cur = _coll.find(query);

			return getRangeIds(cur);
		}
		catch (IllegalArgumentException ex) {
			throw new PDCDatabaseException("Invalid start and/or end ids", ex);
		}
	}

	private List<String> getRangeIds(DBCursor cur)
					throws PDCDatabaseException
	{
		List<String> result = new LinkedList<String>();

		try {
			while (cur.hasNext()) {
				ObjectId obj = (ObjectId) cur.next().get("_id");
				result.add(obj.toStringMongod());
			}
		}
		catch (RuntimeException ex) {
			throw new PDCDatabaseException("Unable to fetch data from the database",
							ex);
		}

		return result;
	}

	@Override
	public DataRecord getRecord(String id)
					throws PDCDatabaseException
	{
		ObjectId oid;

		try {
			oid = new ObjectId(id);
			DataRecord record = (DataRecord) _coll.findOne(oid);

			return record;
		}
		catch (MongoException ex) {
			throw new PDCDatabaseException("Unable to get record", ex);
		}
		catch (IllegalArgumentException ex) {
			return null;
		}
	}

	@Override
	synchronized public boolean insertRecord(DataRecord record)
					throws PDCDatabaseException
	{
		_last_entry = null;

		try {
			_coll.insert(record);
		}
		catch (MongoException ex) {
			throw new PDCDatabaseException("Unable to insert a record", ex);
		}

		return true;
	}
}
