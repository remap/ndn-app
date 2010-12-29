/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pdc;

import com.mongodb.DBCollection;
import com.mongodb.MongoException;
import com.mongodb.WriteConcern;
import java.io.IOException;
import java.util.Date;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.ccnx.ccn.config.ConfigurationException;
import org.ccnx.ccn.impl.support.Log;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;

/**
 *
 * @author takeda
 */
public class Main {

	static void usage()
	{
		System.err.printf("Usage: pdc.jar <uri>\n");
		System.exit(10);
	}

	static void fillDatabase(Application app)
	{
		try {
			Database datastore = new Database(Database.db_type.DATA, app.name);
			DBCollection col = datastore.getDatabase().getCollection("myacl");

			for (int i = 0; i < 10; i++) {
				DataRecord dr = new DataRecord(1, new Date());
				dr.put("lat", i);
				dr.put("long", 123.3974);

				col.insert(dr, WriteConcern.SAFE);
			}
		} catch (MongoException ex) {
			Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
		}
	}

	/**
	 * @param args the command line arguments
	 */
	public static void main(String[] args)
					throws MalformedContentNameStringException, IOException,
					ConfigurationException
	{
		if (args.length != 1)
			usage();

		String uri = args[0];
		PDCConfigStore config = PDCConfigStore.get_instance();

		PDVNode node1 = new PDVNode("ccnx:/pdv1");
		PDVNode node2 = new PDVNode("ccnx:/pdv2");

		Application app = new Application("myapp");
		app.data_stream_set_key("myacl",
						new byte[]{'t', 'e', 's', 't', 'k', 'e', 'y', 0});
		config.addApplication(app);

		if (uri.equals(node1._uri.toURIString())) {
			app.set_node(Application.NodeType.DOWNLINKS,
							Application.Operation.ADD, node2);
			Database.setPrefix("pdv1_");
		} else if (uri.equals(node2._uri.toURIString())) {
			app.set_node(Application.NodeType.UPLINKS,
							Application.Operation.ADD, node1);
			Database.setPrefix("pdv2_");
		} else if (uri.equals("database")) {
			Database.setPrefix("pdv1_");
			fillDatabase(app);
			System.exit(0);
		} else {
			System.out.println("Unknown URI");
			System.exit(10);
		}

		Log.setDefaultLevel(Log.FAC_ALL, Level.WARNING);
		NDNetwork test = new NDNetwork(args[0]);
		test.startListening();
		if (uri.equals(node2._uri.toURIString()))
			PDCReplicator.get_instance().callPull(node1._uri, "myapp", "myacl",
							"4d14593b02542724083d823e", "4d14593b025427240f3d823e");

	}
}
