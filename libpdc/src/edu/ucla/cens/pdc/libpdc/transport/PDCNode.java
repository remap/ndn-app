/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc.transport;

import edu.ucla.cens.pdc.libpdc.stream.DataEncryptor;
import edu.ucla.cens.pdc.libpdc.GlobalConfig;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCEncryptionException;
import edu.ucla.cens.pdc.libpdc.iBSONExportable;
import edu.ucla.cens.pdc.libpdc.util.Log;
import edu.ucla.cens.pdc.libpdc.util.StringUtil;
import java.io.IOException;
import java.io.Serializable;
import java.security.PublicKey;
import java.util.LinkedList;
import java.util.List;
import org.ccnx.ccn.KeyManager;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.KeyLocator;
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

	private transient String _authenticator;

	/**
	 * Key locator for the  node
	 */
	protected KeyLocator _key_locator;

	public PDCNode(String uri)
					throws MalformedContentNameStringException
	{
		this.uri = ContentName.fromURI(uri);
	}

	public KeyLocator getKeyLocator()
	{
		return _key_locator;
	}

	public void setKeyLocator(KeyLocator _key_locator)
	{
		this._key_locator = _key_locator;
	}

	public PublisherPublicKeyDigest getPublickeyDigest()
	{
		return _publickey_digest;
	}

	public void setPublickeyDigest(PublisherPublicKeyDigest digest)
	{
		this._publickey_digest = digest;
	}

	public PublicKey getPublicKey()
	{
		GlobalConfig config = GlobalConfig.getInstance();
		KeyManager kmgr = config.getKeyManager();
		PublicKey key;

		assert kmgr != null;

		Log.debug("Obtaining key " + _key_locator + " " + _publickey_digest);

		if (_publickey_digest == null || _key_locator == null) {
			Log.warning("Don't know public key of " + uri.toURIString());
			return null;
		}

		try {
			key = kmgr.getPublicKey(_publickey_digest, _key_locator);
			if (key == null)
				Log.warning("No key available " + _key_locator + " " + _publickey_digest);
		}
		catch (IOException ex) {
			Log.error("Unable to obtain key for " + uri.toURIString() + ": " + ex.
							getMessage());
			return null;
		}

		return key;
	}

	public String getAuthenticator()
	{
		return _authenticator;
	}

	public void setAuthenticator(String authenticator)
	{
		this._authenticator = authenticator;
	}

	public byte[] encryptData(iBSONExportable data)
					throws PDCEncryptionException
	{
		return encryptData(data.toBSON());
	}

	public byte[] encryptData(byte[] data)
					throws PDCEncryptionException
	{
		PublicKey public_key;

		Log.debug("Encrypting: >" + new String(data) + "<");

		public_key = getPublicKey();
		if (public_key == null)
			throw new PDCEncryptionException("Public key not available");

		return DataEncryptor.encryptAsymData(public_key, data);
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
