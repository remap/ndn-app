/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package edu.ucla.cens.pdc;

import edu.ucla.cens.pdc.libpdc.DataStream;
import java.security.PrivateKey;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.KeyManager;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.protocol.KeyLocator;
import org.ccnx.ccn.protocol.PublisherPublicKeyDigest;

/**
 *
 * @author Derek Kulinski
 */
abstract class PublisherCommand {
	protected final String COMMAND;
	protected CCNHandle _ccn_handle;
	protected KeyManager _keymanager;
	protected PrivateKey _signing_key;
	protected PublisherPublicKeyDigest _publisher;
	protected KeyLocator _locator;

	public PublisherCommand(CCNHandle handle, String name) {
		COMMAND = name;

		_ccn_handle = handle;
		this._keymanager = _ccn_handle.keyManager();
		this._signing_key = _keymanager.getDefaultSigningKey();
		this._publisher = _keymanager.getPublisherKeyID(_signing_key);
		this._locator = _keymanager.getKeyLocator(_signing_key);
	}

	abstract boolean processCommand(DataStream ds, ContentName postfix, Interest interest);

	final String getCommandName() {
		return COMMAND;
	}
}
