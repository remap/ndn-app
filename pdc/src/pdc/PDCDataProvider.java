/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pdc;

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
public class PDCDataProvider extends PDCCommand {
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
		BSONEncoder encoder = new BSONEncoder();
		String datastream_id, record_id;
		DataStream datastream;
		DataRecord record;
		SignedInfo si;
		byte[] cipher;
		ContentObject co;

		if (postfix.count() != 2)
			return false;

		datastream_id = postfix.stringComponent(0);
		record_id = postfix.stringComponent(1);

		Log.debug("Requested; app = " + app.name + " datastream = " + datastream_id
						+ ", record_id = " + record_id);

		datastream = app.data_stream_get(datastream_id);
		if (datastream == null) {
			Log.debug("Unknown data stream");
			return false;
		}

		record = datastream.getRecord(record_id);
		if (record == null)
			return false;

		si = new SignedInfo(_publisher, SignedInfo.ContentType.ENCR,
						_locator, FRESHNESS, null);

		try {
			cipher = _encryptor.encryptData(datastream, encoder.encode(record));
//		cipher = _encryptor.encryptData(app, datastream_id, JSON.serialize(record).getBytes());
			co = new ContentObject(interest.name(), si, cipher, _signing_key);
			_ccn_handle.put(co);

			return true;
		}
		catch (PDCException ex) {
			throw new Error(ex);
		}
		catch (IOException ex) {
			Logger.getLogger(PDCDataProvider.class.getName()).log(Level.SEVERE, null,
							ex);
		}
		catch (InvalidKeyException ex) {
			Logger.getLogger(PDCDataProvider.class.getName()).log(Level.SEVERE, null,
							ex);
		}
		catch (SignatureException ex) {
			Logger.getLogger(PDCDataProvider.class.getName()).log(Level.SEVERE, null,
							ex);
		}

		return false;
	}

	DataRecord fetchRecord(ContentName pdv, Application app, String stream,
					String content_id)
					throws PDCNoResponseException
	{
		BSONDecoder decoder = new BSONDecoder();
		ContentName uri;
		ContentObject response;
		byte[] decrypted;
		BSONObject content;

		assert pdv != null;
		assert app != null;
		assert stream != null;
		assert content_id != null;

		try {
			uri = pdv.append(app.name).append(COMMAND).
							append(stream).append(content_id);
		}
		catch (MalformedContentNameStringException ex) {
			Log.error(String.format("Unable to create proper URI (%s, %s, %s, %s)",
							app.name, COMMAND, stream, content_id));
			throw new Error(ex);
		}

		try {
			response = _ccn_handle.get(uri, SystemConfiguration.LONG_TIMEOUT);
			if (response == null)
				throw new PDCNoResponseException();

			//TODO: Check signature

			decrypted = _encryptor.decryptData(app, stream, response.content());
			content = decoder.readObject(decrypted);
			DataRecord record = new DataRecord(content.toMap());

			return record;
		}
		catch (IOException ex) {
			Logger.getLogger(PDCDataProvider.class.getName()).log(Level.SEVERE, null,
							ex);
		}

		return null;
	}
}
