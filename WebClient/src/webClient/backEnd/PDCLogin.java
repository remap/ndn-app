package webClient.backEnd;

import edu.ucla.cens.pdc.libpdc.stream.DataEncryptor;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCEncryptionException;
import java.io.IOException;
import java.security.InvalidKeyException;
import java.security.KeyPair;
import java.security.SignatureException;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.ccnx.ccn.CCNFilterListener;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.ContentObject;
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import webClient.frontEnd.WebClientServer;
import webClient.lib.Algorithms;
import edu.ucla.cens.pdc.libpdc.util.AuthenticationResponse;
import edu.ucla.cens.pdc.libpdc.util.WCCredentials;
import webClient.lib.Security;
import webClient.session.SessionManager;

/**
 * This class handles the logging in sequence that occurs between the web client
 * and the PDC/PDV instance.
 * @author Alexander Bonomo
 */
public class PDCLogin implements CCNFilterListener
{
    private CCNHandle _ccnHandle;
    private ContentName _namespace;

    private KeyPair _keys;

    private WCCredentials _credentials;
    
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

        //get public/private key pairs
        this._keys = Security.generateKeyPair(512);
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
        if(this._credentials == null)
            return false; //TODO correct return value?

        ContentObject coCredentials;
        try
        {
            //encrypt data
            //DataEncryptor encryptor = new DataEncryptor();
            //encryptor.setEncryptKey(null /* TODO: use PDV public key */);
            //byte[] encryptedBytes = encryptor.encryptRecord(this._credentials);
            coCredentials = ContentObject.buildContentObject(_namespace, this._credentials.toBSON());

            //sign data
            coCredentials.sign(this._keys.getPrivate());
        }
        catch (InvalidKeyException ex)
        {
            Logger.getLogger(PDCLogin.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }
        catch (SignatureException ex)
        {
            Logger.getLogger(PDCLogin.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }

        try
        {
            this._ccnHandle.put(coCredentials);
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
    public boolean isUserAuthenticated(String pdv_uri, String userName, String password) throws PDCEncryptionException
    {
        return true;
        /* commented out until login functionality is implemented in the PDC
        try
        {
            //create the credentials
            this._credentials = new WCCredentials(userName, password, this._keys.getPublic());

            //start listening before we send just in case
            this.startListening();

            //TODO use signed interests
            String dottedNamespace = (WebClientServer.getNDNNamespace()).replace('/', '.');
            ContentObject ack = this._ccnHandle.get(ContentName.fromURI(pdv_uri +
                    "manage/login/" + dottedNamespace), WebClientServer.DEFAULT_TIMEOUT);

            //TODO check for null ack also verify ack

            ContentObject coIsAuthenticated = this._ccnHandle.get(
                    ContentName.fromURI(pdv_uri + "manage/login/isAuthenticated"),
                    WebClientServer.DEFAULT_TIMEOUT);

            AuthenticationResponse ar = decodeAuthorizationResponse(coIsAuthenticated);

            if(!ar.isAuthenticated())
                return false;

            //register a new session
            String userHash = Algorithms.md5HashStr(pdv_uri + userName + password);
            SessionManager.registerSession(userHash, ar.getSymmetricKey());
            SessionManager.getSession(userHash).setPDV_URI(pdv_uri);

            return true;
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
        //*/
    }

    /**
     * Takes a content object response from the PDV and converts it to a boolean value
     * @param response - the PDV's response as a content object
     * @return - the PDV's response as a boolean.
     */
    private AuthenticationResponse decodeAuthorizationResponse(ContentObject response) throws PDCEncryptionException
    {
        //decrypt response
        //DataEncryptor decryptor = new DataEncryptor();
        //decryptor.setDecryptKey(this._keys.getPrivate().getEncoded());
        byte[] bytes = response.content();//decryptor.decryptData(response.content());

        AuthenticationResponse ar = new AuthenticationResponse();
        ar.fromBSON(bytes);

        return ar;
    }//*/
}
