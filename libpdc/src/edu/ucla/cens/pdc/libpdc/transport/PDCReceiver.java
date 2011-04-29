/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc.transport;

import edu.ucla.cens.pdc.libpdc.SystemState;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;

/**
 *
 * @author Derek Kulinski
 */
public class PDCReceiver extends PDCNode {
	private static final long serialVersionUID = -2708593542096598873L;

	public PDCReceiver(String uri)
					throws MalformedContentNameStringException
	{
		super(uri);
	}

	@Override
	public SystemState.PDCReceiver getObjectState()
	{
		SystemState.PDCReceiver.Builder builder = SystemState.PDCReceiver.newBuilder();

		builder.setBase((SystemState.PDCNode) super.getObjectState());

		return builder.build();
	}
}
