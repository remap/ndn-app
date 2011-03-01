/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc;

import edu.ucla.cens.pdc.libpdc.DataRecord;
import edu.ucla.cens.pdc.libpdc.DataStream;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCDatabaseException;
import edu.ucla.cens.pdc.libpdc.transport.PDCPublisher;
import edu.ucla.cens.pdc.libpdc.transport.PDCReceiver;
import java.io.IOException;
import java.util.Date;
import java.util.logging.Level;
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
			for (double i = 0; i < 10; i++) {
				DataRecord dr = new DataRecord();
				dr.put("date", new Date());
				dr.put("type", 1);
				dr.put("latitude", i);
				dr.put("longitude", 123.3974);
				ds.getStorage().insertRecord(dr);
			}
		}
		catch (PDCDatabaseException ex) {
			throw new Error("Unable to populate the database", ex);
		}
	}

	/**
	 * @param args the command line arguments
	 */
	public static void main(String[] args)
					throws MalformedContentNameStringException, IOException,
					ConfigurationException
	{
		byte[] key = new byte[]{'t', 'e', 's', 't', 'k', 'e', 'y', 0};
		Application n1_app, n2_app = null;
		DataStream n1_ds, n2_ds = null;
		NDNetwork test = null;

		if (args.length != 1)
			usage();

		String uri = args[0];
		PDCConfigStore config = PDCConfigStore.getInstance();

		PDCPublisher node1 = new PDCPublisher("ccnx:/pdv1");
		PDCReceiver node2 = new PDCReceiver("ccnx:/pdv2");

		//Disable annoying ccnx debug messages
		Log.setDefaultLevel(Log.FAC_ALL, Level.WARNING);

		if (uri.equals("database"))
			test = new NDNetwork(node1.uri.toURIString());
		else
			test = new NDNetwork(args[0]);

		if (uri.equals(node1.uri.toURIString())) {
			config.setRoot(node1.uri);
			Database.setPrefix("pdv1_");

			n1_app = new Application("myapp");
			n1_ds = new MongoDataStream(n1_app, "myacl");
			n1_ds.getEncryptor().setEncryptKey(key.clone());
			n1_ds.addReceiver(node2);

			n1_app.data_stream_add(n1_ds);
			config.addApplication(n1_app);
		} else if (uri.equals(node2.uri.toURIString())) {
			config.setRoot(node2.uri);
			Database.setPrefix("pdv2_");

			n2_app = new Application("myapp");
			n2_ds = new MongoDataStream(n2_app, "myacl");
			n2_ds.getEncryptor().setDecryptKey(key.clone());
			n2_ds.setPublisher(node1, "myacl");

			n2_app.data_stream_add(n2_ds);
			config.addApplication(n2_app);
		} else if (uri.equals("database")) {
			Database.setPrefix("pdv1_");
			Application app = new Application("myapp");
			DataStream ds = new MongoDataStream(app, "myacl");
//			ds.key = key.clone();
			app.data_stream_add(ds);
			config.addApplication(app);
			fillDatabase(ds);
			System.exit(0);
		} else {
			edu.ucla.cens.pdc.libpdc.util.Log.error("Unknown URI");
			System.exit(10);
		}

		test.startListening();

//		if (uri.equals(node2.uri.toURIString()))
//			n2_ds.periodicPullStart(5000);
	}
}
