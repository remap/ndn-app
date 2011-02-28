/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc;

import org.ccnx.ccn.protocol.ContentName;

/**
 *
 * @author Derek Kulinski
 */
public interface iApplication {
	String getAppName();
	ContentName getBaseName();
	boolean data_stream_exists(String id);
	DataStream data_stream_get(String id);
	DataStream data_stream_add(DataStream ds);
}
