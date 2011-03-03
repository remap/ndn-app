/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc;

import edu.ucla.cens.pdc.libpdc.Constants;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCTransmissionException;
import java.io.IOException;
import java.security.InvalidKeyException;
import java.security.SignatureException;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.ContentObject;
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import org.ccnx.ccn.protocol.SignedInfo;
import edu.ucla.cens.pdc.libpdc.DataStream;
import edu.ucla.cens.pdc.libpdc.util.Log;
import edu.ucla.cens.pdc.libpdc.util.StringUtil;

/**
 *
 * @author Derek Kulinski
 */
public class PublisherControlCommands extends PublisherCommand {
	private static PublisherControlCommands _instance = null;

	private final int FRESHNESS = 1;

	private PublisherControlCommands(CCNHandle handle)
					throws MalformedContentNameStringException
	{
		super(handle, Constants.STR_CONTROL);
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
			stream.getTransport().fetchDataFromUplink();

			return true;
		}
		catch (PDCTransmissionException ex) {
			throw new RuntimeException("Error while trying to fetch data", ex);
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
				return ds.getTransport().publishRecordList(interest, postfix.subname(
								1, postfix.count() - 1));
			else {
				ContentObject co = ContentObject.buildContentObject(interest.name(),
								"invalid request!".getBytes());
				_ccn_handle.put(co);

				return true;
			}
		}
		catch (Exception ex) {
			Log.error("Got problem: " + ex);
			ex.printStackTrace();
		}


		return false;
	}
}
