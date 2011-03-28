/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc;

import com.mongodb.BasicDBObject;
import com.mongodb.DBObject;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCException;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCParseException;
import edu.ucla.cens.pdc.libpdc.transport.PDCReceiver;
import org.bson.BSONDecoder;
import org.bson.BSONEncoder;
import org.ccnx.ccn.protocol.ContentName;

/**
 *
 * @author Derek Kulinski
 */
public class Authenticator implements iBSONExportable {
	private static final String STR_AUTHENTICATOR = "authenticator";

	private static final String STR_KEY_DIGEST = "key_digest";

	private DBObject _data;

	public Authenticator()
	{
	}

	public Authenticator(DataStream stream, PDCReceiver receiver)
					throws PDCException
	{
		String authenticator;

		assert stream != null;
		assert receiver != null;

		authenticator = receiver.getAuthenticator();
		if (authenticator == null)
			throw new PDCException("No authenticator set");

		_data = new BasicDBObject();
		_data.put(STR_AUTHENTICATOR, authenticator);

		//XXX: to implement
		_data.put(STR_KEY_DIGEST, "blah blah blah");
	}

	public String getAuthenticator()
	{
		assert _data != null;
		assert _data.containsField(STR_AUTHENTICATOR);

		return (String) _data.get(STR_AUTHENTICATOR);
	}

	public String getKeyDigest()
	{
		assert _data != null;
		assert _data.containsField(STR_KEY_DIGEST);

		return (String) _data.get(STR_KEY_DIGEST);
	}

	public byte[] toBSON()
	{
		BSONEncoder encoder = new BSONEncoder();

		assert _data != null : "_data is null";
		assert _data.containsField(STR_AUTHENTICATOR) : "no authenticator";
		assert _data.containsField(STR_KEY_DIGEST) : "no key digest";

		return encoder.encode(_data);
	}

	public Authenticator fromBSON(byte[] data)
					throws PDCParseException
	{
		BSONDecoder decoder = new BSONDecoder();

		try {
			_data = (DBObject) decoder.readObject(data);
		}
		catch (RuntimeException ex) {
			throw new PDCParseException("unable to parse data", ex);
		}

		return this;
	}
}
