package webClient.backEnd;

import edu.ucla.cens.pdc.libpdc.core.ManageCommand;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCEncryptionException;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.io.IOException;
import java.util.Collection;
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

    public boolean addDataStream(String userHash, String dsName)
    {
        try
        {
            Session session = SessionManager.getSession(userHash);
            String pdv_uri = session.getPDV_URI();
            String app = session.getCurrentApp();
            ContentName name = ContentName.fromURI(pdv_uri + "/manage/" + ManageCommand.ADD_CMD + "/" + ManageCommand.STR_DS + "/" + app + "/" + dsName);
            ContentObject ack = this._ccnHandle.get(name, WebClientServer.DEFAULT_TIMEOUT);
                       
            if (ack == null)
            {
                return false;
            }

            byte[] content = session.decryptData(ack.content());

            if(content != null)
                return true;
        }
        catch (PDCEncryptionException ex) {
            Log.write(ex.getLocalizedMessage());
        }
        catch (IOException ex) {
            Log.write(ex.getLocalizedMessage());
        }
        catch (MalformedContentNameStringException ex) {
            Log.write(ex.getLocalizedMessage());
        }

        //if we get here, an exception was thrown
        return false;
    }

    public boolean setPublisher(String userHash, String publisherURI)
    {
        try 
        {
            Session session = SessionManager.getSession(userHash);
            //get the app name and datastream name
            String appName = session.getCurrentApp();
            String dsName = session.getCurrentDataStream();
            String uri = session.getPDV_URI() + "/manage/" + ManageCommand.SET_PUBLISHER_CMD + "/" + appName + "/" + dsName + "/" + publisherURI;
            ContentName name = ContentName.fromURI(uri);
            ContentObject ack = this._ccnHandle.get(name, WebClientServer.DEFAULT_TIMEOUT);

            //make sure ack is valid
            if(ack == null) return false;
            byte[] decryptedAck = session.decryptData(ack.content());
            if(decryptedAck == null) return false;

            return true;
        }
        catch (PDCEncryptionException ex) {
            Logger.getLogger(PDCDataStreams.class.getName()).log(Level.SEVERE, null, ex);
        }        catch (IOException ex) {
            Log.write(ex.getLocalizedMessage());
        }
        catch (MalformedContentNameStringException ex) {
            Log.write(ex.getLocalizedMessage());
        }

        //if we get here, an exception was thrown
        return false;
    }

    public boolean addReceiver(String userHash, String receiverURI)
    {
        try {
            Session session = SessionManager.getSession(userHash);
            //get the app name and ds name
            String app = session.getCurrentApp();
            String ds = session.getCurrentDataStream();
            String uri = session.getPDV_URI() + "/manage/add/receiver/" + app + "/" + ds + "/" + receiverURI;
            ContentName name = ContentName.fromURI(uri);
            ContentObject ack = this._ccnHandle.get(name, WebClientServer.DEFAULT_TIMEOUT);

            //make sure ack is good
            if(ack == null) return false;
            byte[] ackBytes = session.decryptData(ack.content());
            if(ackBytes == null) return false;

            return true;
        } catch (PDCEncryptionException ex) {
            Log.write(ex.getLocalizedMessage());
        } catch (IOException ex) {
            Log.write(ex.getLocalizedMessage());
        } catch (MalformedContentNameStringException ex) {
            Log.write(ex.getLocalizedMessage());
        }

        //if we get here, an exception was thrown
        return false;
    }
}
