package webClient.ndn.test;

import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.config.ConfigurationException;
import org.ccnx.ccn.impl.CCNFlowControl.SaveType;
import org.ccnx.ccn.io.content.CCNStringObject;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.ContentObject;
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;

/**
 *
 * @author Alexander Bonomo
 */



public class NDNTest extends Thread
{
    private String _namespace;
    private String _content;

    private boolean _finished = false;
    private boolean _contentReady = false;
    
    private CCNStringObject _readString;
    private CCNStringObject _writeString;

    public NDNTest(String namespace)
    {
        this._namespace = namespace;
    }

    public String getContent()
    {
        return this._content;
    }

    public boolean isContentReady()
    {
        return this._contentReady;
    }

    public void listen() throws ConfigurationException, IOException, MalformedContentNameStringException
    {        
        CCNHandle tempReadHandle = CCNHandle.open();

        Interest i = new Interest(ContentName.fromURI(_namespace));
        ContentObject content = null;

        content = tempReadHandle.get(i, 10000);

        if(content != null)
            this._content = new String(content.content());
        this._contentReady = true;

        //CCNHandle tempWriteHandle = CCNHandle.open();

       /*
        _readString = new CCNStringObject(ContentName.fromURI(_namespace), (String)null, SaveType.RAW, tempReadHandle);
        _readString.updateInBackground(true);

        while(!_finished)
        {
            try
            {
                synchronized(_readString)
                {
                    _readString.wait(1000);
                }
            }
            catch(InterruptedException e){}

            if(_readString.isSaved())
            {
                this._content = _readString.string();
                _finished = true;
                this._contentReady = true;
            }
        }
        //*/
    }

    @Override
    public void run()
    {
        try {
            this.listen();
        } catch (ConfigurationException ex) {
            Logger.getLogger(NDNTest.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(NDNTest.class.getName()).log(Level.SEVERE, null, ex);
        } catch (MalformedContentNameStringException ex) {
            Logger.getLogger(NDNTest.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
