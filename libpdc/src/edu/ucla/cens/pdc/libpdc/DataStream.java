/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc;

import edu.ucla.cens.pdc.libpdc.exceptions.PDCDatabaseException;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCTransmissionException;
import edu.ucla.cens.pdc.libpdc.transport.PDCPublisher;
import edu.ucla.cens.pdc.libpdc.transport.PDCReceiver;
import edu.ucla.cens.pdc.libpdc.transport.StreamTransport;
import edu.ucla.cens.pdc.libpdc.util.Log;
import java.lang.reflect.Constructor;
import java.security.KeyPair;
import java.util.ArrayList;
import java.util.List;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.KeyLocator;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import org.ccnx.ccn.protocol.PublisherPublicKeyDigest;

/**
 *
 * @author Derek Kulinski
 */
public class DataStream {
	/**
	 * application associated with the DS
	 */
	final public iApplication app;

	/**
	 * id of the data stream
	 */
	final public String data_stream_id;

	/**
	 * instance of class responsible for the storage of data
	 */
	final protected Storage _store;

	/**
	 * instance of class responsible for encryption of data
	 * while it is being transferred
	 */
	final protected DataEncryptor _encryptor;

	/**
	 * instance of class responsible for transferring data
	 * over the network
	 */
	final protected StreamTransport _transport;

	/**
	 * id of last record in the database
	 */
	protected String _last_entry = null;

	/**
	 * publisher of the DS
	 */
	protected PDCPublisher _publisher = null;

	/**
	 * publisher data_stream name
	 */
	protected String _publisher_data_stream_id;

	/**
	 * receivers of our DS
	 */
	protected List<PDCReceiver> _receivers = new ArrayList<PDCReceiver>();

	/**
	 * keys associated with our stream
	 */
	protected KeyPair _stream_keys;

	public DataStream(CCNHandle handle, Class<? extends Storage> type,
					iApplication app, String data_stream_id)
	{
		Constructor<? extends Storage> constructor;

		assert app != null;
		assert data_stream_id != null && !data_stream_id.isEmpty();
		assert !data_stream_id.startsWith("/") : "stream id: " + data_stream_id;

		this.app = app;
		this.data_stream_id = data_stream_id;

		try {
			constructor = type.getConstructor(app.getClass(), String.class);
			_store = constructor.newInstance(app, data_stream_id);
		}
		catch (Exception ex) {
			throw new Error("Unable instantiate the storage class", ex);
		}

		this._encryptor = new DataEncryptor();

		try {
			this._transport = new StreamTransport(handle, this);
		} catch (PDCTransmissionException ex) {
			throw new Error("Unable to instantiate transmission class", ex);
		}
	}

	public Storage getStorage()
	{
		return _store;
	}

	public DataEncryptor getEncryptor()
	{
		return _encryptor;
	}

	public StreamTransport getTransport()
	{
		return _transport;
	}

	public ContentName getPublisherStreamURI()
	{
		ContentName uri;
		ContentName result;

		assert app != null : "Datastream should be always associated to application";
		assert _publisher != null : "The publisher needs to be defined to call this method";

		uri = _publisher.uri;
		assert uri != null : "Publisher should always have URI";

		try {
			result = uri.append(app.getAppName()).append(_publisher_data_stream_id);
			return result;
		}
		catch (MalformedContentNameStringException ex) {
			throw new Error(
							String.format("Unable to create %s/%s/%s", uri, app.getAppName(),
							_publisher_data_stream_id), ex);
		}
	}

	public PublisherPublicKeyDigest getKeyDigest()
	{
		//TODO: don't generate this every time
//		return new PublisherPublicKeyDigest(_stream_keys.getPublic());
//		return null;
		return CCNHandle.getHandle().getDefaultPublisher();
	}

	public KeyLocator getKeyLocator()
	{
//		//TODO: this is obviously wrong
//		KeyLocator locator = new KeyLocator(_stream_keys.getPublic());
//
//		return locator;
//		return null;
		return CCNHandle.getHandle().keyManager().getDefaultKeyLocator();
	}

	public void setPublisher(PDCPublisher node, String ds_id)
	{
		_publisher = node;
		_publisher_data_stream_id = ds_id;
	}

	public PDCPublisher getPublisher()
	{
		return _publisher;
	}

	public synchronized void addReceiver(PDCReceiver node)
	{
		_receivers.add(node);
	}

	public synchronized void delReceiver(PDCReceiver node)
	{
		_receivers.remove(node);
	}

	private synchronized void updateLastEntry()
	{
		try {
			_last_entry = _store.getLastEntry();
		}
		catch (PDCDatabaseException ex) {
			Log.error(ex);
		}
	}
}
