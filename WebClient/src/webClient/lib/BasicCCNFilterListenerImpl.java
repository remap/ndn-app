package webClient.lib;

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
public abstract class BasicCCNFilterListenerImpl implements CCNFilterListener
{
    protected CCNHandle m_ccnHandle;
    protected ContentName m_namespace;

    /**
     * Constructor
     * @param namespace - the namespace to listen on
     * @throws MalformedContentNameStringException - if the namespace given is no good
     */
    public BasicCCNFilterListenerImpl(String namespace) throws MalformedContentNameStringException
    {
        //get a handle and a content name
        this.m_ccnHandle = CCNHandle.getHandle();
        this.m_namespace = ContentName.fromURI(namespace);
    }

    /**
     * Begin listening for interests on the namespace specified in the constructor
     * @throws IOException
     */
    public void startListening() throws IOException
    {
        this.m_ccnHandle.registerFilter(this.m_namespace, this);
    }

    public abstract boolean handleInterest(Interest intrst);

}
