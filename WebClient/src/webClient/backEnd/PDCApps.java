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
import pdc.Application;
import webClient.frontEnd.WebClientServer;
import webClient.session.SessionManager;

public class PDCApps
{
    private CCNHandle _ccnHandle;

    public PDCApps(String namespace) throws MalformedContentNameStringException
    {
        //get a handle and a content name
        this._ccnHandle = CCNHandle.getHandle();
    }

    public Collection<Application> getUserApps(String userHash) throws IOException, MalformedContentNameStringException
    {
        String pdv_uri = SessionManager.getSession(userHash).getPdv_uri();

        //TODO correct the URI
        ContentObject apps = this._ccnHandle.get(ContentName.fromURI(pdv_uri),
                WebClientServer.DEFAULT_TIMEOUT);

        return decodeAppCO(apps);
    }

    private Collection<Application> decodeAppCO(ContentObject apps)
    {
        //TODO
        return new LinkedList<Application>();
    }
}
