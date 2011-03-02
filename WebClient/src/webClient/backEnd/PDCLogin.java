package webClient.backEnd;

import java.io.IOException;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.NoSuchAlgorithmException;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.ccnx.ccn.CCNFilterListener;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.ContentObject;
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import webClient.frontEnd.WebClientServer;

/**
 * This class handles the logging in sequence that occurs between the web client
 * and the PDC/PDV instance.
 * @author Alexander Bonomo
 */
public class PDCLogin implements CCNFilterListener
{
    private CCNHandle _ccnHandle;
    private ContentName _namespace;

    private String _usernamePassword;

    /**
     * Constructor
     *
     * @param namespace - the namespace to use to put the user's credentials and
     * the web client's public key
     * @throws MalformedContentNameStringException - if the namespace given is no good
     */
    public PDCLogin(String namespace) throws MalformedContentNameStringException
    {
        //get a handle and a content name
        this._ccnHandle = CCNHandle.getHandle();
        this._namespace = ContentName.fromURI(namespace);
    }

    /**
     * Begin listening for interests on the namespace specified in the constructor
     * @throws IOException
     */
    public void startListening() throws IOException
    {
        _ccnHandle.registerFilter(this._namespace, this);
    }

    /**
     * This function handles the interest for a user's credentials.
     *
     * @param interest - the interest for the user's credentials.
     * @return
     */
    public boolean handleInterest(Interest interest)
    {
        if(this._usernamePassword == null)
            return false; //TODO correct return value?

        //TODO may want to set to correct encoding
        //TODO also need to generate and include my public key in this data packet
        byte[] bytes = this._usernamePassword.getBytes(); //maybe use a hash value instead?
        ContentObject credentials = ContentObject.buildContentObject(_namespace, bytes);

        //TODO sign and encrypt this content object as well

        //TODO may want to use CCNFlowControl instead
        try
        {
            this._ccnHandle.put(credentials);
        }
        catch (IOException ex)
        {
            Logger.getLogger(PDCLogin.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }

        return true;
    }

    /**
     * This function takes a pdv instance and a username/password combination
     * and determines if the user is authenticated or not.
     * @param pdv_uri - the uri of the pdv instance
     * @param userName
     * @param password
     * @return - whether or not this username/password combination is valid for
     * this pdv instance.
     */
    public boolean isUserAuthenticated(String pdv_uri, String userName, String password)
    {
        try
        {
            this._usernamePassword = userName + " " + password;

            //start listening before we send just in case
            this.startListening();

            ContentObject ack = this._ccnHandle.get(ContentName.fromURI(pdv_uri +
                    "/<" + WebClientServer.getNDNNamespace() + ">"), WebClientServer.DEFAULT_TIMEOUT);

            //TODO check for null ack

            ContentObject coIsAuthenticated = this._ccnHandle.get(
                    ContentName.fromURI(pdv_uri + "/isAuthenticated"),
                    WebClientServer.DEFAULT_TIMEOUT);

            return decodeAuthorizationResponse(coIsAuthenticated);
        }
        catch (MalformedContentNameStringException ex)
        {
            Logger.getLogger(PDCLogin.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }
        catch (IOException ex)
        {
            Logger.getLogger(PDCLogin.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }
    }

    /**
     * Takes a content object response from the PDV and converts it to a boolean value
     * @param response - the PDV's response as a content object
     * @return - the PDV's response as a boolean.
     */
    private boolean decodeAuthorizationResponse(ContentObject response)
    {
        //TODO
        return true;
    }

    /**
     * Generates a public/private key combination.
     * @throws NoSuchAlgorithmException
     */
    private void generateKeys() throws NoSuchAlgorithmException
    {
        KeyPairGenerator kpg = KeyPairGenerator.getInstance("RSA");
        kpg.initialize(512);
        KeyPair kp = kpg.generateKeyPair();

    }
}
