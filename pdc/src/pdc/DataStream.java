/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pdc;

import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.security.SignatureException;
import java.security.cert.CertificateEncodingException;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import pdc.exceptions.PDCNoResponseException;
import com.mongodb.BasicDBObject;
import com.mongodb.DBCollection;
import com.mongodb.DBCursor;
import com.mongodb.DBObject;
import com.mongodb.WriteConcern;
import com.mongodb.WriteResult;
import com.mongodb.util.JSON;
import java.io.IOException;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.cert.X509Certificate;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Timer;
import java.util.TimerTask;
import org.bson.types.ObjectId;
import org.ccnx.ccn.config.SystemConfiguration;
import org.ccnx.ccn.impl.security.crypto.util.MinimalCertificateGenerator;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.ContentObject;
import org.ccnx.ccn.protocol.KeyLocator;
import org.ccnx.ccn.protocol.PublisherID;
import pdc.util.Log;

/**
 *
 * @author Derek Kulinski
 */
public class DataStream {
	/**
	 * application associated with the DS
	 */
	final Application app;
	/**
	 * id of the data stream
	 */
	final String data_stream_id;
	/**
	 * key used for symmetric encryption
	 */
	byte[] key = null;
	/**
	 * id of last record in the database
	 */
	private String _last_entry = null;
	/**
	 * publisher of the DS
	 */
	private PDVNode _publisher = null;
	/**
	 * publisher data_stream name
	 */
	private String _publisher_data_stream_id;
	/**
	 * receivers of our DS
	 */
	private List<PDVNode> _receivers = new ArrayList<PDVNode>();
	private Timer pull_timer;
	final private DBCollection _coll;
	final private PDCConfigStore _config = PDCConfigStore.get_instance();
	final private PublisherControlCommands _replicator = PublisherControlCommands.get_instance();
	final private PublisherDataCommand _data_provider = PublisherDataCommand.get_instance();
	final private DataEncryptor _encryptor = new DataEncryptor();

//	KeyPair keys;
//	X509Certificate cert;
//	KeyLocator locator;
//	PublisherID publisher;
	
	DataStream(Application app, String data_stream_id)
	{
		assert app != null;
		assert data_stream_id != null && !data_stream_id.isEmpty();
		assert !data_stream_id.startsWith("/") : "stream id: " + data_stream_id;

		this.app = app;
		this.data_stream_id = data_stream_id;

		_coll = app.get_db_collection(data_stream_id);
		_coll.setObjectClass(DataRecord.class);
//		try {
//			KeyPairGenerator kpg = KeyPairGenerator.getInstance("RSA");
//			kpg.initialize(512);
//			Log.debug("Generating key pair");
//			keys = kpg.genKeyPair();
//
//			cert = MinimalCertificateGenerator.GenerateUserCertificate(keys,
//							"CN="+data_stream_id, MinimalCertificateGenerator.MSEC_IN_YEAR);
//
//			publisher = new PublisherID
//		}
//		catch (CertificateEncodingException ex) {
//			Logger.getLogger(DataStream.class.getName()).log(Level.SEVERE, null, ex);
//		}
//		catch (InvalidKeyException ex) {
//			Logger.getLogger(DataStream.class.getName()).log(Level.SEVERE, null, ex);
//		}
//		catch (IllegalStateException ex) {
//			Logger.getLogger(DataStream.class.getName()).log(Level.SEVERE, null, ex);
//		}
//		catch (SignatureException ex) {
//			Logger.getLogger(DataStream.class.getName()).log(Level.SEVERE, null, ex);
//		}		catch (NoSuchAlgorithmException ex) {
//			Logger.getLogger(DataStream.class.getName()).log(Level.SEVERE, null, ex);
//		}
	}

	PDVNode get_publisher()
	{
		return _publisher;
	}

	ContentName get_publisher_ds()
	{
		ContentName result = null;

		if (_publisher == null)
			return null;

		assert _publisher.uri != null;
		assert _publisher_data_stream_id != null;

		try {
			result = _publisher.uri.append(app.name).append(_publisher_data_stream_id);
		}
		catch (MalformedContentNameStringException ex) {
			throw new Error(String.format("Unable to create %s/%s/%s", _publisher.uri,
							app.name, _publisher_data_stream_id), ex);
		}

		return result;
	}

	void set_publisher(PDVNode node, String ds_id)
	{
		_publisher = node;
		_publisher_data_stream_id = ds_id;
	}

	synchronized void add_receiver(PDVNode node)
	{
		_receivers.add(node);
	}

	synchronized void del_receiver(PDVNode node)
	{
		_receivers.remove(node);
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

	synchronized private void updateLastEntry()
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
				Log.debug("Timer pull event!");
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

	void fetchDataFromUplink() throws PDCNoResponseException
	{
		PDVNode node;
		DataRecord record;
		Collection<String> ids;

		node = get_publisher();
		if (node == null) {
			Log.warning("No uplink defined; fetching aborted");
			return;
		}

		updateLastEntry();

		if (_last_entry == null)
			ids = callList();
		else
			ids = callList(_last_entry);

		Iterator<String> iter = ids.iterator();

		while (iter.hasNext()) {
			String data_id = iter.next();
			Log.debug("pulling: " + data_id);
			record = _data_provider.fetchRecord(this, data_id);
			Log.debug("got: " + JSON.serialize(record));
			insertRecord(record);
			_last_entry = record.id.toStringMongod();
		}
	}

	List<String> callList() throws PDCNoResponseException
	{
		return callList(null, null);
	}

	List<String> callList(String start)
					throws PDCNoResponseException
	{
		return callList(start, null);
	}

	List<String> callList(String start, String end) throws PDCNoResponseException
	{
		ContentName uri = null;
		ContentObject response;

		byte[] decoded;
		List<String> result = new LinkedList<String>();

		try {
			uri = get_publisher_ds().append("control").append("list");

			if (start != null) {
				uri = uri.append(start);
				if (end != null)
					uri = uri.append(end);
			} else
				assert end == null;
		}
		catch (MalformedContentNameStringException ex) {
			Log.error(String.format("Unable to create proper URI (%s, %s, %s, %s)",
							app.name, data_stream_id, start, end));
			throw new Error(ex);
		}

		Log.debug("Requesting: " + uri.toURIString());

		try {
			response = NDNetwork.ccn_handle.get(uri, SystemConfiguration.LONG_TIMEOUT);

			if (response == null)
				throw new PDCNoResponseException();

			//TODO: Check signature here
			decoded = _encryptor.decryptData(this, response.content());

			result = Arrays.asList(new String(decoded).split("\\\n"));

			return result;
		}
		catch (IOException ex) {
			Logger.getLogger(PublisherControlCommands.class.getName()).log(
							Level.SEVERE, null, ex);
		}

		return null;
	}
}
