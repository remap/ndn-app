/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc;

import edu.ucla.cens.pdc.libpdc.DataStream;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.Interest;

/**
 *
 * @author Derek Kulinski
 */
abstract public class ReceiverCommand {
	protected final String COMMAND;

	public ReceiverCommand(String name)
	{
		this.COMMAND = name;
	}

	abstract boolean processCommand(ContentName postfix, Interest interest);

	final String getCommandName()
	{
		return COMMAND;
	}
}
