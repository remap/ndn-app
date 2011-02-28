/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc.transport;

import org.ccnx.ccn.protocol.MalformedContentNameStringException;

/**
 *
 * @author Derek Kulinski
 */
public class PDCPublisher extends PDCNode {
	public PDCPublisher(String uri)
					throws MalformedContentNameStringException
	{
		super(uri);
	}
}
