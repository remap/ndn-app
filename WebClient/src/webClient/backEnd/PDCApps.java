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
import webClient.session.SessionManager;
import webClient.exceptions.NoSuchUserHashException;
import edu.ucla.cens.pdc.libpdc.transport.CollectionTransport;
import webClient.log.Log;
import webClient.session.Session;

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
    public Collection<String> getUserApps(String userHash) throws NoSuchUserHashException, PDCEncryptionException, IOException
    {
        //get the appropriate session
        Session session = SessionManager.getSession(userHash);
        if(session == null)
            throw new NoSuchUserHashException();

        //public key hash
        //PublicKey key = SessionManager.getSession(userHash).getPublicKey();
        //String pubKeyHash = new String(Algorithms.md5Hash(key.getEncoded())); //TODO set correct encoding?

        //<pdv_uri>/<WC_PUB_Key hash>/apps
        String uri = session.getPDV_URI() /*+ "/" + pubKeyHash*/ + "/manage/list/apps";

        ContentObject apps;
        try
        {
            Log.write("Sending interest for list of apps to: " + uri);
            //TODO can't use signed interests yet since they don't extend interests...
            //SignedInterest interest = session.getSignedInterest(uri);
            //apps = this._ccnHandle.get(interest, WebClientServer.DEFAULT_TIMEOUT); //COMPILE ERROR b/c SignedInterest does not extend Interest...
            apps = this._ccnHandle.get(ContentName.fromURI(uri), WebClientServer.DEFAULT_TIMEOUT);

            //decrypt data
            byte[] content = session.decryptData(apps.content());

            //convert to a collection and return
            CollectionTransport<String> ctApps = new CollectionTransport<String>();
            ctApps.fromBSON(content);
            return ctApps.toCollection();
        }
        catch (MalformedContentNameStringException ex)
        {
            //this should never happen unless base pdv uri is bad
            Logger.getLogger(PDCApps.class.getName()).log(Level.SEVERE, null, ex);
            Log.write("Bad PDV URI given!");
            return null;
        }
    }

}
