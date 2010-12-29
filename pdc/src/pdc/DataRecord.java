/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pdc;

import com.mongodb.BasicDBObject;
import com.mongodb.DBObject;
import org.bson.BSONObject;
import java.text.*;
import java.util.*;
import org.bson.types.ObjectId;

/**
 *
 * @author takeda
 */
public final class DataRecord implements DBObject {

	ObjectId id;
	int type = -1;
	Date timestamp = null;
	DBObject data = new BasicDBObject();

	public DataRecord() {
	}
	
	public DataRecord(String id) {
		this.id = new ObjectId(id);
	}

	public DataRecord(int type, Date ts) {
		this.type = type;
		this.timestamp = ts;
	}

	public DataRecord(Map data) {
		this.putAll(data);
	}

	public void markAsPartialObject() {
		throw new UnsupportedOperationException("Not supported yet.");
	}

	public boolean isPartialObject() {
		throw new UnsupportedOperationException("Not supported yet.");
	}

	public Object put(String string, Object o) {
		if (string.equals("_id")) {
			id = (ObjectId) o;

			return id;
		} else if (string.equals("type")) {
			type = Integer.parseInt(o.toString());

			return type;
		} else if (string.equals("timestamp")) {
			try {
				timestamp = DateFormat.getInstance().parse(o.toString());
			} catch (ParseException ex) {
				timestamp = null;
			}

			return timestamp;
		}

		return data.put(string, o);
	}

	public void putAll(BSONObject bsono) {
		putAll(bsono.toMap());
	}

	public void putAll(Map map) {
		Map m = new LinkedHashMap(map);

		if (m.containsKey("_id")) {
			id = (ObjectId) m.get("_id");
			m.remove("_id");
		}

		if (m.containsKey("type")) {
			type = (Integer) m.get("type");
			m.remove("type");
		}

		if (m.containsKey("timestamp")) {
			timestamp = (Date) m.get(m);
			m.remove("timestamp");
		}

		data.putAll(m);
	}

	public Object get(String string) {
		if (string.equals("_id")) {
//			return id == null ? null : id.toStringMongod();
			return id;
		}


		if (string.equals("type"))
			return type != -1 ? type : null;

		if (string.equals("timestamp"))
			return timestamp;

		return data.get(string);
	}

	public Map toMap() {
		Map map = new LinkedHashMap(data.toMap());

		if (id != null)
			map.put("_id", id);

		if (type != -1)
			map.put("type", type);

		if (timestamp != null)
			map.put("timestamp", DateFormat.getDateTimeInstance().format(timestamp));

		return map;
	}

	public Object removeField(String string) {
		if (string.equals("_id")) {
			ObjectId t = id;
			this.id = null;

			return t;
		} else if (string.equals("type")) {
			int t = this.type;
			this.type = -1;

			return t;
		} else if (string.equals("timestamp")) {
			Date t = timestamp;
			timestamp = null;

			return t;
		}

		return data.removeField(string);
	}

	public boolean containsKey(String string) {
//		throw new UnsupportedOperationException("Apparently deprecated");
		return containsField(string);
	}

	public boolean containsField(String string) {
		if (string.equals("_id"))
			return id != null;

		if (string.equals("type"))
			return type != -1;

		if (string.equals("timestamp"))
			return timestamp != null;

		return data.containsField(string);
	}

	public Set<String> keySet() {
		Set<String> set = new LinkedHashSet<String>(data.keySet());

		if (id != null)
			set.add("_id");

		if (type != -1)
			set.add("type");

		if (timestamp != null)
			set.add("timestamp");

		return set;
	}
}
