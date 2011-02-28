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
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
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
	@SuppressWarnings("rawtypes")
	private DataStream _stream;

	private CCNHandle _ccn_handle;

	private ContentName _base_name;

	public StreamTransport(CCNHandle handle, DataStream stream)
	{
		assert handle != null;
		assert stream != null;

		this._ccn_handle = handle;
		this._stream = stream;
	}

	public boolean publishDataRecord(Interest interest, String data_id)
					throws PDCTransmissionException
	{
		DataRecord record;
		byte[] data;

		try {
			record = _stream.getStorage().getRecord(data_id);

			if (record == null)
				throw new PDCTransmissionException(data_id + " does not exist");

			data = _stream.getEncryptor().encryptData(record);
			return publishData(interest, data);
		}
		catch (PDCEncryptionException ex) {
			throw new PDCTransmissionException("Error encrypting the data", ex);
		}
		catch (PDCDatabaseException ex) {
			throw new PDCTransmissionException("Error accessing the database", ex);
		}
	}

	private boolean publishData(Interest interest, byte[] data)
					throws PDCTransmissionException
	{
		SignedInfo si;
		ContentObject co;

		assert interest != null;
		assert data != null;

		try {
			si = new SignedInfo(_stream.getKeyDigest(), SignedInfo.ContentType.ENCR,
							_stream.getKeyLocator(), 1, null);
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
				response = _ccn_handle.get(data_uri,
								SystemConfiguration.LONG_TIMEOUT);
			}
			catch (IOException ex) {
				throw new PDCTransmissionException("Unable to fetch the data", ex);
			}

			if (response == null)
				throw new PDCNoResponseException();

			//TODO: Check signature

			record = _stream.getEncryptor().decryptData(response.content());

			return record;
		}
		catch (MalformedContentNameStringException ex) {
			throw new PDCTransmissionException(String.format(
							"Unable to create proper URI (%s, %s, %s)",
							publisher_ds, Constants.STR_COMMAND, content_id), ex);
		}
	}
}
