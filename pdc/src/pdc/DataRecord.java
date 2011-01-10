/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pdc;

import com.mongodb.BasicDBObject;
import com.mongodb.DBObject;
import java.text.*;
import java.util.*;
import org.bson.BSONObject;
import org.bson.types.ObjectId;

/**
 * Single data record stored in the database
 * @author Derek Kulinski
 */
public final class DataRecord implements DBObject {
	private boolean _isPartialObject = false;
	ObjectId id;
	Date timestamp = null;
	String imei;
	Double latitude;
	Double longitude;
	DBObject data = new BasicDBObject();

	public DataRecord()
	{
	}

	public DataRecord(String id)
	{
		this.id = new ObjectId(id);
	}

	public DataRecord(Date ts)
	{
		this.timestamp = ts;
	}

	public DataRecord(Map data)
	{
		this.putAll(data);
	}

	public void markAsPartialObject()
	{
		_isPartialObject = true;
	}

	public boolean isPartialObject()
	{
		return _isPartialObject;
	}

	public Object put(String string, Object o)
	{
		if (string.equals("_id")) {
			id = (ObjectId) o;

			return id;
		} else if (string.equals("timestamp")) {
			timestamp = (Date) o;

			return timestamp;
		} else if (string.equals("imei")) {
			imei = (String) o;

			return imei;
		} else if (string.equals("latitude")) {
			latitude = (Double) o;

			return latitude;
		} else if (string.equals("longitude")) {
			longitude = (Double) o;

			return longitude;
		}

		return data.put(string, o);
	}

	private void putAllValue(Map m, final String key)
	{
		if (m.containsKey(key)) {
			put(key, m.get(key));
			m.remove(key);
		}
	}

	public void putAll(BSONObject bsono)
	{
		putAll(bsono.toMap());
	}

	public void putAll(Map map)
	{
		Map m = new LinkedHashMap(map);

		putAllValue(m, "_id");
		putAllValue(m, "timestamp");
		putAllValue(m, "imei");
		putAllValue(m, "latitude");
		putAllValue(m, "longitude");

		data.putAll(m);
	}

	public Object get(String string)
	{
		if (string.equals("_id"))
			return id;

		if (string.equals("timestamp"))
			return timestamp;

		if (string.equals("imei"))
			return imei;

		if (string.equals("latitude"))
			return latitude;

		if (string.equals("longitude"))
			return longitude;

		return data.get(string);
	}

	public Map toMap()
	{
		Map map = new LinkedHashMap(data.toMap());

		if (id != null)
			map.put("_id", id);

		if (timestamp != null)
//			map.put("timestamp", DateFormat.getDateTimeInstance().format(timestamp));
			map.put("timestamp", timestamp);

		if (imei != null)
			map.put("imei", imei);

		if (latitude != null)
			map.put("latitude", latitude);

		if (longitude != null)
			map.put("longitude", longitude);

		return map;
	}

	public Object removeField(String string)
	{
		if (string.equals("_id")) {
			ObjectId t = id;
			this.id = null;

			return t;
		} else if (string.equals("timestamp")) {
			Date t = timestamp;
			timestamp = null;

			return t;
		} else if (string.equals("imei")) {
			String t = imei;
			imei = null;

			return t;
		} else if (string.equals("latitude")) {
			Double t = latitude;
			latitude = null;

			return t;
		} else if (string.equals("longitude")) {
			Double t = longitude;
			longitude = null;

			return t;
		}

		return data.removeField(string);
	}

	public boolean containsKey(String string)
	{
//		throw new UnsupportedOperationException("Apparently deprecated");
		return containsField(string);
	}

	public boolean containsField(String string)
	{
		if (string.equals("_id"))
			return id != null;

		if (string.equals("timestamp"))
			return timestamp != null;

		if (string.equals("imei"))
			return imei != null;

		if (string.equals("latitude"))
			return latitude != null;

		if (string.equals("longitude"))
			return longitude != null;

		return data.containsField(string);
	}

	public Set<String> keySet()
	{
		Set<String> set = new LinkedHashSet<String>(data.keySet());

		if (id != null)
			set.add("_id");

		if (timestamp != null)
			set.add("timestamp");

		if (imei != null)
			set.add("imei");

		if (latitude != null)
			set.add("latitude");

		if (longitude != null)
			set.add("longitude");

		return set;
	}
}
