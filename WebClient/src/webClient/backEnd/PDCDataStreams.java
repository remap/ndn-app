package webClient.backEnd;

import edu.ucla.cens.pdc.libpdc.DataStream;
import java.io.IOException;
import java.util.Collection;
import java.util.LinkedList;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.ContentObject;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import webClient.frontEnd.WebClientServer;
import webClient.lib.CollectionTransport;
import webClient.session.SessionManager;

/**
 * This class grabs a list of all the data streams for a particular app.
 * @author Alexander Bonomo
 */

public class PDCDataStreams 
{
    private CCNHandle _ccnHandle;

    public PDCDataStreams()
    {
        //get a handle and a content name
        this._ccnHandle = CCNHandle.getHandle();
    }

    /**
     * Gets the list of data streams.
     * @param userHash - the userHash value identifying the session
     * @param appName - the app name
     * @return - a collection of data streams
     * @throws IOException
     * @throws MalformedContentNameStringException
     */
    public Collection<String> getDataStreams(String userHash, String appID) throws IOException, MalformedContentNameStringException
    {
        String pdv_uri = SessionManager.getSession(userHash).getPDV_URI();

        //TODO add wc public key hash to the URI
        ContentObject streams = this._ccnHandle.get(ContentName.fromURI(pdv_uri + "/" + appID),
                WebClientServer.DEFAULT_TIMEOUT);

        return decodeStreamsCO(streams);
    }

    /**
     * Decodes the returned ContentObject into a list of DataStreams
     * @param streams - the content object returned by the PDV
     * @return - the list of available data streams
     */
    private Collection<String> decodeStreamsCO(ContentObject streams)
    {
        CollectionTransport<String> ctDataStreams = new CollectionTransport<String>();
        ctDataStreams.fromBSON(streams.content());
        return ctDataStreams.toCollection();
    }
}
