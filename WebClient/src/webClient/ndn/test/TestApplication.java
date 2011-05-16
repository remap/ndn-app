package webClient.ndn.test;

import com.mongodb.DBCollection;
import edu.ucla.cens.pdc.Database;
import edu.ucla.cens.pdc.libpdc.stream.DataStream;
import edu.ucla.cens.pdc.libpdc.iApplication;
import java.util.Collection;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import org.ccnx.ccn.protocol.PublisherPublicKeyDigest;

/**
 * This class is a very basic implementation of iApplication for testing purposes
 * @author Alexander Bonomo
 */
public class TestApplication implements iApplication {
	private String m_appName;

	private ContentName m_namespace;

	private LinkedHashMap<String, DataStream> m_dataStreams = new LinkedHashMap<String, DataStream>();

	/**
	 * Constructor
	 * @param appName - the name for the app
	 * @param namespace - the namespace for the app
	 * @throws MalformedContentNameStringException - thrown if the namespace given is bad
	 */
	public TestApplication(String appName, String namespace)
					throws MalformedContentNameStringException
	{
		this.m_appName = appName;
		this.m_namespace = ContentName.fromURI(namespace);
		//this.m_db = new Database(Database.db_type.DATA, appName);
	}

	public String getAppName()
	{
		return m_appName;
	}

	public ContentName getBaseName()
	{
		return this.m_namespace;
	}

	/**
	 * TODO don't know what this function is supposed to do...
	 * @param id
	 * @return
	 */
	public boolean isDataStream(String id)
	{
		throw new UnsupportedOperationException("Not supported yet.");
	}

	public DataStream getDataStream(String id)
	{
		return this.m_dataStreams.get(id);
	}

	public DataStream addDataStream(DataStream ds)
	{
		return this.m_dataStreams.put(ds.data_stream_id, ds);
	}

	/**
	 * TODO in my opinion, this should also be a method in the interface
	 * @return - list of data streams for this app
	 */
	public Collection<String> listDataStreams()
	{
		LinkedList<String> streams = new LinkedList<String>();
		for (DataStream ds : this.m_dataStreams.values())
			streams.add(ds.data_stream_id);
		return streams;
	}

	public DBCollection get_db_collection(String id)
	{
		return Database.getDatabase(Database.db_type.DATA, m_appName).getCollection(
						id);
	}

    public PublisherPublicKeyDigest getKeyDigest() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public void setKeyDigest(PublisherPublicKeyDigest digest) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
}
