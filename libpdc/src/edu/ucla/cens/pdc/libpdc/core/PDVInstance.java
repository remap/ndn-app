/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc.core;

import edu.ucla.cens.pdc.libpdc.Application;
import edu.ucla.cens.pdc.libpdc.stream.DataStream;
import edu.ucla.cens.pdc.libpdc.util.Log;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import org.ccnx.ccn.CCNFilterListener;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.KeyManager;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;

/**
 *
 * @author Derek Kulinski
 */
final public class PDVInstance implements CCNFilterListener {
	final private Map<String, GenericCommand> _generic_commands = new HashMap<String, GenericCommand>(
					1);

	final private Map<String, StreamCommand> _stream_commands = new HashMap<String, StreamCommand>(
					2);

	final private GlobalConfig _config = GlobalConfig.getInstance();

	final static CCNHandle ccn_handle = CCNHandle.getHandle();

	public PDVInstance()
					throws MalformedContentNameStringException
	{
		GlobalConfig config = GlobalConfig.getInstance();
		KeyManager keymanager;

		keymanager = config.getKeyManager();
		assert keymanager != null;

		ccn_handle.getNetworkManager().setKeyManager(keymanager);

		add_generic_command(new PublisherDataCommand());
		add_generic_command(new PublisherControlCommands());
		add_stream_command(new ReceiverControlCommands());
	}

	public void startListening()
					throws MalformedContentNameStringException, IOException
	{
		ContentName root = _config.getRoot();
		ccn_handle.registerFilter(root, this);
	}

	public void stopListening()
	{
		ContentName root = _config.getRoot();
		ccn_handle.unregisterFilter(root, this);
	}

	public boolean handleInterest(Interest interest)
	{
		/*
		 * <root>/<app_id>/<stream_id>
		 *
		 * Stream commands:
		 * <stream_id>/data/<data_id>
		 * <stream_id>/control/authenticator/<receiver>
		 * <stream_id>/control/stream_info/<receiver>
		 * <stream_id>/control/list[/<last_data_id>]
		 *
		 * Receiver commands:
		 * <app_id>/control/setup/<stream>
		 * <app_id>/control/pull/<stream>
		 */

		ContentName root, name, postfix;
		String app_name, ds_name, command_name;
		Application app;
		DataStream ds;

		root = _config.getRoot();
		name = interest.name();
		postfix = name.postfix(root);

		Log.debug("Got interest: " + name + ", postfix: " + postfix);

		if (postfix == null || postfix.count() < 3)
			return false;

		app_name = postfix.stringComponent(0);
		app = _config.getApplication(app_name);
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
		ds = app.getDataStream(ds_name);
		if (ds == null) {
			Log.warning("Stream " + ds_name + " doesn't exist.");
			return false;
		}

		command_name = postfix.stringComponent(2);
		if (!_stream_commands.containsKey(command_name)) {
			Log.warning("Unknown command: " + command_name);
			return false;
		}

		ContentName remain = postfix.subname(3, postfix.count() - 3);
		StreamCommand cmd = _stream_commands.get(command_name);
		Log.info(String.format("Firing %s(%s, %s, %s)\n", cmd.getCommandName(),
						app.name, remain.toURIString(), interest));

		return cmd.processCommand(ds, remain, interest);
	}

	private void add_generic_command(StreamCommand command)
	{
		_stream_commands.put(command.getCommandName(), command);
	}

	private void add_stream_command(GenericCommand command)
	{
		_generic_commands.put(command.getCommandName(), command);
	}
}
