/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc;

import edu.ucla.cens.pdc.libpdc.core.PDVInstance;
import edu.ucla.cens.pdc.libpdc.Application;
import edu.ucla.cens.pdc.libpdc.GlobalConfig;
import edu.ucla.cens.pdc.libpdc.DataRecord;
import edu.ucla.cens.pdc.libpdc.DataStream;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCDatabaseException;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCTransmissionException;
import edu.ucla.cens.pdc.libpdc.transport.PDCPublisher;
import edu.ucla.cens.pdc.libpdc.transport.PDCReceiver;
import java.io.IOException;
import java.security.InvalidKeyException;
import java.util.Date;
import java.util.logging.Level;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.config.ConfigurationException;
import org.ccnx.ccn.impl.support.Log;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;

/**
 *
 * @author Derek Kulinski
 */
public class Main {
	static void usage()
	{
		System.err.printf("Usage: pdc.jar <uri>\n");
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
				Log.info("Record {0} added.", i);
			}
		}
		catch (PDCDatabaseException ex) {
			throw new Error("Unable to populate the database", ex);
		}
	}

	static void setupPDV(int pdv_started)
					throws MalformedContentNameStringException
	{
		GlobalConfig config = GlobalConfig.getInstance();
		CCNHandle handle;
		byte[] key = new byte[]{'t', 'e', 's', 't', 'k', 'e', 'y', 0};
		Application n1_app = null, n2_app = null;
		DataStream n1_ds = null, n2_ds = null;

		PDCPublisher node1 = new PDCPublisher("ccnx:/ucla.edu/apps/pdv1", "myds");
		PDCReceiver node2 = new PDCReceiver("ccnx:/ucla.edu/apps/pdv2");

		handle = CCNHandle.getHandle();

		if (pdv_started == 1) {
			config.setRoot(node1.uri);

			n1_app = new Application("myapp");
			n1_ds = new DataStream(handle, n1_app, "myds");
			n1_ds.getTransport().getEncryptor().setEncryptKey(key.clone());
			n1_ds.addReceiver(node2);

			n1_app.addDataStream(n1_ds);
			config.addApplication(n1_app);
		} else if (pdv_started == 2) {
			config.setRoot(node2.uri);

			n2_app = new Application("myapp");
			n2_ds = new DataStream(handle, n2_app, "myds");
			n2_ds.getTransport().getEncryptor().setDecryptKey(key.clone());
			n2_ds.setPublisher(node1);

			n2_app.addDataStream(n2_ds);
			config.addApplication(n2_app);
		} else if (pdv_started == -1) {
			config.setRoot(node1.uri);
			Application app = new Application("myapp");
			DataStream ds = new DataStream(handle, app, "myds");
//			ds.key = key.clone();
			app.addDataStream(ds);
			config.addApplication(app);
		}

	}

	/**
	 * @param args the command line arguments
	 */
	public static void main(String[] args)
					throws MalformedContentNameStringException, IOException,
					ConfigurationException, PDCTransmissionException, PDCDatabaseException,
					InvalidKeyException
	{
		GlobalConfig config;
		int pdv_started = 0;
		boolean restore = false;
		PDVInstance test = null;

		if (args.length != 1)
			usage();

		String uri = args[0];

		if (uri.equals("ccnx:/ucla.edu/apps/pdv1"))
			pdv_started = 1;
		else if (uri.equals("ccnx:/ucla.edu/apps/pdv2"))
			pdv_started = 2;
		else if (uri.equals("database"))
			pdv_started = -1;
		else {
			Log.severe("Unknown URI");
			System.exit(10);
		}

		if (pdv_started == 1 || pdv_started == -1) {
			MongoStorage.setPrefix("pdv1_");
			MongoConfigStorage.setPrefix("pdv1_");
		} else if (pdv_started == 2) {
			MongoStorage.setPrefix("pdv2_");
			MongoConfigStorage.setPrefix("pdv2_");
		}

		GlobalConfig.setConfigStorage(MongoConfigStorage.class);
		GlobalConfig.setDataStorage(MongoStorage.class);

		//Disable annoying ccnx debug messages
		Log.setDefaultLevel(Log.FAC_ALL, Level.WARNING);

		if (restore) {
			config = GlobalConfig.loadState();
			if (config == null) {
				Log.warning("No stored configuration found setting up ...");
				config = GlobalConfig.getInstance();
				restore = false;
			}
		} else
			config = GlobalConfig.getInstance();

		if (!restore)
			setupPDV(pdv_started);

		if (pdv_started > 0)
			test = new PDVInstance();

		edu.ucla.cens.pdc.libpdc.util.Log.debug(config.toString());

		if (pdv_started == -1) {
			DataStream ds = config.getApplication("myapp").getDataStream("myds");
			fillDatabase(ds);
			System.exit(0);
		}

		test.startListening();

		edu.ucla.cens.pdc.libpdc.util.Log.debug("Listening");

		if (pdv_started == 2)
			config.getApplication("myapp").periodicPullStart(5);
	}
}
