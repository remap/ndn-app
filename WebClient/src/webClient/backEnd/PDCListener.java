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

public class PDCListener implements CCNFilterListener
{
    private CCNHandle _ccnHandle;
    private ContentName _namespace;

    private int _interestsHandled;

    public PDCListener(String namespace) throws MalformedContentNameStringException
    {
        this._ccnHandle = CCNHandle.getHandle();
        this._namespace = ContentName.fromURI(namespace);
        this._interestsHandled = 0;
        //TODO
    }

    public void startListening() throws IOException
    {
        _ccnHandle.registerFilter(this._namespace, this);
    }

    public boolean handleInterest(Interest interest)
    {
        //TODO
        this._interestsHandled++;
        return false;
    }

    public int interestsHandled()
    {
        return this._interestsHandled;
    }
}
