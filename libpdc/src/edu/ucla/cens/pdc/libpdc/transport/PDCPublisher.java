/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc.transport;

import edu.ucla.cens.pdc.libpdc.SystemState;
import java.io.IOException;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;

/**
 *
 * @author Derek Kulinski
 */
public class PDCPublisher extends PDCNode {
	public PDCPublisher(String uri, String stream_id)
					throws MalformedContentNameStringException
	{
		super(uri);

		assert stream_id != null && !stream_id.isEmpty();

		this._stream_id = stream_id;
	}

	public PDCPublisher(SystemState.PDCPublisher state)
					throws MalformedContentNameStringException, IOException
	{
		super(state.getBase());

		this._stream_id = state.getStreamId();
	}

	/**
	 * @return the _stream_id
	 */
	public String getStreamId()
	{
		return _stream_id;
	}

	/**
	 * @param stream_id the _stream_id to set
	 */
	public void setStreamId(String stream_id)
	{
		this._stream_id = stream_id;
	}

	@Override
	public SystemState.PDCPublisher getObjectState()
	{
		SystemState.PDCPublisher.Builder builder = SystemState.PDCPublisher.
						newBuilder();

		builder.setBase((SystemState.PDCNode) super.getObjectState());
		builder.setStreamId(_stream_id);

		return builder.build();
	}

	private String _stream_id;
}
