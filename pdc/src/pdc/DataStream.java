/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pdc;

import java.util.logging.Level;
import java.util.logging.Logger;
import pdc.exceptions.PDCNoResponseException;
import com.mongodb.BasicDBObject;
import com.mongodb.DBCollection;
import com.mongodb.DBCursor;
import com.mongodb.DBObject;
import com.mongodb.WriteConcern;
import com.mongodb.WriteResult;
import com.mongodb.util.JSON;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Timer;
import java.util.TimerTask;
import org.bson.types.ObjectId;
import pdc.util.Log;

/**
 *
 * @author Derek Kulinski
 */
public class DataStream {
	/**
	 * id of the data stream
	 */
	final String data_stream_id;
	/**
	 * application associated with the DS
	 */
	final Application app;
	/**
	 * key used for symmetric encryption
	 */
	byte[] key = null;
	/**
	 * id of last record in the database
	 */
	private String _last_entry = null;
	private PDVNode _uplink = null;
	private List<PDVNode> _downlinks = new ArrayList<PDVNode>();
	private Timer pull_timer;
	final private Database _db;
	final private DBCollection _coll;
	final private PDCConfigStore _config = PDCConfigStore.get_instance();
	final private PDCReplicator _replicator = PDCReplicator.get_instance();
	final private PDCDataProvider _data_provider = PDCDataProvider.get_instance();

	DataStream(Application app, String data_stream_id)
	{
		assert app != null;
		assert data_stream_id != null && !data_stream_id.isEmpty();
		assert !data_stream_id.startsWith("/") : "stream id: " + data_stream_id;

		this.app = app;
		this.data_stream_id = data_stream_id;

		_db = new Database(Database.db_type.DATA, app.name);
		_coll = _db.getDatabase().getCollection(data_stream_id);
		_coll.setObjectClass(DataRecord.class);
	}

	PDVNode get_uplink()
	{
		return _uplink;
	}

	void set_uplink(PDVNode node)
	{
		_uplink = node;
	}

	void add_downlink(PDVNode node)
	{
		_downlinks.add(node);
	}

	void del_downlink(PDVNode node)
	{
		_downlinks.remove(node);
	}

	/**
	 * get record from database by its id
	 * @param id object id of the record
	 * @return record or null if doesn't exist
	 */
	DataRecord getRecord(String id)
	{
		DataRecord record = (DataRecord) _coll.findOne(new ObjectId(id));

		return record;
	}

	WriteResult insertRecord(DataRecord record)
	{
		return _coll.insert(record, WriteConcern.NORMAL);
	}

	List<String> getRangeIds()
	{
		DBCursor cur = _coll.find();

		return getRangeIds(cur);
	}

	List<String> getRangeIds(String start)
	{
		ObjectId startid = new ObjectId(start);

		DBObject criteria = new BasicDBObject("$gt", startid);
		DBObject query = new BasicDBObject("_id", criteria);

		DBCursor cur = _coll.find(query);

		return getRangeIds(cur);
	}

	/**
	 * Get record ids from start to end (included)
	 * @param start
	 * @param end
	 * @return
	 */
	List<String> getRangeIds(String start, String end)
	{
		ObjectId startid = new ObjectId(start);
		ObjectId endid = new ObjectId(end);

		DBObject criteria = new BasicDBObject("$gte", startid).append("$lte", endid);
		DBObject query = new BasicDBObject("_id", criteria);

		DBCursor cur = _coll.find(query);

		return getRangeIds(cur);
	}

	List<String> getRangeIds(DBCursor cur)
	{
		List<String> result = new LinkedList<String>();

		while (cur.hasNext()) {
			ObjectId obj = (ObjectId) cur.next().get("_id");
			result.add(obj.toStringMongod());
		}

		return result;
	}

	void fetchDataFromUplink()
					throws PDCNoResponseException
	{
		PDVNode node;
		DataRecord record;
		Collection<String> ids;

		node = get_uplink();
		if (node == null) {
			Log.warning("No uplink defined; fetching aborted");
			return;
		}

		updateLastEntry();

		if (_last_entry == null)
			ids = _replicator.callPull(node.uri, this);
		else
			ids = _replicator.callPull(node.uri, this, _last_entry);

		Iterator<String> iter = ids.iterator();

		//XXX: Skip first entry which is URI
		if (iter.hasNext())
			iter.next();

		while (iter.hasNext()) {
			String data_id = iter.next();
			Log.debug("pulling: " + data_id);
			record = _data_provider.fetchRecord(node.uri, app, data_stream_id, data_id);
			Log.debug("got: " + JSON.serialize(record));
			insertRecord(record);
			_last_entry = record.id.toStringMongod();
		}
	}

	private void updateLastEntry()
	{
		DataRecord record;
		DBObject fields = new BasicDBObject("_id", 1);
		DBObject sort = new BasicDBObject("$natural", -1);

		//Get _id of the first newest row
		DBCursor cur = _coll.find(null, fields);
		cur.sort(sort);
		cur.limit(1);

		if (!cur.hasNext()) {
			Log.debug(
							"Doesn't look like we have anything in the database -> no last_entry");
			_last_entry = null;
			return;
		}

		record = (DataRecord) cur.next();
		_last_entry = record.id.toStringMongod();
		Log.debug("Last entry is: " + _last_entry);
	}

	public void periodicPullStart(long period)
	{
		if (pull_timer != null)
			periodicPullStop();

		pull_timer = new Timer(true);
		pull_timer.schedule(new TimerTask() {
			@Override
			public void run()
			{
				try {
					fetchDataFromUplink();
				}
				catch (PDCNoResponseException ex) {
					Logger.getLogger(DataStream.class.getName()).log(Level.SEVERE, null,
									ex);
				}
			}
		}, 0, period);
	}

	public void periodicPullStop()
	{
		if (pull_timer == null)
			return;

		pull_timer.cancel();
		pull_timer = null;
	}
}
