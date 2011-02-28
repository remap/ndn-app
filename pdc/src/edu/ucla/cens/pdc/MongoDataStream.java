/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc;

import edu.ucla.cens.pdc.libpdc.DataStream;
import org.ccnx.ccn.CCNHandle;

/**
 *
 * @author Derek Kulinski
 */
public class MongoDataStream extends DataStream {
	public MongoDataStream(Application app, String data_stream_id)
	{
		super(CCNHandle.getHandle(), MongoStorage.class, app, data_stream_id);
	}
}
