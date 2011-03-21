/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc.transport;

import edu.ucla.cens.pdc.libpdc.util.StringUtil;
import java.io.Serializable;
import java.security.KeyPair;
import java.security.PublicKey;
import java.util.LinkedList;
import java.util.List;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import org.ccnx.ccn.protocol.PublisherPublicKeyDigest;

/**
 * Stores information about every node we communicate with
 * @author Derek Kulinski
 */
public class PDCNode implements Serializable {
	private static final long serialVersionUID = -6962419725928576508L;

	/**
	 * URI of the node
	 */
	public final ContentName uri;

	/**
	 * Node's public key digest
	 */
	protected PublisherPublicKeyDigest _publickey_digest;

	public PublisherPublicKeyDigest getPublickeyDigest()
	{
		return _publickey_digest;
	}

	public void setPublickeyDigest(PublisherPublicKeyDigest digest)
	{
		this._publickey_digest = digest;
	}

	public PDCNode(String uri)
					throws MalformedContentNameStringException
	{
		this.uri = ContentName.fromURI(uri);
	}

	@Override
	public String toString()
	{
		List<String> data = new LinkedList<String>();
		StringBuilder sb = new StringBuilder();

		sb.append(this.getClass().getSimpleName());
		sb.append('[');
		data.add(uri.toURIString());
		data.add(_publickey_digest == null ? null : _publickey_digest.toString());
		sb.append(StringUtil.join(data, "; "));
		sb.append(']');

		return sb.toString();
	}
}
