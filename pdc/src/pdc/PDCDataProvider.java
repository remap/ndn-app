/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pdc;

import com.mongodb.DBCollection;
import com.mongodb.DBObject;
import com.mongodb.util.JSON;
import java.io.IOException;
import java.security.InvalidKeyException;
import java.security.SignatureException;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.bson.BSONEncoder;
import org.bson.BSONObject;
import org.bson.types.ObjectId;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.ContentObject;
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import org.ccnx.ccn.protocol.SignedInfo;
import pdc.util.Log;

/**
 *
 * @author takeda
 */
class PDCDataProvider extends PDCCommand {

	private static PDCDataProvider _instance = null;
	private final int FRESHNESS = 5;
	private DataEncryptor _encryptor;
	private PDCConfigStore _config = PDCConfigStore.get_instance();

	private PDCDataProvider(CCNHandle handle)
					throws MalformedContentNameStringException
	{
		super(handle, "share");

		this._encryptor = new DataEncryptor();
	}

	static PDCDataProvider get_instance()
	{
		assert _instance != null;
		return _instance;
	}

	static PDCDataProvider get_instance(CCNHandle handle)
					throws MalformedContentNameStringException
	{
		if (_instance == null)
			_instance = new PDCDataProvider(handle);

		return _instance;
	}

	@Override
	boolean processCommand(Application app, ContentName postfix, Interest interest)
	{
		if (postfix.count() != 2)
			return false;

		String datastream = postfix.stringComponent(0);
		String record_id = postfix.stringComponent(1);

		Log.debug("Requested; app = " + app.name + " datastream = " + datastream
						+ ", record_id = " + record_id + "\n");

		if (!app.data_stream_exists(datastream)) {
			Log.debug("Unknown data stream");
			return false;
		}

		DataRecord record = getRecord(app, datastream, record_id);
		if (record == null)
			return false;

		SignedInfo si = new SignedInfo(_publisher, SignedInfo.ContentType.ENCR,
						_locator, FRESHNESS, null);

		byte[] cipher = _encryptor.encryptData(app, datastream, JSON.serialize(
						record).getBytes());

//		BSONEncoder encoder = new BSONEncoder();
//		byte[] cipher = _encryptor.encryptData(app, acl, encoder.encode(record));

		ContentObject co;
		try {
			co = new ContentObject(interest.name(), si, cipher, _signing_key);
			_ccn_handle.put(co);

			return true;
		} catch (IOException ex) {
			Logger.getLogger(PDCDataProvider.class.getName()).log(Level.SEVERE, null,
							ex);
		} catch (InvalidKeyException ex) {
			Logger.getLogger(PDCDataProvider.class.getName()).log(Level.SEVERE, null,
							ex);
		} catch (SignatureException ex) {
			Logger.getLogger(PDCDataProvider.class.getName()).log(Level.SEVERE, null,
							ex);
		}

		return false;
	}

	private DataRecord getRecord(Application app, String datastream,
					String record_id)
	{
		Database datastore = new Database(Database.db_type.DATA, app.name);
		DBCollection coll = datastore.getDatabase().getCollection(datastream);
		coll.setObjectClass(DataRecord.class);

		DataRecord record = (DataRecord) coll.findOne(new ObjectId(record_id));
		if (record == null) {
			Log.error("Object " + record_id + " doesn't exist");
			return null;
		}

		Log.debug(JSON.serialize(record));

		return record;
	}
}
