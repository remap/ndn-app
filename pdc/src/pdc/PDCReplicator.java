/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pdc;

import java.io.IOException;
import java.security.InvalidKeyException;
import java.security.SignatureException;
import java.util.Collection;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.config.SystemConfiguration;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.ContentObject;
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import org.ccnx.ccn.protocol.SignedInfo;
import pdc.util.Log;
import pdc.util.StringUtil;

/**
 *
 * @author takeda
 */
class PDCReplicator extends PDCCommand {

	private static PDCReplicator _instance = null;
	private final int FRESHNESS = 1;
	private DataEncryptor _encryptor;
	private PDCConfigStore _config = PDCConfigStore.get_instance();

	private PDCReplicator(CCNHandle handle)
					throws MalformedContentNameStringException
	{
		super(handle, "replicate");

		_encryptor = new DataEncryptor();
	}

	static PDCReplicator get_instance()
	{
		assert _instance != null;
		return _instance;
	}

	static PDCReplicator get_instance(CCNHandle handle)
					throws MalformedContentNameStringException
	{
		if (_instance == null)
			_instance = new PDCReplicator(handle);

		return _instance;
	}

	private boolean handlePush(Interest interest, Application app,
					ContentName name)
	{
		System.out.println("Got push request for: " + name.toURIString());
		return false;
	}

//	private boolean handlePull(Interest interest, Application app, ContentName name) {
//		Log.debug("Got pull request for: " + name.toURIString());
//
//		if (name.count() < 1)
//			return false;
//
//		String[] args = name.toString().split("%7C");
//
//		if (args.length < 2 || args.length > 3)
//			return false;
//
//		try {
//			ContentName uri = ContentName.fromNative(args[0])
//							.append(app.name).append("share").append(args[1]);
//
//		} catch (MalformedContentNameStringException ex) {
//			Log.error("Invalid uri: " + args[0]);
//			return false;
//		}
//
//
//		return false;
//	}
	private boolean handlePull(Interest interest, Application app,
					ContentName name)
					throws InvalidKeyException, SignatureException, IOException
	{

		String[] args;
		DataStream datastream;
		Collection<String> ids;
		ContentName uri;
		String data;
		ContentObject co;

		Log.debug("Got pull request for: " + name.toURIString());

		if (name.count() < 1)
			return false;

		args = StringUtil.stripPrfixChar(name.toString(), "/").split("%7C");

		if (args.length < 2 || args.length > 3)
			return false;

		uri = interest.name().subname(0, interest.name().count() - 3);

		// Content of the data packet
		datastream = new DataStream(app, args[0]);
		ids = args.length == 2
						? datastream.getRangeIds(args[1])
						: datastream.getRangeIds(args[1], args[2]);
		data = uri + "\n" + StringUtil.join(ids, "\n");

		SignedInfo si = new SignedInfo(_publisher, SignedInfo.ContentType.ENCR,
						_locator, FRESHNESS, null);

		byte[] cipher = _encryptor.encryptData(app, datastream, data.getBytes());
		co = new ContentObject(interest.name(), si, cipher, _signing_key);
		_ccn_handle.put(co);

		return true;
	}

	@Override
	boolean processCommand(Application app, ContentName postfix, Interest interest)
	{
		System.out.println("Got replication interest for: " + postfix.toURIString());

		if (postfix.count() == 0) {
			System.err.println("No subcommand!");
			return false;
		}

		String command = postfix.stringComponent(0);

		try {
			if (command.matches("push"))
				return handlePush(interest, app, postfix.subname(1, postfix.count() - 1));
			else if (command.matches("pull"))
				return handlePull(interest, app, postfix.subname(1, postfix.count() - 1));
			else {
				ContentObject co = ContentObject.buildContentObject(interest.name(),
								"invalid request!".getBytes());
				_ccn_handle.put(co);
				return true;
			}

		} catch (InvalidKeyException ex) {
			Logger.getLogger(PDCReplicator.class.getName()).log(Level.SEVERE, null, ex);
		} catch (SignatureException ex) {
			Logger.getLogger(PDCReplicator.class.getName()).log(Level.SEVERE, null, ex);
		} catch (IOException ex) {
			Logger.getLogger(PDCReplicator.class.getName()).log(Level.SEVERE, null, ex);
		}
		return false;
	}

	Collection<String> callPull(ContentName pdv, String app, String stream,
					String start, String end)
					throws MalformedContentNameStringException
	{
		ContentName uri;

		assert pdv != null;
		assert app != null;
		assert stream != null;
		assert start != null;

		uri = pdv.append(app).append(COMMAND).append("pull");

		if (end == null)
			uri = uri.append(String.format("%s|%s", stream, start));
		else
			uri = uri.append(String.format("%s|%s|%s", stream, start, end));

		Log.debug(uri.toURIString());

		try {
			ContentObject response = _ccn_handle.get(uri,
							SystemConfiguration.NO_TIMEOUT);
			if (response == null)
				return null;

			Application appl = _config.getApplication(app);
			byte[] content = _encryptor.decryptData(appl, stream, response.content());

			//XXX: Check signature here
			Log.debug(new String(content));
		} catch (IOException ex) {
			Logger.getLogger(PDCReplicator.class.getName()).log(Level.SEVERE, null, ex);
		}
		return null;
	}
}
