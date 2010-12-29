/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pdc;

import com.mongodb.BasicDBObject;
import com.mongodb.DBCollection;
import com.mongodb.DBCursor;
import com.mongodb.DBObject;
import java.util.Collection;
import java.util.LinkedList;
import java.util.List;
import org.bson.types.ObjectId;

/**
 *
 * @author takeda
 */
class DataStream {

	final String id;
	final String app_id;
	byte[] key = null;
	String last_entry = null;
	private Database _db;
	private DBCollection _coll;

	DataStream(Application app, String id) {
		assert !id.startsWith("/") : "stream id: " + id;

		this.app_id = app.name;
		this.id = id;

		_db = new Database(Database.db_type.DATA, app_id);
		_coll = _db.getDatabase().getCollection(id);
		_coll.setObjectClass(DataRecord.class);
	}

	DataStream(String appid, String id) {
		assert !id.startsWith("/") : "stream id: " + id;

		this.app_id = appid;
		this.id = id;

		_db = new Database(Database.db_type.DATA, app_id);
		_coll = _db.getDatabase().getCollection(id);
		_coll.setObjectClass(DataRecord.class);
	}

	DataRecord getRecord(String id) {
		DataRecord record = (DataRecord) _coll.findOne(new ObjectId(id));

		return record;
	}

	List<String> getRangeIds(String start) {
		ObjectId startid = new ObjectId(start);

		DBObject criteria = new BasicDBObject("$gt", startid);
		DBObject query = new BasicDBObject("_id", criteria);

		DBCursor cur = _coll.find(query);

		List<String> result = new LinkedList<String>();
		while (cur.hasNext()) {
			ObjectId obj = (ObjectId) cur.next().get("_id");
			result.add(obj.toStringMongod());
		}

		return result;
	}

	List<String> getRangeIds(String start, String end) {
		ObjectId startid = new ObjectId(start);
		ObjectId endid = new ObjectId(end);

		DBObject criteria = new BasicDBObject("$gte", startid)
						.append("$lte", endid);
		DBObject query = new BasicDBObject("_id", criteria);

		DBCursor cur = _coll.find(query);

		List<String> result = new LinkedList<String>();
		while (cur.hasNext()) {
			ObjectId obj = (ObjectId) cur.next().get("_id");
			result.add(obj.toStringMongod());
		}

		return result;
	}

	String getLastDBEntry() {
		Database db = new Database(Database.db_type.DATA, app_id);
		DBCollection coll = db.getDatabase().getCollection(id);

		return "blah";
	}
}
