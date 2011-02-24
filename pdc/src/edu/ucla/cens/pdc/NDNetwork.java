/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import org.ccnx.ccn.CCNFilterListener;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.config.ConfigurationException;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import edu.ucla.cens.pdc.util.Log;

/**
 *
 * @author Derek Kulinski
 */
public class NDNetwork implements CCNFilterListener {
	private Map<String, PublisherCommand> _receiver_commands = new HashMap<String, PublisherCommand>(
					1);
	private Map<String, PublisherCommand> _publisher_commands = new HashMap<String, PublisherCommand>(
					2);
	final private PDCConfigStore _config = PDCConfigStore.get_instance();
	final static CCNHandle ccn_handle = CCNHandle.getHandle();
	final private ContentName _namespace;

	public NDNetwork(String namespace)
					throws IOException, ConfigurationException,
					MalformedContentNameStringException
	{
//		_ccn_handle = CCNHandle.getHandle();
		_namespace = ContentName.fromURI(namespace);

		add_publisher_command(PublisherDataCommand.get_instance(ccn_handle));
		add_publisher_command(PublisherControlCommands.get_instance(ccn_handle));
	}

	public void startListening()
					throws MalformedContentNameStringException, IOException
	{
		ccn_handle.registerFilter(_namespace, this);
	}

	public boolean handleInterest(Interest interest)
	{
		String app_name, ds_name, command_name;
		Application app;
		DataStream ds;

		ContentName name = interest.name();
		ContentName postfix = name.postfix(_namespace);

		Log.debug("Got interest: " + name + ", postfix: " + postfix);

		if (postfix == null || postfix.count() < 3)
			return false;

		app_name = postfix.stringComponent(0);
		app = _config.get_application(app_name);
		if (app == null) {
			Log.warning("Application " + app_name + " doesn't exist.");
			return false;
		}

		if (postfix.stringComponent(1).equals("control"))
			//TODO: implement it (receiver side)
			throw new UnsupportedOperationException("Not implemented yet");

		if (postfix.count() < 4)
			return false;

		ds_name = postfix.stringComponent(1);
		ds = app.data_stream_get(ds_name);
		if (ds == null) {
			Log.warning("Stream " + ds_name + " doesn't exist.");
			return false;
		}

		command_name = postfix.stringComponent(2);
		if (!_publisher_commands.containsKey(command_name)) {
			Log.warning("Unknown command: " + command_name);
			return false;
		}

		ContentName remain = postfix.subname(3, postfix.count() - 3);
		PublisherCommand cmd = _publisher_commands.get(command_name);
		Log.info(String.format("Firing %s(%s, %s, %s)\n", cmd.getCommandName(),
						app.name, remain.toURIString(), interest));

		return cmd.processCommand(ds, remain, interest);
	}

	private void add_publisher_command(PublisherCommand command)
	{
		_publisher_commands.put(command.getCommandName(), command);
	}

	private void add_receiver_command(PublisherCommand command)
	{
		_receiver_commands.put(command.getCommandName(), command);
	}
}
