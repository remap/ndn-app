package webClient.backEnd;

import java.io.IOException;
import org.ccnx.ccn.CCNFilterListener;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;

/**
 *
 * @author Alexander Bonomo
 */
public class PDCLogin implements CCNFilterListener
{
    private CCNHandle _ccnHandle;
    private ContentName _namespace;
    
    public PDCLogin(String namespace) throws MalformedContentNameStringException
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

}
