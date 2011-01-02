/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pdc;

import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import org.ccnx.ccn.protocol.PublisherPublicKeyDigest;

/**
 * Stores information about every node we communicate with
 * @author Derek Kulinski
 */
class PDVNode {
	/**
	 * URI of the node
	 */
	public final ContentName uri;

	/**
	 * Node's public key digest
	 */
	private PublisherPublicKeyDigest _publickey_digest;

	public PDVNode(String uri)
					throws MalformedContentNameStringException
	{
		this.uri = ContentName.fromURI(uri);
	}
}
