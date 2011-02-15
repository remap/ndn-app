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
public class PublisherControlCommands extends PublisherCommand {
	private static PublisherControlCommands _instance = null;
	private final int FRESHNESS = 1;
	private DataEncryptor _encryptor;

	private PublisherControlCommands(CCNHandle handle)
					throws MalformedContentNameStringException
	{
		super(handle, "control");

		_encryptor = new DataEncryptor();
	}

	static PublisherControlCommands get_instance()
	{
		assert _instance != null;
		return _instance;
	}

	static PublisherControlCommands get_instance(CCNHandle handle)
					throws MalformedContentNameStringException
	{
		if (_instance == null)
			_instance = new PublisherControlCommands(handle);

		return _instance;
	}

	private boolean handlePush(Interest interest, DataStream stream,
					ContentName name)
	{
		String[] args;
		SignedInfo si;
		ContentObject co;

		Log.debug("Got push request for: " + name.toURIString());

		if (name.count() < 1)
			return false;

		//<data stream>[|<last entry>]
		args = StringUtil.stripPrefixChar(name.toString(), "/").split("%7C");

		if (args.length < 1 || args.length > 2)
			return false;

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

	private boolean handleList(Interest interest, DataStream datastream,
					ContentName name)
					throws InvalidKeyException, SignatureException, IOException
	{
		Collection<String> ids;
		String data;
		SignedInfo si;

		byte[] cipher;
		ContentObject co;

		assert interest != null;
		assert datastream != null;
		assert name != null;

		Log.debug("Got list request for: " + name.toURIString());

		// Content of the data packet
		if (name.count() == 0)
			ids = datastream.getRangeIds();
		else if (name.count() == 1)
			ids = datastream.getRangeIds(name.stringComponent(0));
		else
			ids = datastream.getRangeIds(name.stringComponent(0), name.stringComponent(
							1));

		data = StringUtil.join(ids, "\n");

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
	boolean processCommand(DataStream ds, ContentName postfix, Interest interest)
	{
		Log.debug("Got replication interest for: " + postfix.toURIString());

		if (postfix.count() == 0) {
			Log.error("No subcommand!");

			return false;
		}

		String command = postfix.stringComponent(0);

		try {
			if (command.matches("push"))
				return handlePush(interest, ds, postfix.subname(1, postfix.count() - 1));
			else if (command.matches("list"))
				return handleList(interest, ds, postfix.subname(1, postfix.count() - 1));
			else {
				ContentObject co = ContentObject.buildContentObject(interest.name(),
								"invalid request!".getBytes());
				_ccn_handle.put(co);

				return true;
			}
		}
		catch (InvalidKeyException ex) {
			Logger.getLogger(PublisherControlCommands.class.getName()).log(
							Level.SEVERE, null, ex);
		}
		catch (SignatureException ex) {
			Logger.getLogger(PublisherControlCommands.class.getName()).log(
							Level.SEVERE, null, ex);
		}
		catch (IOException ex) {
			Logger.getLogger(PublisherControlCommands.class.getName()).log(
							Level.SEVERE, null, ex);
		}

		return false;
	}
}
