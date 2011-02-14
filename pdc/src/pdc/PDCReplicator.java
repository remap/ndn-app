/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pdc;

import pdc.exceptions.PDCNoResponseException;
import java.io.IOException;
import java.security.InvalidKeyException;
import java.security.SignatureException;
import java.util.Arrays;
import java.util.Collection;
import java.util.LinkedList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.config.SystemConfiguration;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.ContentObject;
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import org.ccnx.ccn.protocol.SignedInfo;
import pdc.exceptions.PDCException;
import pdc.util.Log;
import pdc.util.StringUtil;

/**
 *
 * @author Derek Kulinski
 */
public class PDCReplicator extends PDCCommand {
	private static PDCReplicator _instance = null;
	private final int FRESHNESS = 1;
	private DataEncryptor _encryptor;
	private PDCConfigStore _config = PDCConfigStore.get_instance();

	private PDCReplicator(CCNHandle handle)
					throws MalformedContentNameStringException
	{
		super(handle, "replicate");

		_encryptor = new DataEncryptor();
	}

	static PDCReplicator get_instance()
	{
		assert _instance != null;
		return _instance;
	}

	static PDCReplicator get_instance(CCNHandle handle)
					throws MalformedContentNameStringException
	{
		if (_instance == null)
			_instance = new PDCReplicator(handle);

		return _instance;
	}

	private boolean handlePush(Interest interest, Application app,
					ContentName name)
	{
		String[] args;
		DataStream stream;
		SignedInfo si;
		ContentObject co;

		Log.debug("Got push request for: " + name.toURIString());

		if (name.count() < 1)
			return false;

		//<data stream>[|<last entry>]
		args = StringUtil.stripPrefixChar(name.toString(), "/").split("%7C");

		if (args.length < 1 || args.length > 2)
			return false;

		stream = app.data_stream_get(args[0]);
		if (stream == null) {
			Log.info("Stream " + args[0] + " doesn't exist.");
			return false;
		}

		si = new SignedInfo(_publisher, SignedInfo.ContentType.GONE, _locator,
						1, null);

		try {
			co = new ContentObject(interest.name(), si, null, _signing_key);
			_ccn_handle.put(co);

			//TODO: handle situation when argument is given
			stream.fetchDataFromUplink();

			return true;
		}
		catch (InvalidKeyException ex) {
			throw new RuntimeException("Unable to sign content object", ex);
		}
		catch (SignatureException ex) {
			throw new RuntimeException("Unable to sign content object", ex);
		}
		catch (IOException ex) {
			throw new RuntimeException("Unable to send response", ex);
		}
		catch (PDCNoResponseException ex) {
			Log.error("Uplink didin't respond");
		}

		return false;
	}

	private boolean handlePull(Interest interest, Application app,
					ContentName name)
					throws InvalidKeyException, SignatureException, IOException
	{

		String[] args;
		DataStream datastream;
		Collection<String> ids;
		ContentName uri;
		String data;
		SignedInfo si;

		byte[] cipher;
		ContentObject co;

		Log.debug("Got pull request for: " + name.toURIString());

		if (name.count() < 1)
			return false;

		args = StringUtil.stripPrefixChar(name.toString(), "/").split("%7C");

		if (args.length < 1 || args.length > 3)
			return false;

		uri = interest.name().subname(0, interest.name().count() - 3);

		datastream = app.data_stream_get(args[0]);

		if (datastream == null) {
			Log.info("Unknown stream: " + args[0]);

			return false;
		} // Content of the data packet
		if (args.length == 1)
			ids = datastream.getRangeIds();
		else if (args.length == 2)
			ids = datastream.getRangeIds(args[1]);
		else
			ids = datastream.getRangeIds(args[1], args[2]);

		data = uri + "\n" + StringUtil.join(ids, "\n");

		si = new SignedInfo(_publisher, SignedInfo.ContentType.ENCR, _locator,
						FRESHNESS, null);

		try {
			cipher = _encryptor.encryptData(datastream, data.getBytes());
			co = new ContentObject(interest.name(), si, cipher, _signing_key);
			_ccn_handle.put(co);
		}
		catch (PDCException ex) {
			throw new Error("Unable to encrypt data", ex);
		}

		return true;
	}

	@Override
	boolean processCommand(Application app, ContentName postfix, Interest interest)
	{
		Log.debug("Got replication interest for: " + postfix.toURIString());

		if (postfix.count() == 0) {
			Log.error("No subcommand!");

			return false;
		}

		String command = postfix.stringComponent(0);

		try {
			if (command.matches("push"))
				return handlePush(interest, app, postfix.subname(1, postfix.count() - 1));
			else if (command.matches("pull"))
				return handlePull(interest, app, postfix.subname(1, postfix.count() - 1));
			else {
				ContentObject co = ContentObject.buildContentObject(interest.name(),
								"invalid request!".getBytes());
				_ccn_handle.put(co);

				return true;
			}
		}
		catch (InvalidKeyException ex) {
			Logger.getLogger(PDCReplicator.class.getName()).log(Level.SEVERE, null, ex);
		}
		catch (SignatureException ex) {
			Logger.getLogger(PDCReplicator.class.getName()).log(Level.SEVERE, null, ex);
		}
		catch (IOException ex) {
			Logger.getLogger(PDCReplicator.class.getName()).log(Level.SEVERE, null, ex);
		}

		return false;
	}

	List<String> callPull(ContentName pdv, DataStream stream)
					throws PDCNoResponseException
	{
		return callPull(pdv, stream, null, null);
	}

	List<String> callPull(ContentName pdv, DataStream stream, String start)
					throws PDCNoResponseException
	{
		return callPull(pdv, stream, start, null);
	}

	List<String> callPull(ContentName pdv, DataStream data_stream, String start,
					String end)
					throws PDCNoResponseException
	{
		ContentName uri = null;
		ContentObject response;

		byte[] decoded;
		List<String> result = new LinkedList<String>();

		assert pdv != null;
		assert data_stream != null;

		try {
			uri = pdv.append(data_stream.app._name).append(COMMAND).append("pull");

			if (start == null)
				uri = uri.append(String.format("%s",
								data_stream.data_stream_id));
			else if (end == null)
				uri = uri.append(String.format("%s|%s",
								data_stream.data_stream_id, start));
			else
				uri = uri.append(String.format("%s|%s|%s",
								data_stream.data_stream_id, start, end));
		}
		catch (MalformedContentNameStringException ex) {
			Log.error(String.format("Unable to create proper URI (%s, %s, %s, %s, %s)",
							data_stream.app._name, COMMAND, data_stream.data_stream_id, start,
							end));
			throw new Error(ex);
		}

		try {
			response = _ccn_handle.get(uri, SystemConfiguration.LONG_TIMEOUT);

			if (response == null)
				throw new PDCNoResponseException();

			//TODO: Check signature here
			decoded = _encryptor.decryptData(data_stream, response.content());

			result = Arrays.asList(new String(decoded).split("\\\n"));

			return result;
		}
		catch (IOException ex) {
			Logger.getLogger(PDCReplicator.class.getName()).log(Level.SEVERE, null, ex);
		}

		return null;
	}
}
