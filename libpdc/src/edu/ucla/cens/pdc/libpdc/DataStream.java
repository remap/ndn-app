/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc;

import edu.ucla.cens.pdc.libpdc.exceptions.PDCTransmissionException;
import edu.ucla.cens.pdc.libpdc.transport.PDCPublisher;
import edu.ucla.cens.pdc.libpdc.transport.PDCReceiver;
import edu.ucla.cens.pdc.libpdc.transport.StreamTransport;
import edu.ucla.cens.pdc.libpdc.util.StringUtil;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.lang.reflect.Field;
import java.util.ArrayList;
import java.util.Collection;
import java.util.LinkedList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;

/**
 *
 * @author Derek Kulinski
 */
public class DataStream implements iDataStream, iState {
	private static final long serialVersionUID = 4028445614659553162L;

	/**
	 * application associated with the DS
	 */
	public transient final iApplication app;

	/**
	 * id of the data stream
	 */
	public final String data_stream_id;

	/**
	 * instance of class responsible for the storage of data
	 */
	protected transient Storage _store;

	/**
	 * instance of class responsible for transferring data
	 * over the network
	 */
	protected StreamTransport _transport;

	/**
	 * publisher of the DS
	 */
	protected PDCPublisher _publisher = null;

	/**
	 * receivers of our DS
	 */
	protected List<PDCReceiver> _receivers = new ArrayList<PDCReceiver>();


	public DataStream(CCNHandle handle, iApplication app, String data_stream_id)
	{
		assert app != null;
		assert data_stream_id != null && !data_stream_id.isEmpty();
		assert !data_stream_id.startsWith("/") : "stream id: " + data_stream_id;

		this.app = app;
		this.data_stream_id = data_stream_id;

		setupClass();

		try {
			this._transport = new StreamTransport(handle, this);
		}
		catch (PDCTransmissionException ex) {
			throw new Error("Unable to instantiate transmission class", ex);
		}
	}

	protected void setupClass()
	{
		_store = GlobalConfig.setupDataStorage(app, data_stream_id);
	}

	public Storage getStorage()
	{
		return _store;
	}

	public StreamTransport getTransport()
	{
		return _transport;
	}

	public void processStreamInfo(StreamInfo data)
	{
		_transport.getEncryptor().setDecryptKey(data.getStreamKey());
	}

	public ContentName getPublisherStreamURI()
	{
		ContentName uri;
		ContentName result;

		assert app != null : "Datastream should be always associated to application";
		assert _publisher != null : "The publisher needs to be defined to call this method";

		uri = _publisher.uri;
		assert uri != null : "Publisher should always have URI";
		assert _publisher.getStream_id() != null : "Publisher needs to have stream URI present";

		try {
			result = uri.append(app.getAppName()).append(_publisher.getStream_id());
			return result;
		}
		catch (MalformedContentNameStringException ex) {
			throw new Error(
							String.format("Unable to create %s/%s/%s", uri, app.getAppName(),
							_publisher.getStream_id()), ex);
		}
	}

	public void setPublisher(PDCPublisher node)
	{
		_publisher = node;
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

	public synchronized Collection<PDCReceiver> getReceivers()
	{
		return _receivers;
	}

	public synchronized PDCReceiver name2receiver(ContentName name_id)
	{
		for (PDCReceiver receiver : _receivers) {
			if (!receiver.uri.equals(name_id))
				continue;

			return receiver;
		}

		return null;
	}


	@Override
	public String toString()
	{
		List<String> data = new LinkedList<String>();
		StringBuilder sb = new StringBuilder();

		sb.append(this.getClass().getSimpleName());
		sb.append('[');
		data.add(data_stream_id);
		data.add(app.getAppName());
		data.add(_store.toString());
		data.add(_transport.toString());
		data.add(_publisher == null ? null : _publisher.toString());
		data.add(_receivers.toString());
		sb.append(StringUtil.join(data, "; "));
		sb.append(']');

		return sb.toString();
	}

// <editor-fold defaultstate="collapsed" desc="serialization code">
	private void writeObject(ObjectOutputStream out)
					throws IOException
	{
		out.defaultWriteObject();

//		out.writeUTF(data_stream_id);
//		out.writeObject(_transport);
//		out.writeObject(_publisher);
//		out.writeObject(_receivers);
//		out.writeObject(_stream_keys);
	}

	public void postStoreState(ObjectOutputStream out)
					throws IOException
	{
		out.writeUTF(app.getAppName());
	}

	private void readObject(ObjectInputStream in)
					throws IOException, ClassNotFoundException
	{
		in.defaultReadObject();
	}

	@SuppressWarnings("unchecked")
	public void postLoadState(ObjectInputStream in)
					throws IOException, ClassNotFoundException
	{
		GlobalConfig config = GlobalConfig.getInstance();
		String app_name;
		Application tmp_app;

		app_name = in.readUTF();

		tmp_app = config.getApplication(app_name);
		if (tmp_app == null)
			throw new IOException("Application " + app_name + " not found");

		tmp_app.addDataStream(this);

		try {
			Field fld_app = DataStream.class.getDeclaredField("app");
			fld_app.setAccessible(true);
			fld_app.set(this, tmp_app);
		}
		catch (Exception ex) {
			Logger.getLogger(DataStream.class.getName()).log(Level.SEVERE, null, ex);
		}

		setupClass();

//		_transport = (StreamTransport) in.readObject();
//		_publisher = (PDCPublisher) in.readObject();
//		_receivers = (List<PDCReceiver>) in.readObject();
//		_stream_keys = (KeyPair) in.readObject();
	}

	public String getStateGroupName()
	{
		return "datastream_" + app.getAppName();
	}

	public String getStateKey()
	{
		return data_stream_id;
	}

	public void storeState()
					throws IOException
	{
		GlobalConfig config = GlobalConfig.getInstance();

		config.saveConfig(this);
	}

	public void storeStateRecursive()
					throws IOException
	{
		storeState();
	}

	public static DataStream loadState(String app_name, String ds_name)
					throws IOException
	{
		DataStream stream;
		GlobalConfig config = GlobalConfig.getInstance();

		stream = (DataStream) config.loadConfig("datastream_" + app_name, ds_name);

		return stream;
	}
// </editor-fold>
}
