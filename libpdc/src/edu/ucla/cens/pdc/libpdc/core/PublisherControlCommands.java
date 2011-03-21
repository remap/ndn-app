/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc.core;

import edu.ucla.cens.pdc.libpdc.Constants;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import edu.ucla.cens.pdc.libpdc.DataStream;
import edu.ucla.cens.pdc.libpdc.transport.PDCReceiver;
import edu.ucla.cens.pdc.libpdc.util.Log;

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
//			if (command.matches("pull"))
//				return handlePull(interest, ds, postfix.subname(1, postfix.count() - 1));
//			else
			if (command.matches("stream_info"))
				return ds.getTransport().publishStreamInfo(interest);
			else if (command.matches("list"))
				return ds.getTransport().publishRecordList(interest, postfix.subname(
								1, postfix.count() - 1));
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
