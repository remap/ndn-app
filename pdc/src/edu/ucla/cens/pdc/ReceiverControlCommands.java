/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc;

import edu.ucla.cens.pdc.libpdc.GlobalConfig;
import edu.ucla.cens.pdc.libpdc.Constants;
import edu.ucla.cens.pdc.libpdc.DataStream;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCTransmissionException;
import edu.ucla.cens.pdc.libpdc.transport.StreamTransport;
import edu.ucla.cens.pdc.libpdc.util.Log;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.Interest;

/**
 *
 * @author Derek Kulinski
 */
public class ReceiverControlCommands extends ReceiverCommand {
	public ReceiverControlCommands()
	{
		super(Constants.STR_CONTROL);
	}

	@Override
	boolean processCommand(ContentName postfix, Interest interest)
	{
		GlobalConfig config = GlobalConfig.getInstance();
		int components;
		String command;
		ContentName stream_uri;
		DataStream ds;

		components = postfix.count();
		if (components < 1) {
			Log.info("Missing command");
			return false;
		}

		command = postfix.stringComponent(0);

		//Right now all commands require an URI argument
		if (components < 2) {
			Log.info("Invalid arguments");
			return false;
		}

		stream_uri = postfix.subname(1, components - 1);

		ds = config.uri2dataStream(stream_uri);
		if (ds == null) {
			Log.info("Unknown stream");
			return false;
		}

		if (command.equals("setup"))
			return setupCommand(ds, interest);
		else if (command.equals("pull"))
			return pullCommand(ds, interest);
		
		Log.error("Unknown command '" + command + "'!");

		return false;
	}

	private boolean setupCommand(DataStream ds, Interest interest)
	{
		throw new UnsupportedOperationException("Not yet implemented");
	}

	private boolean pullCommand(DataStream ds, Interest interest)
	{
		StreamTransport transport = ds.getTransport();

		try {
			transport.publishACK(interest);
		}
		catch (PDCTransmissionException ex) {
			Log.error("Error while sending ack: " + ex.getMessage());
			return false;
		}

		try {
			transport.fetchDataFromUplink();
		}
		catch (PDCTransmissionException ex) {
			Log.error("Error while pulling new records.");
			return false;
		}

		return true;
	}
}
