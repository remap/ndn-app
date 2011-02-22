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
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import pdc.DataRecord;
import webClient.session.SessionManager;

public class PDCDataRecords 
{
    private CCNHandle _ccnHandle;

    public PDCDataRecords(String namespace)
    {
        //get a handle and a content name
        this._ccnHandle = CCNHandle.getHandle();
    }

    public static Collection<DataRecord> getDataRecords(String userHash, String streamName)
    {
        String pdv_uri = SessionManager.getSession(userHash).getPdv_uri();

        //TODO get all data records at once or 1 at a time
        
        return new LinkedList<DataRecord>();
    }
}
