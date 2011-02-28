/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc;

import com.mongodb.BasicDBObject;
import com.mongodb.DBCollection;
import com.mongodb.DBCursor;
import com.mongodb.DBObject;
import com.mongodb.MongoException;
import com.mongodb.WriteConcern;
import edu.ucla.cens.pdc.libpdc.DataRecord;
import edu.ucla.cens.pdc.libpdc.Storage;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCDatabaseException;
import edu.ucla.cens.pdc.libpdc.util.Log;
import java.util.LinkedList;
import java.util.List;
import org.bson.types.ObjectId;

/**
 *
 * @author Derek Kulinski
 */
final public class MongoStorage extends Storage {
	final private DBCollection _coll;

	public MongoStorage(Application app, String data_stream_id)
	{
		super(app, data_stream_id);

		_coll = app.get_db_collection(data_stream_id);
		_coll.setObjectClass(DataRecord.class);
	}

	@Override
	public String getLastEntry()
	{
		DataRecord record;
		DBObject fields = new BasicDBObject("_id", 1);
		DBObject sort = new BasicDBObject("$natural", -1);
		String last_entry;

		// Get _id of the first newest row
		DBCursor cur = _coll.find(null, fields);
		cur.sort(sort);
		cur.limit(1);

		if (!cur.hasNext()) {
			Log.debug(
							"Doesn't look like we have anything in the database -> no last_entry");
			return null;
		}

		record = (DataRecord) cur.next();
		last_entry = record.getId().toStringMongod();
		Log.debug("Last entry is: " + last_entry);

		return last_entry;
	}

	@Override
	public List<String> getRangeIds()
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
	{
		List<String> result = new LinkedList<String>();

		while (cur.hasNext()) {
			ObjectId obj = (ObjectId) cur.next().get("_id");
			result.add(obj.toStringMongod());
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
	public boolean insertRecord(DataRecord record)
					throws PDCDatabaseException
	{
//		WriteResult result;
		try {
			_coll.insert(record, WriteConcern.NORMAL);
		}
		catch (MongoException ex) {
			throw new PDCDatabaseException("Unable to insert a record", ex);
		}

		return true;
	}
}
