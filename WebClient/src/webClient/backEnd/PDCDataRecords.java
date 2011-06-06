package webClient.backEnd;

import edu.ucla.cens.pdc.libpdc.datastructures.DataRecord;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCEncryptionException;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCParseException;
import edu.ucla.cens.pdc.libpdc.transport.CollectionTransport;
import java.io.IOException;
import java.util.Arrays;
import java.util.Collection;
import java.util.List;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.ContentObject;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import webClient.exceptions.NoSuchUserHashException;
import webClient.frontEnd.WebClientServer;
import webClient.log.Log;
import webClient.session.Session;
import webClient.session.SessionManager;

/**
 * This class grabs data records in a data stream from the PDC.
 * @author Alexander Bonomo
 */
public class PDCDataRecords {
	private CCNHandle _ccnHandle;

	public PDCDataRecords()
	{
		//get a handle and a content name
		this._ccnHandle = CCNHandle.getHandle();
	}

	/**
	 * This function grabs the data records from a specified stream.
	 *
	 * @param userHash - session identifying user hash vaule
	 * @return - a collection of data records
	 * @throws IOException
	 * @throws MalformedContentNameStringException
	 */
	public Collection<String> getDataRecordList(String userHash)
			throws IOException, MalformedContentNameStringException,
			NoSuchUserHashException, PDCEncryptionException
	{
		Session session = SessionManager.getSession(userHash);
		if (session == null)
			throw new NoSuchUserHashException();

		//get necessary information to grab record list
		String pdv_uri = session.getPDV_URI();
		String appName = session.getCurrentApp();
		String dsName = session.getCurrentDataStream();

		Log.write("Retrieving list of data records.");

		ContentObject coDataRecords = this._ccnHandle.get(ContentName.fromURI(pdv_uri
				+ PDCCommands.DATA_RECORD_LIST + "/" + appName + "/" + dsName),
				WebClientServer.DEFAULT_TIMEOUT / 2);

		if (coDataRecords == null)
			return null;

		//decrypt and verify data
		if (!coDataRecords.validate())
			return null;
		byte[] data = session.decryptData(coDataRecords.content());
		CollectionTransport<String> ctRecords = new CollectionTransport<String>();
		ctRecords.fromBSON(data);

		return ctRecords.toCollection();
	}

	/**
	 * Retrieve the specified data stream
	 * @param userHash
	 * @param dataRecord
	 * @return
	 * @throws IOException
	 * @throws MalformedContentNameStringException
	 * @throws PDCParseException
	 */
	public DataRecord getDataRecord(String userHash, String dataRecord)
			throws IOException, MalformedContentNameStringException, PDCParseException,
			PDCEncryptionException
	{
		Session session = SessionManager.getSession(userHash);
		String pdv_uri = session.getPDV_URI();
		String dsName = session.getCurrentDataStream();
		String appName = session.getCurrentApp();

		//SignedInterest interest = session.getSignedInterest(ContentName.fromURI(pdv_uri
		//        + "/" + dsName + "/data/" + dataRecord);

		Log.write("Retrieving data record " + dataRecord);

		//the data command postfix: <stream_id>/data/<data_id>
		ContentObject coRecord = this._ccnHandle.get(ContentName.fromURI(pdv_uri
				+ PDCCommands.DATA_RECORD_CONTENT + "/" + appName + "/" + dsName
				+ "/" + dataRecord), WebClientServer.DEFAULT_TIMEOUT);

		//decrypt bytes
		byte[] content = session.decryptData(coRecord.content());

		DataRecord theRecord = new DataRecord();
		theRecord.fromBSON(coRecord.content());
		return theRecord;
	}
}
