package webClient.backEnd;

/**
 *
 * @author Alexander Bonomo
 */

import java.io.IOException;
import java.util.Collection;
import java.util.LinkedList;
import org.ccnx.ccn.CCNFilterListener;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.ContentObject;
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import pdc.DataStream;
import webClient.frontEnd.WebClientServer;
import webClient.session.SessionManager;

public class PDCDataStreams 
{
    private CCNHandle _ccnHandle;

    public PDCDataStreams()
    {
        //get a handle and a content name
        this._ccnHandle = CCNHandle.getHandle();
    }

    public Collection<DataStream> getDataStreams(String userHash, String appName) throws IOException, MalformedContentNameStringException
    {
        String pdv_uri = SessionManager.getSession(userHash).getPdv_uri();

        //TODO correct the URI
        ContentObject streams = this._ccnHandle.get(ContentName.fromURI(pdv_uri),
                WebClientServer.DEFAULT_TIMEOUT);

        return decodeStreamsCO(streams);
    }

    private Collection<DataStream> decodeStreamsCO(ContentObject streams)
    {
        //TODO
        return new LinkedList<DataStream>();
    }
}
