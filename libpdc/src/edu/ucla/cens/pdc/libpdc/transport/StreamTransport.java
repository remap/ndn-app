/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc.transport;

import edu.ucla.cens.pdc.libpdc.Constants;
import edu.ucla.cens.pdc.libpdc.DataRecord;
import edu.ucla.cens.pdc.libpdc.DataStream;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCDatabaseException;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCEncryptionException;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCNoResponseException;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCTransmissionException;
import edu.ucla.cens.pdc.libpdc.util.Log;
import edu.ucla.cens.pdc.libpdc.util.StringUtil;
import java.io.IOException;
import java.util.Collection;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.config.SystemConfiguration;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.ContentObject;
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import org.ccnx.ccn.protocol.SignedInfo;

/**
 *
 * @author Derek Kulinski
 */
public class StreamTransport {
	final public ContentName base_name;

	final private DataStream _stream;

	final private CCNHandle _ccn_handle;

	public StreamTransport(CCNHandle handle, DataStream stream)
					throws PDCTransmissionException
	{
		assert handle != null;
		assert stream != null;

		this._ccn_handle = handle;
		this._stream = stream;

		try {
			this.base_name = _stream.app.getBaseName().append(_stream.data_stream_id);
		}
		catch (MalformedContentNameStringException ex) {
			throw new PDCTransmissionException(
							"Unable to create base name for the data stream", ex);
		}
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

			data = _stream.getEncryptor().encryptRecord(record);
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
					throws PDCDatabaseException, PDCEncryptionException, PDCTransmissionException
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

		cipher = _stream.getEncryptor().encryptData(data.getBytes());

		return publishData(interest, cipher, 1);
	}

	private boolean publishData(Interest interest, byte[] data, int freshness)
					throws PDCTransmissionException
	{
		SignedInfo si;
		ContentObject co;

		assert interest != null;
		assert data != null;

		try {
			si = new SignedInfo(_stream.getKeyDigest(), SignedInfo.ContentType.ENCR,
							_stream.getKeyLocator(), freshness, null);
			co = new ContentObject(interest.name(), si, data,
							_ccn_handle.keyManager().getDefaultSigningKey());

			_ccn_handle.put(co);

			return true;
		}
		catch (Exception ex) {
			throw new PDCTransmissionException("Error while publishing data", ex);
		}
	}

	DataRecord fetchRecord(String content_id)
					throws PDCTransmissionException, PDCNoResponseException,
					PDCEncryptionException
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
				throw new PDCNoResponseException();

			//TODO: Check signature

			record = _stream.getEncryptor().decryptRecord(response.content());

			return record;
		}
		catch (MalformedContentNameStringException ex) {
			throw new PDCTransmissionException(String.format(
							"Unable to create proper URI (%s, %s, %s)",
							publisher_ds, Constants.STR_COMMAND, content_id), ex);
		}
	}
}
