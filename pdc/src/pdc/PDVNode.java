/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package pdc;

import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import org.ccnx.ccn.protocol.PublisherPublicKeyDigest;

/**
 *
 * @author takeda
 */
class PDVNode {
	ContentName _uri;
	PublisherPublicKeyDigest _publickey_digest;

	public PDVNode(String uri) throws MalformedContentNameStringException {
		this._uri = ContentName.fromURI(uri);
	}
}
