package webClient.session;

import edu.ucla.cens.pdc.libpdc.DataEncryptor;
import edu.ucla.cens.pdc.libpdc.DataStream;
import edu.ucla.cens.pdc.libpdc.SignedInterest;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCEncryptionException;
import edu.ucla.cens.pdc.libpdc.iApplication;
import java.security.KeyPair;
import java.security.NoSuchAlgorithmException;
import java.security.PublicKey;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import webClient.lib.Security;

/**
 * This class represents the user's session once they have successfully logged in
 * @author Alexander Bonomo
 */
public class Session
{
    public Session()
    {
        this.keyPair = Security.generateKeyPair(512);
    }

    ////////////////////////////////////////////////////////////////////////////

    /**
     * The URI of the PDV instance
     */
    private String pdv_uri;

    /**
     * PDV instance URI getter
     * @return - the URI of the PDV instance as a String
     */
    public String getPDV_URI()
    {
        return pdv_uri;
    }

    /**
     * PDV instance URI setter
     * @param pdv_uri - the URI of the PDV instance
     */
    public void setPDV_URI(String pdv_uri)
    {
        this.pdv_uri = pdv_uri;
    }

    ////////////////////////////////////////////////////////////////////////////

    /**
     * Possible actions the user could currently be doing.
     */
    public static enum CurrentAction
    {
        DOWNLOAD,
        CONFIGURE,
        UPLOAD
    }

    private CurrentAction currentAction;

    /**
     * Gets the current action.
     * @return - returns null if no action has been selected yet.
     */
    public CurrentAction getCurrentAction()
    {
        return this.currentAction;
    }

    /**
     * Set the current action
     * @param ca - the current action to be set
     */
    public void setCurrentAction(CurrentAction ca)
    {
        this.currentAction = ca;
    }

    /**
     * Resets the current action, current application, and current data stream
     * to null.
     *
     * This should only be called from the home page, or when the web client
     * wants to go back to the home page or earlier.
     */
    public void resetCurrentAction()
    {
        this.currentAction = null;
        this.appID = null;
        this.currentDS = null;
    }

    ////////////////////////////////////////////////////////////////////////////

    /**
     * The current application the user has selected
     */
    private String appID;

    /**
     * Gets the current application the user has selected
     * @return - the current app
     */
    public String getCurrentApp()
    {
        return this.appID;
    }

    /**
     * Sets the current app to what the user has selected
     * @param appID - the selected app
     */
    public void setCurrentApp(String appID)
    {
        this.appID = appID;
    }

    ////////////////////////////////////////////////////////////////////////////

    /**
     * The current data stream the user has selected
     */
    private String currentDS;

    public String getCurrentDataStream()
    {
        return this.currentDS;
    }

    public void setCurrentDataStream(String ds)
    {
        this.currentDS = ds;
    }

    ////////////////////////////////////////////////////////////////////////////

    private String requestedRecord;

    public String getRequestedRecord()
    {
        return this.requestedRecord;
    }

    public void requestRecord(String record_id)
    {
        this.requestedRecord = record_id;
    }

    ////////////////////////////////////////////////////////////////////////////

    /**
     * The public / private key pair for the session
     */
    private KeyPair keyPair;

    public PublicKey getPublicKey()
    {
        return this.keyPair.getPublic();
    }

    /**
     * Generate a signed interest for the uri specified
     * @param uri - the uri to express interest in
     * @return - the signed interest
     * @throws MalformedContentNameStringException - if the uri given is no good
     */
    public SignedInterest getSignedInterest(String uri) throws MalformedContentNameStringException
    {
        try 
        {
            SignedInterest theInterest = new SignedInterest(keyPair.getPrivate());
            //TODO: not 100% sure if this is how you use signed interests
            theInterest.signName(ContentName.fromURI(uri));
            return theInterest;
        } 
        catch (NoSuchAlgorithmException ex) 
        {
            /*
             * TODO: this should be caught in the constructor as it should never
             * happen anyway, unless the algorithm is passed as a parameter
             */
            Logger.getLogger(Session.class.getName()).log(Level.SEVERE, null, ex);
            return null;
        }
    }
    //TODO function to sign a packet w/ private key

    public byte[] decryptBytes(byte[] bytes) throws PDCEncryptionException
    {
        DataEncryptor decryptor = new DataEncryptor();
        decryptor.setDecryptKey(keyPair.getPrivate().getEncoded());
        return decryptor.decryptData(bytes);
    }

    ////////////////////////////////////////////////////////////////////////////
}
