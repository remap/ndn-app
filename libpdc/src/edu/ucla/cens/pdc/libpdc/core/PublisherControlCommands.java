/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc.core;

import edu.ucla.cens.pdc.libpdc.Authenticator;
import edu.ucla.cens.pdc.libpdc.Constants;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCEncryptionException;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCException;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCTransmissionException;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import edu.ucla.cens.pdc.libpdc.stream.DataStream;
import edu.ucla.cens.pdc.libpdc.StreamInfo;
import edu.ucla.cens.pdc.libpdc.transport.CommunicationHelper;
import edu.ucla.cens.pdc.libpdc.transport.PDCReceiver;
import edu.ucla.cens.pdc.libpdc.util.Log;
import org.ccnx.ccn.CCNHandle;

/**
 *
 * @author Derek Kulinski
 */
public class PublisherControlCommands extends StreamCommand {
	PublisherControlCommands()
					throws MalformedContentNameStringException
	{
		super(Constants.STR_CONTROL);
	}

	boolean processAuthenticator(DataStream ds, ContentName receiver_uri,
					Interest interest)
	{
		CCNHandle handle = CCNHandle.getHandle(); //XXX: remove this
		PDCReceiver receiver;
		Authenticator auth;
		byte[] encrypted;

		receiver = ds.name2receiver(receiver_uri);
		if (receiver == null) {
			Log.info("Interest for authenticator for unknown " + receiver_uri.
							toURIString());
			return false;
		}

		try {
			auth = new Authenticator(ds, receiver);
		}
		catch (PDCException ex) {
			Log.info("No authenticator available: " + ex.getMessage());
			return false;
		}
		try {
			encrypted = receiver.encryptData(auth);
		}
		catch (PDCEncryptionException ex) {
			Log.error("Error while encrypting data: " + ex.getMessage());
			return false;
		}

		try {
			return CommunicationHelper.publishEncryptedData(handle, interest,
							receiver.getPublickeyDigest(), encrypted, 1);
		}
		catch (PDCTransmissionException ex) {
			Log.error("Error while transmitting data: " + ex.getMessage());
			return false;
		}
	}

	boolean processStreamInfo(DataStream ds, ContentName receiver_uri,
					Interest interest)
	{
		CCNHandle handle = CCNHandle.getHandle(); //XXX: remove this
		PDCReceiver receiver;
		StreamInfo si;
		byte[] encrypted;

		receiver = ds.name2receiver(receiver_uri);
		if (receiver == null) {
			Log.warning(receiver_uri.toURIString() + " is an unknown URI");
			return false;
		}

		si = new StreamInfo(ds);
		try {
			encrypted = receiver.encryptData(si);
		}
		catch (PDCEncryptionException ex) {
			Log.error("Unable to encrypt stream info: " + ex.getMessage());
			return false;
		}

		assert encrypted != null;

		try {
			return CommunicationHelper.publishEncryptedData(handle, interest, ds.
							getTransport().getEncryptor().getStreamKeyDigest(), encrypted, 1);
		}
		catch (PDCTransmissionException ex) {
			Log.error("Unable to transmit data: " + ex.getMessage());
			return false;
		}
	}

	@Override
	@SuppressWarnings("CallToThreadDumpStack")
	boolean processCommand(DataStream ds, ContentName postfix, Interest interest)
	{
		Log.debug("Got replication interest for: " + postfix.toURIString());

		if (postfix.count() == 0) {
			Log.error("No subcommand!");

			return false;
		}

		String command = postfix.stringComponent(0);

		try {
			ContentName remainder = postfix.subname(1, postfix.count() - 1);
			if (command.matches("authenticator"))
				return processAuthenticator(ds, remainder, interest);
			else if (command.matches("stream_info"))
				return processStreamInfo(ds, remainder, interest);
			else if (command.matches("list"))
				return ds.getTransport().publishRecordList(interest, remainder);
			else {
				Log.info("Invalid request: " + interest.name().toURIString());

				return false;
			}
		}
		catch (Exception ex) {
			Log.error("Got problem: " + ex);
			ex.printStackTrace();
		}

		return false;
	}
}
