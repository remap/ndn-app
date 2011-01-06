/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pdc;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import org.ccnx.ccn.CCNFilterListener;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.config.ConfigurationException;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import pdc.util.Log;

/**
 *
 * @author Derek Kulinski
 */
public class NDNetwork implements CCNFilterListener {
	private PDCConfigStore _config = PDCConfigStore.get_instance();
	private Map<String, PDCCommand> _commands = new HashMap<String, PDCCommand>(5);
	private CCNHandle _ccn_handle;
	private ContentName _namespace;

	public NDNetwork(String namespace)
					throws IOException, ConfigurationException,
					MalformedContentNameStringException
	{
		_ccn_handle = CCNHandle.getHandle();
		_namespace = ContentName.fromURI(namespace);

		addCommand(PDCDataProvider.get_instance(_ccn_handle));
		addCommand(PDCReplicator.get_instance(_ccn_handle));
	}

	public void startListening()
					throws MalformedContentNameStringException, IOException
	{
		_ccn_handle.registerFilter(_namespace, this);
	}

	public boolean handleInterest(Interest interest)
	{
		ContentName name = interest.name();
		ContentName postfix = name.postfix(_namespace);

		Log.debug("Got interest: " + name + ", postfix: " + postfix);

		if (postfix == null || postfix.count() < 2)
			return false;

		String appname = postfix.stringComponent(0);

		Application app = _config.get_application(appname);
		if (app == null) {
			Log.warning("Application " + appname + " doesn't exist.");
			return false;
		}

		String command = postfix.stringComponent(1);
		if (!_commands.containsKey(command)) {
			Log.warning("Unknown command: " + command);
			return false;
		}

		ContentName remain = postfix.subname(2, postfix.count() - 2);
		PDCCommand cmd = _commands.get(command);
		Log.info(String.format("Firing %s(%s, %s, %s)\n", cmd.getCommandName(), app.name,
						remain.toURIString(), interest));
		return cmd.processCommand(app, remain, interest);
	}

	private void addCommand(PDCCommand command)
	{
		_commands.put(command.getCommandName(), command);
	}
}
