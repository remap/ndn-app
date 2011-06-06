/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.transducer;

import edu.ucla.cens.pdc.libpdc.Application;
import edu.ucla.cens.pdc.libpdc.core.GlobalConfig;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCDatabaseException;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCParseException;
import edu.ucla.cens.pdc.libpdc.stream.DataStream;
import edu.ucla.cens.pdc.libpdc.util.Log;
import edu.ucla.cens.pdc.xmlparser.Configuration;
import java.io.File;
import java.io.IOException;
import java.util.LinkedList;
import java.util.List;
import java.util.concurrent.ScheduledExecutorService;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Derek Kulinski
 */
public class TransducerServer {
	//XXX: hacks need to be gone
	public TransducerServer(String config)
	{
//		final XMLParser parser = new XMLParser();
//		parser.setFileName(config);
//
//		_transducer_config = parser.parse();
		_transducers = new LinkedList<TransducerClient>();
	}

	public void initialize()
	{
		final File directory = new File(
				"/home/takeda/Documents/cens/ndn-app/transducers/derek/transducer-client");

		final GlobalConfig config = GlobalConfig.getInstance();

		final Application app = config.getApplication("myapp");
		assert app != null;

		final DataStream i_stream = app.getDataStream("input");
		assert i_stream != null;

		final DataStream o_stream = app.getDataStream("output");
		assert o_stream != null;

		final DataStream[][] streams = new DataStream[][]{
			{i_stream},
			{o_stream}
		};

		//XXX: this should be automatically guessed
		final int[] record_count = new int[]{1};

		TransducerClient client = new TransducerClient("CounterMultiplier",
				directory,
				"/home/takeda/Documents/cens/ndn-app/transducers/derek/transducer-client/examples/Transducers.jar",
				"CounterMultiplier", streams, record_count);

		_transducers.add(client);

//		if (_scheduler == null || _scheduler.isTerminated())
//			_scheduler = Executors.newSingleThreadScheduledExecutor();
//
//		_scheduler.schedule(new Runnable() {
//			public void run()
//			{
//				executeTransducers();
//
//				if (_scheduler != null && !_scheduler.isTerminated())
//					_scheduler.schedule(this, 10, TimeUnit.SECONDS);
//			}
//		}, 10, TimeUnit.SECONDS);
	}

	public synchronized void executeTransducers()
	{
		Log.debug("Executing transducers: " + _transducers.size());

		try {
			for (TransducerClient transducer : _transducers)
				transducer.newDataCheck();
		}
		catch (PDCDatabaseException ex) {
			Logger.getLogger(TransducerServer.class.getName()).
					log(Level.SEVERE, null, ex);
		}
		catch (IOException ex) {
			Logger.getLogger(TransducerServer.class.getName()).
					log(Level.SEVERE, null, ex);
		}
		catch (PDCParseException ex) {
			Logger.getLogger(TransducerServer.class.getName()).
					log(Level.SEVERE, null, ex);
		}
	}

	private ScheduledExecutorService _scheduler;

	private final List<TransducerClient> _transducers;

	private Configuration _transducer_config;
}
