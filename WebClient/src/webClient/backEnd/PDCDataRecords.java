package webClient.backEnd;

import edu.ucla.cens.pdc.libpdc.DataRecord;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCParseException;
import java.io.IOException;
import java.util.Arrays;
import java.util.Collection;
import java.util.LinkedList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
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
    public Collection<String> getDataRecordList(String userHash) throws IOException, MalformedContentNameStringException
    {
        String pdv_uri = SessionManager.getSession(userHash).getPDV_URI();

        String appName = "";//SessionManager.getSession(userHash).getCurrentApp().getName();
        String dsName = SessionManager.getSession(userHash).getCurrentDataStream().data_stream_id;

        //TODO append correct arguments (if any) to URI
        ContentObject coDataRecords = this._ccnHandle.get(ContentName.fromURI
                (pdv_uri + "/" + appName + "/" + dsName +
                PDCCommands.DATA_RECORD_LIST), WebClientServer.DEFAULT_TIMEOUT);

        //TODO decrypt and verify data
        byte[] data = coDataRecords.content();
        String dataStr = new String(data);
        String[] records = dataStr.split("\n");
        List recordList = Arrays.asList(records);

        return recordList;
    }
}
