/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc;

import edu.ucla.cens.pdc.libpdc.core.PDVInstance;
import edu.ucla.cens.pdc.libpdc.Application;
import edu.ucla.cens.pdc.libpdc.core.GlobalConfig;
import edu.ucla.cens.pdc.libpdc.datastructures.DataRecord;
import edu.ucla.cens.pdc.libpdc.stream.DataStream;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCDatabaseException;
import edu.ucla.cens.pdc.libpdc.stream.Storage;
import edu.ucla.cens.pdc.libpdc.util.Log;
import edu.ucla.cens.pdc.transducer.TransducerServer;
import java.io.IOException;
import java.util.Date;
import java.util.logging.Level;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import sun.misc.Signal;
import sun.misc.SignalHandler;

/**
 *
 * @author Derek Kulinski
 */
public class Main {
	static void usage()
	{
		System.err.printf("Usage: pdc.jar database\n");
		System.err.printf("       pdc.jar pdv2\n");
		System.err.printf("       pdc.jar pdv1 ccnx:/path/to/pdv2/key key_digest\n");
		System.exit(10);
	}

	static void fillDatabase(DataStream ds)
	{
		try {
			for (double i = 0; i < 500; i++) {
				DataRecord dr = new DataRecord();
				dr.put("date", new Date());
				dr.put("type", 1);
				dr.put("latitude", i);
				dr.put("longitude", 123.3974);
				for (int j = 0; j < 500; j++)
					dr.put("entry" + j, j);
				ds.getStorage().insertRecord(dr);
				org.ccnx.ccn.impl.support.Log.info("Record {0} added.", i);
			}
		}
		catch (PDCDatabaseException ex) {
			throw new Error("Unable to populate the database", ex);
		}
	}

	static void setupPDV(int pdv_started)
			throws MalformedContentNameStringException, IOException
	{
		final GlobalConfig config = GlobalConfig.getInstance();
		final CCNHandle handle = config.getCCNHandle();
		final ContentName root = ContentName.fromURI("ccnx:/ucla.edu/apps/pdv");

		Application n1_app = null;
		DataStream n1_input, n1_output;

		if (pdv_started == 1) {
			config.setRoot(root);

			n1_app = new Application("myapp");

			n1_input = new DataStream(handle, n1_app, "input");
			n1_app.addDataStream(n1_input);

			n1_output = new DataStream(handle, n1_app, "output");
			n1_app.addDataStream(n1_output);

			config.addApplication(n1_app);
		} else if (pdv_started == -1) {
			config.setRoot(root);
			Application app = new Application("myapp");
			DataStream ds = new DataStream(handle, app, "input");
			app.addDataStream(ds);
			config.addApplication(app);
		}
	}

	/**
	 * @param args the command line arguments
	 */
	@SuppressWarnings("fallthrough")
	public static void main(String[] args)
			throws Exception
	{
		GlobalConfig config;
		int pdv_started = 0;
		PDVInstance test = null;

		if (args.length < 1)
			usage();

		String arg = args[0];

		if (arg.equals("pdv"))
			pdv_started = 1;
		else if (arg.equals("database"))
			pdv_started = -1;
		else {
			Log.error("Unknown command");
			System.exit(10);
		}

		MongoDataStorage.setPrefix("pdv_");
		MongoConfigStorage.setPrefix("pdv_");

		GlobalConfig.setFeatures(GlobalConfig.FEAT_SHARING
				| GlobalConfig.FEAT_MANAGE | GlobalConfig.FEAT_FILTERING);
		GlobalConfig.setConfigStorage(MongoConfigStorage.class);
		GlobalConfig.setDataStorage(MongoDataStorage.class);

		//Disable annoying ccnx debug messages
		org.ccnx.ccn.impl.support.Log.setDefaultLevel(
				org.ccnx.ccn.impl.support.Log.FAC_ALL, Level.WARNING);

		config = GlobalConfig.getInstance();

		setupPDV(pdv_started);

//		Signal.handle(new Signal("INT"), new IntHander());

		if (pdv_started > 0)
			test = new PDVInstance();

		DataStream ds = config.getApplication("myapp").getDataStream("input");
		switch (pdv_started) {
		case -1:
			fillDatabase(ds);
			System.exit(0);
		}

		test.startListening();

		Log.debug("Listening");

		TransducerServer ts = test.getTransducers();
		int counter = 0;
		Storage store = ds.getStorage();
		while (true) {
			DataRecord r = new DataRecord();
			r.put("counter", counter++);
			store.insertRecord(r);
			ts.executeTransducers();
			Thread.sleep(5000);
		}
	}

	static class IntHander implements SignalHandler {
		public void handle(Signal signal)
		{
			System.out.println("Saving the configuration ...");
			final GlobalConfig config = GlobalConfig.getInstance();

			try {
				config.storeStateRecursive();
			}
			catch (IOException ex) {
				System.out.println("Error while saving the data: " + ex.
						getLocalizedMessage());
			}

			config.getCCNHandle().close();
			System.exit(0);
		}
	}
}
