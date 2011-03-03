package webClient.backEnd;

import edu.ucla.cens.pdc.libpdc.DataRecord;
import java.io.IOException;
import java.util.Collection;
import java.util.LinkedList;
import org.ccnx.ccn.CCNFilterListener;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.ContentObject;
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import webClient.frontEnd.WebClientServer;
import webClient.session.SessionManager;

/**
 * This class grabs data records in a data stream from the PDC.
 * @author Alexander Bonomo
 */

public class PDCDataRecords 
{
    private CCNHandle _ccnHandle;

    public PDCDataRecords()
    {
        //get a handle and a content name
        this._ccnHandle = CCNHandle.getHandle();
    }

    /**
     * This function grabs the data records from a specified stream.
     *
     * @param userHash - session identifying user hash vaule
     * @return - a collection of data records
     * @throws IOException
     * @throws MalformedContentNameStringException
     */
    public Collection<DataRecord> getDataRecords(String userHash) throws IOException, MalformedContentNameStringException
    {
        String pdv_uri = SessionManager.getSession(userHash).getPDV_URI();

        String appName = "";//SessionManager.getSession(userHash).getCurrentApp().getName();

        //TODO append correct arguments to URI
        ContentObject coDataRecords = this._ccnHandle.get(ContentName.fromURI
                (pdv_uri + appName + PDCCommands.PULL_REQUEST), WebClientServer.DEFAULT_TIMEOUT);

        
        return new LinkedList<DataRecord>();
    }
}
