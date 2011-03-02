/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc.transport;

import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;

/**
 *
 * @author Derek Kulinski
 */
public class PDCPublisher extends PDCNode {
	private String _stream_id;

	public PDCPublisher(String uri, String stream_id)
					throws MalformedContentNameStringException
	{
		super(uri);

		assert stream_id != null && !stream_id.isEmpty();

		this._stream_id = stream_id;
	}

	/**
	 * @return the _stream_id
	 */
	public String getStream_id()
	{
		return _stream_id;
	}

	/**
	 * @param stream_id the _stream_id to set
	 */
	public void setStream_id(String stream_id)
	{
		this._stream_id = stream_id;
	}
}
