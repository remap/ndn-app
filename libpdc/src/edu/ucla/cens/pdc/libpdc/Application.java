/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc;

import edu.ucla.cens.pdc.libpdc.exceptions.PDCTransmissionException;
import edu.ucla.cens.pdc.libpdc.util.Log;
import edu.ucla.cens.pdc.libpdc.util.StringUtil;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.Timer;
import java.util.TimerTask;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;

/**
 * Stores information about applications that PDV handles
 * @author Derek Kulinski
 */
public class Application implements iApplication, iState {
	private static final long serialVersionUID = -5652787850695477611L;

	/**
	 * Identifier for the application
	 */
	public final String name;

	private transient ContentName _base_uri;

	private transient Map<String, DataStream> _data_stream;

	private transient Set<String> _to_pull;

	private transient Timer _pull_timer = null;

	private transient final ScheduledExecutorService _scheduler = Executors.
					newSingleThreadScheduledExecutor();

	private long _pull_rate = 0;

	public Application(String name)
	{
		this.name = name;
		setupObject();
	}

	private void setupObject()
	{
		GlobalConfig config = GlobalConfig.getInstance();

		try {
			_base_uri = config.getRoot().append(name);
		}
		catch (MalformedContentNameStringException ex) {
			throw new Error("Unable to set base name", ex);
		}

		_data_stream = new HashMap<String, DataStream>();
		_to_pull = new LinkedHashSet<String>();
	}

	public String getAppName()
	{
		return name;
	}

	public ContentName getBaseName()
	{
		return _base_uri;
	}

	/**
	 * Check if given data stream exists
	 * @param id
	 * @return
	 */
	synchronized public boolean isDataStream(String id)
	{
		return _data_stream.containsKey(id);
	}

	synchronized public DataStream getDataStream(String id)
	{
		return _data_stream.get(id);
	}

	synchronized public DataStream addDataStream(DataStream ds)
	{
		return _data_stream.put(ds.data_stream_id, ds);
	}

	synchronized Iterator<DataStream> getDataStreamsIterator()
	{
		return _data_stream.values().iterator();
	}

	synchronized private boolean performPull()
	{
		Iterator<String> iter;
		String ds_id;
		DataStream ds;

		if (_to_pull.isEmpty())
			_to_pull.addAll(_data_stream.keySet());

		Log.debug("Calling pull; iterating through " + _to_pull.size()
						+ " entries ...");

		iter = _to_pull.iterator();
		while (iter.hasNext()) {
			ds_id = iter.next();

			ds = _data_stream.get(ds_id);
			if (ds == null)
				continue;

			if (ds.getPublisher() == null)
				continue;

			iter.remove();

			try {
				Log.debug("Making " + ds.data_stream_id + " fetch data from the uplink");
				return ds.getTransport().fetchDataFromUplink();
			}
			catch (PDCTransmissionException ex) {
				Log.error("Unable to fetch data from uplink: " + ex.getMessage());
			}
		}

		return false;
	}

	synchronized public void periodicPullStart(long period)
	{
		if (_pull_rate > 0)
			periodicPullStop();

		Log.debug("Setting up pull for " + period + " seconds");

		_pull_rate = period;

		_scheduler.schedule(new Runnable() {
			public void run()
			{
				if (_pull_rate == 0)
					return;

				Log.debug("Performing pull...");
				performPull();
				Log.debug("Scheduling next task...");

				_scheduler.schedule(this, _pull_rate, TimeUnit.SECONDS);
			}
		}, _pull_rate, TimeUnit.SECONDS);
	}

	synchronized public void periodicPullStop()
	{
		if (_pull_rate == 0)
			return;

		_pull_rate = 0;
		_scheduler.shutdown();
	}

	@Override
	public String toString()
	{
		List<String> data = new LinkedList<String>();
		StringBuilder sb = new StringBuilder();

		sb.append(this.getClass().getSimpleName());
		sb.append('[');
		data.add(name);
		data.add(_base_uri.toURIString());
		data.add(_data_stream.toString());
		sb.append(StringUtil.join(data, "; "));
		sb.append(']');

		return sb.toString();
	}

	private void writeObject(ObjectOutputStream out)
					throws IOException
	{
		out.defaultWriteObject();
	}

	public void postStoreState(ObjectOutputStream out)
					throws IOException
	{
		int ds_count = _data_stream.size();
		out.writeInt(ds_count);

		for (String ds_name : _data_stream.keySet())
			out.writeUTF(ds_name);
	}

	private void readObject(ObjectInputStream in)
					throws IOException, ClassNotFoundException
	{
		in.defaultReadObject();

		setupObject();
	}

	public void postLoadState(ObjectInputStream in)
					throws IOException
	{
		GlobalConfig config = GlobalConfig.getInstance();
		int ds_count;

		config.addApplication(this);

		ds_count = in.readInt();

		for (int i = 0; i < ds_count; i++) {
			String ds_name = in.readUTF();
			DataStream stream = DataStream.loadState(name, ds_name);
			assert stream != null;

			_data_stream.put(ds_name, stream);
		}
	}

	public String getStateGroupName()
	{
		return "applications";
	}

	public String getStateKey()
	{
		return name;
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
		for (DataStream ds : _data_stream.values())
			ds.storeStateRecursive();

		storeState();
	}

	public static Application loadState(String name)
					throws IOException
	{
		Application app;
		GlobalConfig config = GlobalConfig.getInstance();

		app = (Application) config.loadConfig("applications", name);

		return app;
	}
}
