package webClient.backEnd;

import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.ccnx.ccn.CCNFilterListener;
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.ContentObject;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;

/**
 * This class grabs the current configuration settings for a datastream and allows
 * the PDV to express interests in new settings
 * 
 * @author Alexander Bonomo
 */
public class PDCConfig implements CCNFilterListener
{
    /**
     * this class is just here to prevent compilation errors. It should probably
     * be implemented in the PDC itself.
     * 
     */
    public class ConfigSettings
    {

    }

    private CCNHandle _ccnHandle;
    private ContentName _namespace;

    private ConfigSettings _settings;
    
    /**
     * Constructor
     * @param namespace - the namespace to use to grab the new configuration settings
     * @throws MalformedContentNameStringException - if the namespace given is no good
     */
    public PDCConfig(String namespace) throws MalformedContentNameStringException
    {
        //get a handle and a content name
        this._ccnHandle = CCNHandle.getHandle();
        this._namespace = ContentName.fromURI(namespace);
    }

    /**
     * Begin listening for interests
     * 
     * @throws IOException
     */
    private void startListening() throws IOException
    {
        this._ccnHandle.registerFilter(_namespace, this);
    }
    
    /**
     * Handles interests for the new configuration settings
     * @param intrst - the interest
     * @return
     */
    public boolean handleInterest(Interest intrst)
    {
        byte[] settingBytes = this.convertSettingsToBytes(_settings);
        ContentObject coSettings = ContentObject.buildContentObject(_namespace, settingBytes);

        try
        {
            this._ccnHandle.put(coSettings);
        }
        catch (IOException ex)
        {
            Logger.getLogger(PDCConfig.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }


        return true;
    }

    /**
     * gets the current configuration settings for the data stream
     * @return - the current configuration settings
     */
    public ConfigSettings getCurrentConfigSettings()
    {
        //TODO
        return new ConfigSettings();
    }

    private byte[] convertSettingsToBytes(ConfigSettings settings)
    {
        //TODO
        return null;
    }
}
