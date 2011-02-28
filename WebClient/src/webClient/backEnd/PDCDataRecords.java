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
import pdc.DataRecord;
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
     * @param streamName
     * @return - a collection of data records
     * @throws IOException
     * @throws MalformedContentNameStringException
     */
    public Collection<DataRecord> getDataRecords(String userHash, String streamName) throws IOException, MalformedContentNameStringException
    {
        String pdv_uri = SessionManager.getSession(userHash).getPdv_uri();

        String appName = "temp"; //TODO

        //TODO append correct arguments to URI
        ContentObject coDataRecords = this._ccnHandle.get(ContentName.fromURI
                (pdv_uri + appName + PDCCommands.PULL_REQUEST), WebClientServer.DEFAULT_TIMEOUT);

        //TODO get all data records at once or 1 at a time
        
        return new LinkedList<DataRecord>();
    }
}
