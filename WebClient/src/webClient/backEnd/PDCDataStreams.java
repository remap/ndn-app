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
import pdc.DataStream;

public class PDCDataStreams implements CCNFilterListener
{
    private CCNHandle _ccnHandle;
    private ContentName _namespace;

    public PDCDataStreams(String namespace) throws MalformedContentNameStringException
    {
        //get a handle and a content name
        this._ccnHandle = CCNHandle.getHandle();
        this._namespace = ContentName.fromURI(namespace);
    }

    public void startListening() throws IOException
    {
        _ccnHandle.registerFilter(this._namespace, this);
    }

    public boolean handleInterest(Interest intrst)
    {
        throw new UnsupportedOperationException("Not supported yet.");

        //TODO
    }

    public static Collection<DataStream> getDataStreams(String appName)
    {
        //TODO
        return new LinkedList<DataStream>();
    }
}
