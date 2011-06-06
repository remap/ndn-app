package webClient.backEnd;

import edu.ucla.cens.pdc.libpdc.stream.DataEncryptor;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCEncryptionException;
import java.io.IOException;
import java.security.InvalidKeyException;
import java.security.KeyPair;
import java.security.NoSuchAlgorithmException;
import java.security.SignatureException;
import java.security.spec.InvalidKeySpecException;
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
import webClient.exceptions.NoPDVResponseException;
import edu.ucla.cens.pdc.libpdc.util.AuthenticationResponse;
import edu.ucla.cens.pdc.libpdc.util.EncryptionHelper;
import edu.ucla.cens.pdc.libpdc.util.WCCredentials;
import java.security.KeyFactory;
import java.security.PublicKey;
import java.security.spec.X509EncodedKeySpec;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;
import org.ccnx.ccn.config.SystemConfiguration;
import org.ccnx.ccn.config.UserConfiguration;
import webClient.lib.Security;
import webClient.log.Log;
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
    private static WCCredentials _credentials;
    private String _userHash;
    private PublicKey _pdvKey;

    /**
     * Constructor
     *
     * @param namespace - the namespace to use to put the user's credentials and
     * the web client's public key
     * @throws MalformedContentNameStringException - if the namespace given is no good
     */
    public PDCLogin(String namespace, String pdv_uri, String pdv_key, String userName, String password)
            throws MalformedContentNameStringException, NoPDVResponseException
    {
        //get a handle and a content name
        this._ccnHandle = CCNHandle.getHandle();
        this._namespace = ContentName.fromURI(namespace);

        //get public/private key pairs
        this._keys = Security.generateKeyPair(512);
        Log.write("WC's public key: " + Algorithms.bytesToHexStr(_keys.getPublic().getEncoded()));

        //convert the hex string representation of the key to a PublicKey object
        byte[] keyBytes = Algorithms.hexStrToBytes(pdv_key);
        _pdvKey = Algorithms.bytesToPubKey(keyBytes);
        Log.write("PDV public key: " + Algorithms.bytesToHexStr(_pdvKey.getEncoded()));

        //get the user hash value
        this._userHash = Algorithms.md5HashStr(pdv_uri + userName + password);

        //begin logon process
        this.startLogon(pdv_uri, userName, password);
    }

    public String getUserHash()
    {
        return this._userHash;
    }
    /**
     * Begin listening for interests on the namespace specified in the constructor
     * @throws IOException
     */
    public void startListening() throws IOException
    {
        Log.write("PDCLogin listening for interests to: " + this._namespace.toURIString());
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
        Log.write("Received interest: " + interest.toString());
        try
        {
            //encrypt and make the content object
            byte[] content = EncryptionHelper.encryptAsymData(_pdvKey, this._keys.getPublic().getEncoded());
            ContentObject coWCPubKey = ContentObject.buildContentObject(_namespace, content);

            //sign data
            coWCPubKey.sign(this._keys.getPrivate());            
            
            this._ccnHandle.put(coWCPubKey);
            
            Log.write("sent WC public key.");
        }
        catch (Exception ex)
        {
            Logger.getLogger(PDCLogin.class.getName()).log(Level.SEVERE, null, ex);
            Log.write(ex.getLocalizedMessage());
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
        try
        {
            ContentObject coIsAuthenticated = this._ccnHandle.get(
                    ContentName.fromURI(pdv_uri + "/manage/login/isAuthenticated/" + _userHash),
                    WebClientServer.DEFAULT_TIMEOUT);

            //check for null response
            if(coIsAuthenticated == null || coIsAuthenticated.content() == null)
            {
                Log.write("No response from PDV instance on status of login.");
                return false;
            }
            /*
            AuthenticationResponse ar = decodeAuthorizationResponse(coIsAuthenticated);

            if(ar == null || !ar.isAuthenticated())
                return false;
             */

            SecretKey symmKey = EncryptionHelper.unwrapKey(this._keys.getPrivate(), coIsAuthenticated.content());
            //SecretKey symmKey = (new SecretKeySpec(coIsAuthenticated.content(), "AES"));//EncryptionHelper.unwrapKey(this._keys.getPrivate(), coIsAuthenticated.content());
            
            //register a new session
            SessionManager.registerSession(_userHash, symmKey);
            SessionManager.getSession(_userHash).setPDV_URI(pdv_uri);

            Log.write("Successfully logged in. Session key: " + Algorithms.bytesToHexStr(symmKey.getEncoded()));

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

    private void startLogon(String pdv_uri, String userName, String password) throws NoPDVResponseException
    {
        try
        {
            //create the credentials
           this._credentials = new WCCredentials(userName, password, this._keys.getPublic());

            //start listening before we send just in case
            this.startListening();
            //encrypt and make the content object
            byte[] content = EncryptionHelper.encryptAsymData(_pdvKey, this._keys.getPublic().getEncoded());
            ContentObject coWCPubKey = ContentObject.buildContentObject(_namespace, content);

            //sign data
            coWCPubKey.sign(this._keys.getPrivate());

            this._ccnHandle.put(coWCPubKey);

            //TODO use signed interests

            String dottedNamespace = (WebClientServer.getNDNNamespace()).replace('/', '.');
            String interestURI = pdv_uri + "/manage/login/" + dottedNamespace + "/" + _userHash;
            Log.write("Sending interest to: " + interestURI);
            ContentObject ack = this._ccnHandle.get(ContentName.fromURI(interestURI), WebClientServer.DEFAULT_TIMEOUT);

            //check for null ack
            if (ack == null) {
                Log.write("No response from PDV instance to log in.");
                throw new NoPDVResponseException();
            }
        } catch (InvalidKeyException ex) {
            Logger.getLogger(PDCLogin.class.getName()).log(Level.SEVERE, null, ex);
        } catch (SignatureException ex) {
            Logger.getLogger(PDCLogin.class.getName()).log(Level.SEVERE, null, ex);
        } catch (PDCEncryptionException ex) {
            Logger.getLogger(PDCLogin.class.getName()).log(Level.SEVERE, null, ex);
        } catch (MalformedContentNameStringException ex) {
            Logger.getLogger(PDCLogin.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(PDCLogin.class.getName()).log(Level.SEVERE, null, ex);
        }
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
