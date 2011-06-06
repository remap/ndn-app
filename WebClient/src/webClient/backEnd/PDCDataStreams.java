package webClient.backEnd;

import edu.ucla.cens.pdc.libpdc.exceptions.PDCEncryptionException;
import java.io.IOException;
import java.util.Collection;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.ContentObject;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import webClient.frontEnd.WebClientServer;
import edu.ucla.cens.pdc.libpdc.transport.CollectionTransport;
import webClient.log.Log;
import webClient.session.SessionManager;
import webClient.session.Session;

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
        Session session = SessionManager.getSession(userHash);
        String pdv_uri = session.getPDV_URI();

        Log.write("Retrieving data streams " + pdv_uri + "/manage/list/datastreams/" + appID);

        ContentObject streams = this._ccnHandle.get(ContentName.fromURI(pdv_uri + "/manage/list/datastreams/" + appID),
                WebClientServer.DEFAULT_TIMEOUT);

        if(streams == null) //communication error
            return null;

        byte[] content;
        try {
            content = session.decryptData(streams.content());
        } catch (PDCEncryptionException ex) {
            Logger.getLogger(PDCDataStreams.class.getName()).log(Level.SEVERE, null, ex);
            Log.write("ERROR: " + ex.getLocalizedMessage());
            return null;
        }
        CollectionTransport<String> ctDataStreams = new CollectionTransport<String>();
        ctDataStreams.fromBSON(content);
        return ctDataStreams.toCollection();
        
    }

}
