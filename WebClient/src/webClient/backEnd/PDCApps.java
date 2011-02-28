package webClient.backEnd;

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

/**
 *
 * @author Alexander Bonomo
 *
 * This class connects to the PDV instance and grabs the collection of applications
 * available to the user on this PDV instance.
 */


public class PDCApps
{
    private CCNHandle _ccnHandle;

    public PDCApps()
    {
        //get a handle and a content name
        this._ccnHandle = CCNHandle.getHandle();
    }

    /**
     * Function that grabs the collection of apps available to this user on this
     * PDV instance.
     * 
     * @param userHash - the user hash value to identify the session
     * @return the collection of apps available to this user
     * @throws IOException
     * @throws MalformedContentNameStringException
     */
    public Collection<Application> getUserApps(String userHash) throws IOException, MalformedContentNameStringException
    {
        String pdv_uri = SessionManager.getSession(userHash).getPdv_uri();

        //TODO correct the URI
        ContentObject apps = this._ccnHandle.get(ContentName.fromURI(pdv_uri),
                WebClientServer.DEFAULT_TIMEOUT);

        return decodeAppCO(apps);
    }

    /**
     * Decodes a content object into a collection of apps
     * @param apps - the content object to decode
     * @return - the collection of Apps
     */
    private Collection<Application> decodeAppCO(ContentObject apps)
    {
        //TODO
        return new LinkedList<Application>();
    }
}
