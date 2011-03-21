/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc.core;

import edu.ucla.cens.pdc.libpdc.Constants;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.Interest;

/**
 *
 * @author Derek Kulinski
 */
public class ManageCommand extends GenericCommand {
	public ManageCommand()
	{
		super(Constants.STR_MANAGE);
	}

	/*
	 * /datastream/<name>/
	 * - add - create datastream
	 * - remove - remove stream
	 * - modify
	 * - newkey - generate a new key for encryption
	 *
	 */

	@Override
	boolean processCommand(ContentName postfix, Interest interest)
	{
		throw new UnsupportedOperationException("To implement");
	}
}
