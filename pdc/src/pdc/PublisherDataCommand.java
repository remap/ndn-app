/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pdc;

import com.mongodb.util.JSON;
import pdc.exceptions.PDCNoResponseException;
import java.io.IOException;
import java.security.InvalidKeyException;
import java.security.SignatureException;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.bson.BSONDecoder;
import org.bson.BSONEncoder;
import org.bson.BSONObject;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.config.SystemConfiguration;
import org.ccnx.ccn.io.CCNOutputStream;
import org.ccnx.ccn.io.CCNVersionedOutputStream;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.ContentObject;
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import org.ccnx.ccn.protocol.SignedInfo;
import pdc.exceptions.PDCException;
import pdc.util.Log;

/**
 *
 * @author Derek Kulinski
 */
public class PublisherDataCommand extends PublisherCommand {
	private static PublisherDataCommand _instance = null;
	private final int FRESHNESS = 5;
	private DataEncryptor _encryptor;
	private PDCConfigStore _config = PDCConfigStore.get_instance();

	private PublisherDataCommand(CCNHandle handle)
					throws MalformedContentNameStringException
	{
		super(handle, "data");

		this._encryptor = new DataEncryptor();
	}

	static PublisherDataCommand get_instance()
	{
		assert _instance != null;
		return _instance;
	}

	static PublisherDataCommand get_instance(CCNHandle handle)
					throws MalformedContentNameStringException
	{
		if (_instance == null)
			_instance = new PublisherDataCommand(handle);

		return _instance;
	}

	@Override
	boolean processCommand(DataStream datastream, ContentName postfix,
					Interest interest)
	{
		BSONEncoder encoder = new BSONEncoder();
		String record_id;
		DataRecord record;
		SignedInfo si;
		byte[] cipher;
		ContentObject co;
		CCNOutputStream os;

		if (postfix.count() != 1)
			return false;

		record_id = postfix.stringComponent(0);

		Log.debug(String.format(
						"Requested; app = %s, datastream = %s, record_id = %s",
						datastream.app.name, datastream.data_stream_id, record_id));

		record = datastream.getRecord(record_id);
		if (record == null)
			return false;

		si = new SignedInfo(_publisher, SignedInfo.ContentType.ENCR,
						_locator, FRESHNESS, null);

		try {
			cipher = _encryptor.encryptData(datastream, encoder.encode(record));
//			cipher = _encryptor.encryptData(datastream,
//							JSON.serialize(record).getBytes());
			co = new ContentObject(interest.name(), si, cipher, _signing_key);
			_ccn_handle.put(co);

			return true;
		}
		catch (PDCException ex) {
			throw new Error(ex);
		}
		catch (IOException ex) {
			Logger.getLogger(PublisherDataCommand.class.getName()).log(Level.SEVERE,
							null,
							ex);
		}
		catch (InvalidKeyException ex) {
			Logger.getLogger(PublisherDataCommand.class.getName()).log(Level.SEVERE,
							null,
							ex);
		}
		catch (SignatureException ex) {
			Logger.getLogger(PublisherDataCommand.class.getName()).log(Level.SEVERE,
							null,
							ex);
		}

		return false;
	}

	DataRecord fetchRecord(DataStream datastream, String content_id)
					throws PDCNoResponseException
	{
		BSONDecoder decoder = new BSONDecoder();
		ContentName publisher_ds, uri;
		ContentObject response;
		byte[] decrypted;
		BSONObject content;

		assert datastream != null;
		assert content_id != null;

		publisher_ds = datastream.get_publisher_ds();
		try {
			uri = publisher_ds.append(COMMAND).append(content_id);
		}
		catch (MalformedContentNameStringException ex) {
			Log.error(String.format("Unable to create proper URI (%s, %s, %s)",
							publisher_ds, COMMAND, content_id));
			throw new Error(ex);
		}

		try {
			response = _ccn_handle.get(uri, SystemConfiguration.LONG_TIMEOUT);
			if (response == null)
				throw new PDCNoResponseException();

			//TODO: Check signature

			decrypted = _encryptor.decryptData(datastream, response.content());
			content = decoder.readObject(decrypted);
			DataRecord record = new DataRecord(content.toMap());

			return record;
		}
		catch (IOException ex) {
			Logger.getLogger(PublisherDataCommand.class.getName()).log(Level.SEVERE,
							null, ex);
		}

		return null;
	}
}
