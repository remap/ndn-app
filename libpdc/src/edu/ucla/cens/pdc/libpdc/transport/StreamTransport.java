/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc.transport;

import com.mongodb.util.JSON;
import edu.ucla.cens.pdc.libpdc.Constants;
import edu.ucla.cens.pdc.libpdc.DataEncryptor;
import edu.ucla.cens.pdc.libpdc.DataRecord;
import edu.ucla.cens.pdc.libpdc.DataStream;
import edu.ucla.cens.pdc.libpdc.Storage;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCDatabaseException;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCEncryptionException;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCTransmissionException;
import edu.ucla.cens.pdc.libpdc.util.Log;
import edu.ucla.cens.pdc.libpdc.util.StringUtil;
import java.io.IOException;
import java.util.Arrays;
import java.util.Collection;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.config.SystemConfiguration;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.ContentObject;
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.protocol.KeyLocator;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import org.ccnx.ccn.protocol.PublisherPublicKeyDigest;
import org.ccnx.ccn.protocol.SignedInfo;

/**
 *
 * @author Derek Kulinski
 */
public class StreamTransport {
	final public ContentName base_name;

	final private DataStream _stream;

	final private DataEncryptor _encryptor;

	final private CCNHandle _ccn_handle;

	public StreamTransport(CCNHandle handle, DataStream stream)
					throws PDCTransmissionException
	{
		assert handle != null;
		assert stream != null;

		this._stream = stream;
		this._encryptor = new DataEncryptor();
		this._ccn_handle = handle;

		try {
			this.base_name = _stream.app.getBaseName().append(_stream.data_stream_id);
		}
		catch (MalformedContentNameStringException ex) {
			throw new PDCTransmissionException(
							"Unable to create base name for the data stream", ex);
		}
	}

	/**
	 * @return the _encryptor
	 */
	public DataEncryptor getEncryptor()
	{
		return _encryptor;
	}

	public PublisherPublicKeyDigest getKeyDigest()
	{
		//TODO: don't generate this every time
//		return new PublisherPublicKeyDigest(_stream_keys.getPublic());
//		return null;
		return _ccn_handle.getDefaultPublisher();
	}

	public KeyLocator getKeyLocator()
	{
//		//TODO: this is obviously wrong
//		KeyLocator locator = new KeyLocator(_stream_keys.getPublic());
//
//		return locator;
//		return null;
		return _ccn_handle.keyManager().getDefaultKeyLocator();
	}

	public boolean publishDataRecord(Interest interest, String data_id)
					throws PDCTransmissionException
	{
		DataRecord record;
		byte[] data;

		try {
			record = _stream.getStorage().getRecord(data_id);

			if (record == null) {
				Log.warning(data_id + " does not exist");
				return false;
			}

			data = _encryptor.encryptRecord(record);
			return publishData(interest, data, 1);
		}
		catch (PDCEncryptionException ex) {
			throw new PDCTransmissionException("Error encrypting the data", ex);
		}
		catch (PDCDatabaseException ex) {
			throw new PDCTransmissionException("Error accessing the database", ex);
		}
	}

	public boolean publishRecordList(Interest interest, ContentName arguments)
					throws PDCDatabaseException, PDCEncryptionException,
					PDCTransmissionException
	{
		Collection<String> ids;
		String data;
		byte[] cipher;

		assert interest != null;
		assert arguments != null;

		Log.debug("Got list request for: " + arguments.toURIString());

		// Content of the data packet
		if (arguments.count() == 0)
			ids = _stream.getStorage().getRangeIds();
		else if (arguments.count() == 1)
			ids = _stream.getStorage().getRangeIds(arguments.stringComponent(0));
		else
			ids = _stream.getStorage().getRangeIds(arguments.stringComponent(0),
							arguments.stringComponent(1));

		data = StringUtil.join(ids, "\n");

		cipher = _encryptor.encryptData(data.getBytes());

		return publishData(interest, cipher, 1);
	}

	public boolean publishACK(Interest interest)
					throws PDCTransmissionException
	{
		String answer = "ACK";

		return publishData(interest, answer.getBytes(), 1);
	}

	private boolean publishData(Interest interest, byte[] data, int freshness)
					throws PDCTransmissionException
	{
		SignedInfo si;
		ContentObject co;

		assert interest != null;
		assert data != null;

		try {
			si = new SignedInfo(getKeyDigest(), SignedInfo.ContentType.ENCR,
							getKeyLocator(), freshness, null);
			co = new ContentObject(interest.name(), si, data,
							_ccn_handle.keyManager().getDefaultSigningKey());

			_ccn_handle.put(co);

			return true;
		}
		catch (Exception ex) {
			throw new PDCTransmissionException("Error while publishing data", ex);
		}
	}

	public List<String> fetchList()
					throws PDCTransmissionException
	{
		return fetchList(null, null);
	}

	public List<String> fetchList(String start)
					throws PDCTransmissionException
	{
		return fetchList(start, null);
	}

	public List<String> fetchList(String start, String end)
					throws PDCTransmissionException
	{
		ContentName uri = null;
		ContentObject response;

		byte[] decoded;
		List<String> result;

		try {
			uri = _stream.getPublisherStreamURI().append(Constants.STR_CONTROL).append(
							"list");

			if (start != null) {
				uri = uri.append(start);
				if (end != null)
					uri = uri.append(end);
			} else if (end != null)
				throw new Error("Start is null, but end is not null???");
		}
		catch (MalformedContentNameStringException ex) {
			throw new Error(String.format(
							"Unable to create proper URI (%s, %s, %s, %s)", _stream.app.
							getAppName(), _stream.data_stream_id, start, end));
		}

		Log.debug("Requesting: " + uri.toURIString());

		try {
			response = _ccn_handle.get(uri, SystemConfiguration.LONG_TIMEOUT);
		}
		catch (IOException ex) {
			throw new PDCTransmissionException("Unable to get the data", ex);
		}

		if (response == null)
			return null;

		try {
			decoded = _encryptor.decryptData(response.content());
		}
		catch (PDCEncryptionException ex) {
			throw new PDCTransmissionException("Unable to decrypt the message", ex);
		}

		//Special case (empty list returned)
		if (decoded.length == 0)
			return new LinkedList<String>();

		result = Arrays.asList(new String(decoded).split("\\\n"));

		return result;
	}

	public DataRecord fetchRecord(String content_id)
					throws PDCTransmissionException
	{
		DataRecord record;
		ContentName publisher_ds, data_uri;
		ContentObject response;

		assert content_id != null;

		publisher_ds = _stream.getPublisherStreamURI();

		try {
			data_uri = _stream.getPublisherStreamURI().append(Constants.STR_DATA).
							append(content_id);

			try {
				response = _ccn_handle.get(data_uri, SystemConfiguration.LONG_TIMEOUT);
			}
			catch (IOException ex) {
				throw new PDCTransmissionException("Unable to fetch the data", ex);
			}

			if (response == null)
				return null;

			try {
				record = _encryptor.decryptRecord(response.content());
			}
			catch (PDCEncryptionException ex) {
				throw new PDCTransmissionException("Unable to decrypt message", ex);
			}

			return record;
		}
		catch (MalformedContentNameStringException ex) {
			throw new PDCTransmissionException(String.format(
							"Unable to create proper URI (%s, %s, %s)",
							publisher_ds, Constants.STR_CONTROL, content_id), ex);
		}
	}

	public boolean fetchDataFromUplink()
					throws PDCTransmissionException
	{
		PDCPublisher publisher;
		String last_entry;
		DataRecord record;
		Collection<String> ids;
		Storage storage;

		storage = _stream.getStorage();

		publisher = _stream.getPublisher();
		if (publisher == null) {
			Log.warning("No uplink defined; fetching aborted");
			return true;
		}
		try {
			last_entry = storage.getLastEntry();
		}
		catch (PDCDatabaseException ex) {
			throw new PDCTransmissionException(
							"Unable to fetch id of last record from the database", ex);
		}

		if (last_entry == null)
			ids = fetchList();
		else
			ids = fetchList(last_entry);

		if (ids == null) {
			Log.warning("No response when fetching ids");
			return false;
		}

		if (ids.isEmpty()) {
			Log.info("No more records to pull");
			return true;
		}

		Iterator<String> iter = ids.iterator();

		try {
			while (iter.hasNext()) {
				String data_id = iter.next();

				Log.debug("pulling: " + data_id);
				record = fetchRecord(data_id);
				if (record == null) {
					Log.warning("No response when fetching record " + data_id);
					return false;
				}

				Log.debug("got: " + JSON.serialize(record));
				storage.insertRecord(record);
			}
		}
		catch (PDCDatabaseException ex) {
			throw new Error("Unable to insert entry to the database", ex);
		}

		return true;
	}
}
