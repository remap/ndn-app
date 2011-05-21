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
import edu.ucla.cens.pdc.libpdc.exceptions.PDCTransmissionException;
import edu.ucla.cens.pdc.libpdc.transport.PDCPublisher;
import edu.ucla.cens.pdc.libpdc.transport.PDCReceiver;
import edu.ucla.cens.pdc.libpdc.util.Log;
import java.io.IOException;
import java.security.InvalidKeyException;
import java.util.Date;
import java.util.logging.Level;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.config.ConfigurationException;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import org.ccnx.ccn.protocol.PublisherPublicKeyDigest;

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
		GlobalConfig config = GlobalConfig.getInstance();
		CCNHandle handle;
		byte[] key = new byte[]{'t', 'e', 's', 't', 'k', 'e', 'y', 0};
		Application n1_app = null, n2_app = null;
		DataStream n1_ds = null, n2_ds = null;

		PDCPublisher node1 = new PDCPublisher("ccnx:/ucla.edu/apps/pdv1");
		PDCReceiver node2 = new PDCReceiver("ccnx:/ucla.edu/apps/pdv2");

		handle = config.getCCNHandle();

		if (pdv_started == 1) {
			config.setRoot(node1.uri);

			n1_app = new Application("myapp", false);
			n1_ds = new DataStream(handle, n1_app, "myds", false);
//			n1_ds.getTransport().getEncryptor().setEncryptKey(key.clone());
			n1_ds.addReceiver(node2);

			n1_app.addDataStream(n1_ds);
			config.addApplication(n1_app);
		} else if (pdv_started == 2) {
			config.setRoot(node2.uri);

			n2_app = new Application("myapp", false);
			n2_ds = new DataStream(handle, n2_app, "myds", false);
//			n2_ds.getTransport().getEncryptor().setDecryptKey(key.clone());
			n2_ds.setPublisher(node1);

			n2_app.addDataStream(n2_ds);
			config.addApplication(n2_app);
		} else if (pdv_started == -1) {
			config.setRoot(node1.uri);
			Application app = new Application("myapp", false);
			DataStream ds = new DataStream(handle, app, "myds", false);
//			ds.key = key.clone();
			app.addDataStream(ds);
			config.addApplication(app);
		}

	}

	/**
	 * @param args the command line arguments
	 */
	@SuppressWarnings("fallthrough")
	public static void main(String[] args)
			throws MalformedContentNameStringException, IOException,
			ConfigurationException, PDCTransmissionException, PDCDatabaseException,
			InvalidKeyException
	{
		GlobalConfig config;
		int pdv_started = 0;
		boolean RESTORE_CONFIG = true;
		final boolean SAVE_CONFIG = true;
		PDVInstance test = null;
		PublisherPublicKeyDigest digest = null;

		if (args.length < 1)
			usage();

		if (args.length >= 2)
			digest = new PublisherPublicKeyDigest(args[1]);

		String arg = args[0];

		if (arg.equals("pdv1"))
			pdv_started = 1;
		else if (arg.equals("pdv2"))
			pdv_started = 2;
		else if (arg.equals("database"))
			pdv_started = -1;
		else {
			Log.error("Unknown command");
			System.exit(10);
		}

		if (pdv_started == 1 || pdv_started == -1) {
			MongoDataStorage.setPrefix("pdv1_");
			MongoConfigStorage.setPrefix("pdv1_");
		} else if (pdv_started == 2) {
			MongoDataStorage.setPrefix("pdv2_");
			MongoConfigStorage.setPrefix("pdv2_");
		}

		GlobalConfig.setFeatures(GlobalConfig.FEAT_SHARING
				| GlobalConfig.FEAT_MANAGE);
		GlobalConfig.setConfigStorage(MongoConfigStorage.class);
		GlobalConfig.setDataStorage(MongoDataStorage.class);

		//Disable annoying ccnx debug messages
		org.ccnx.ccn.impl.support.Log.setDefaultLevel(
				org.ccnx.ccn.impl.support.Log.FAC_ALL, Level.WARNING);

		if (RESTORE_CONFIG) {
			config = GlobalConfig.loadState();
			if (config == null) {
				Log.warning("No stored configuration found setting up ...");
				config = GlobalConfig.getInstance();
				RESTORE_CONFIG = false;
			}
		} else
			config = GlobalConfig.getInstance();

		if (!RESTORE_CONFIG)
			setupPDV(pdv_started);

		if (pdv_started > 0)
			test = new PDVInstance();

		Log.debug(config.toString());
		if (SAVE_CONFIG)
			config.storeStateRecursive();

		DataStream ds = config.getApplication("myapp").getDataStream("myds");
		switch (pdv_started) {
		case -1:
			fillDatabase(ds);
			System.exit(0);
		case 1:
			if (digest != null) {
				Log.debug("Setting up pdv2's key");
				PDCReceiver receiver = ds.getReceivers().iterator().next();
				receiver.setPublickeyDigest(digest);
				ds.storeStateRecursive();
			}
		/* fallthrough */
		case 2:
			final PublisherPublicKeyDigest dsdigest = ds.getTransport().getEncryptor().
					getStreamKeyDigest();
			Log.info("myds key: " + dsdigest.toString());
		}

		test.startListening();

		Log.debug("Listening");

		if (pdv_started == 1) {
			final PDCReceiver receiver = ds.getReceivers().iterator().next();
			if (args.length >= 3)
				ds.setupReceiver(receiver, args[2]);
		} else if (pdv_started == 2) {
			final PDCPublisher publisher = ds.getPublisher();
			final String authenticator = ds.setupPublisher(publisher);
			Log.info("Authenticator for the publisher: " + authenticator);

//			config.getApplication("myapp").periodicPullStart(5);

//			//first one will fail, but it'll obtain an encryption key
//			config.getApplication("myapp").getDataStream("myds").getTransport().
//					fetchDataFromUplink();
//			config.getApplication("myapp").getDataStream("myds").getTransport().
//					fetchDataFromUplink();
		}
	}
}
