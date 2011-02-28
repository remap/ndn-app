/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package edu.ucla.cens.pdc.libpdc.transport;

import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import org.ccnx.ccn.protocol.PublisherPublicKeyDigest;

/**
 * Stores information about every node we communicate with
 * @author Derek Kulinski
 */
public class PDCNode {
	/**
	 * URI of the node
	 */
	public final ContentName uri;

	/**
	 * Node's public key digest
	 */
	protected PublisherPublicKeyDigest _publickey_digest;

	public PDCNode(String uri)
					throws MalformedContentNameStringException
	{
		this.uri = ContentName.fromURI(uri);
	}
}
