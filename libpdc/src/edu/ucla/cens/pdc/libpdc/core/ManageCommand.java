package edu.ucla.cens.pdc.libpdc.core;

import edu.ucla.cens.pdc.libpdc.Application;
import edu.ucla.cens.pdc.libpdc.Constants;
import edu.ucla.cens.pdc.libpdc.datastructures.DataRecord;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCDatabaseException;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCEncryptionException;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCTransmissionException;
import edu.ucla.cens.pdc.libpdc.iApplication;
import edu.ucla.cens.pdc.libpdc.iDataStream;
import edu.ucla.cens.pdc.libpdc.stream.DataStream;
import edu.ucla.cens.pdc.libpdc.transport.CollectionTransport;
import edu.ucla.cens.pdc.libpdc.transport.CommunicationHelper;
import edu.ucla.cens.pdc.libpdc.transport.PDCPublisher;
import edu.ucla.cens.pdc.libpdc.transport.PDCReceiver;
import edu.ucla.cens.pdc.libpdc.util.EncryptionHelper;
import edu.ucla.cens.pdc.libpdc.util.Log;
import edu.ucla.cens.pdc.libpdc.util.MiscFuncs;
import edu.ucla.cens.pdc.libpdc.util.WCCredentials;
import java.io.IOException;
import java.security.KeyFactory;
import java.security.NoSuchAlgorithmException;
import java.security.PublicKey;
import java.security.spec.InvalidKeySpecException;
import java.security.spec.X509EncodedKeySpec;
import java.util.Collection;
import java.util.Set;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.crypto.SecretKey;
import org.ccnx.ccn.config.SystemConfiguration;
import org.ccnx.ccn.config.UserConfiguration;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.ContentObject;
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;

/**
 * Handles the manage command postfix
 *
 * Root: <PDV>/manage/...
 *
 * @author Derek Kulinski, Alexander Bonomo
 */
public class ManageCommand extends GenericCommand {
	//ManageCommand constants
        public static final String ADD_CMD = "add";

	public static final String LIST_CMD = "list";

	public static final String LOGIN_CMD = "login";

	public static final String CONTENT_CMD = "getcontent";

        public static final String REMOVE_CMD = "remove";

        public static final String SET_PUBLISHER_CMD = "set_publisher";

	public static final String STR_APPS = "apps";

	public static final String STR_DS = "datastreams";

	public static final String STR_DR = "datarecords";

	public static final String STR_isAuth = "isAuthenticated";

        public static final String STR_Receiver = "receiver";

	//private member variables
	private GlobalConfig _globalConfig;

	private WCCredentials _credentials;

	private PublicKey _wcPubKey;

	public ManageCommand()
	{
		super(Constants.STR_MANAGE);
		_globalConfig = GlobalConfig.getInstance();
		_credentials = new WCCredentials();
	}

	/* Commands:
	 *
         * /add/apps/<app_name>
         * /add/datastreams/<app_name>/<datastream_name>
         * /add/receiver/<app_name>/<datastream_name>/<receiver_uri>
         *
         * /getcontent/<app_name>/<ds_name>/<data_id>
         *
	 * /list/apps
	 * /list/datastreams/<app_name>
	 * /list/datarecords/<app_name>/<datastream_name>
	 *
	 * /login/<dottedWC>/<user_hash>
	 * /login/isAuthenticated/<user_hash>
         *
         * /remove/datastreams/<app_name>/<datastream_name>
         *
         * /set_publisher/<app_name>/<datastream_name>/<publisher_uri>
         * 
	 */
	@Override
	boolean processCommand(ContentName postfix, Interest interest)
	{
		//make sure there is a command
		if (postfix.count() == 0) {
			Log.error("No subcommand!");
			return false;
		}

		//check if it's the list command
		if (postfix.stringComponent(0).equals(LIST_CMD))
			return handleListCmd(postfix, interest);

		//check for login command
		if (postfix.stringComponent(0).equals(LOGIN_CMD))
			return handleLoginCmd(postfix, interest);

                //check for content command
		if (postfix.stringComponent(0).equals(CONTENT_CMD))
			return handleContentCmd(postfix.subname(1, postfix.count() - 1), interest);

                //check for add command
                if(postfix.stringComponent(0).equals(ADD_CMD))
                    return handleAddCmd(postfix.subname(1, postfix.count()-1), interest);

                //check for remove command
                //if(postfix.stringComponent(0).equals(REMOVE_CMD))
                //    return handleRemoveCmd(postfix.subname(1, postfix.count()-1), interest);

                //check for set publisher command
                if(postfix.stringComponent(0).equals(SET_PUBLISHER_CMD))
                    return handleSetPubCmd(postfix.subname(1, postfix.count()-1), interest);

		//more commands here...

		//if we get here, the command isn't supported
		return false;
	}

    /**
     * Handle list command
     * @param postfix
     * @param interest
     * @return
     */
    private boolean handleListCmd(ContentName postfix, Interest interest)
    {
        //make sure there are enough components in the postfix
        if(postfix.count() < 2)
        {
            Log.error("No subcommand after /list/");
            return false;
        }

        //apps
        if(postfix.stringComponent(1).equals(STR_APPS))
        {
            Log.info("Received list apps command");
            
            //get the app list
            Set<String> apps = _globalConfig.getAppList();
            
            //send it across the network
            CollectionTransport<String> ctApps = new CollectionTransport<String>(apps);
            byte[] content;
            //encrypt data
            try {
                content = EncryptionHelper.encryptSymData(this._globalConfig.getKeyManager().getWCSymmKey(), ctApps.toBSON());
            } catch (PDCEncryptionException ex) {
                Log.error(ex);
                return false;
            }
            
            ContentObject co = ContentObject.buildContentObject(interest.name(), content);
            try {
                _globalConfig.getCCNHandle().put(co);
            } catch (IOException ex) {
                Logger.getLogger(ManageCommand.class.getName()).log(Level.SEVERE, null, ex);
            }

            return true;
        }

        //make sure there are enough components in the postfix for datastreams
        if(postfix.count() < 3)
        {
            Log.error("Cannot perform list command. Not enough arguments.");
            return false;
        }

        //datastreams
        if(postfix.stringComponent(1).equals(STR_DS))
        {
            Log.info("Received list datastreams command for " + postfix.stringComponent(2));
            
            //get the list of data streams
            String appName          = postfix.stringComponent(2);
            Application app         = _globalConfig.getApplication(appName);
            Set<String> dataStreams = app.getDataStreamList();

            Log.info("Sending back list: " + dataStreams.toString());
            
            //send it across the network
            try
            {
                CollectionTransport<String> ctDS = new CollectionTransport<String>(dataStreams);
                byte[] content = EncryptionHelper.encryptSymData(this._globalConfig.getKeyManager().getWCSymmKey(), ctDS.toBSON());
                ContentObject co = ContentObject.buildContentObject(interest.name(), content);
                _globalConfig.getCCNHandle().put(co);
            } catch (PDCEncryptionException ex) {
                Logger.getLogger(ManageCommand.class.getName()).log(Level.SEVERE, null, ex);
                Log.error(ex.getLocalizedMessage());
            } catch (IOException ex) {
                Logger.getLogger(ManageCommand.class.getName()).log(Level.SEVERE, null, ex);
                Log.error(ex.getLocalizedMessage());
            }

            //TODO use communication helper for encryption

            return true;
        }

        //datarecords
        if(postfix.stringComponent(1).equals(STR_DR))
        {
            //make sure there are enough components in the postfix
            if(postfix.count() < 4)
            {
                Log.error("Cannot perform list command. Not enough arguments.");
                return false;
            }

            Log.info("Received list data record command.");
            
            //grab arguments needed to list the data records
            String appName  = postfix.stringComponent(2);
            String dsName   = postfix.stringComponent(3);
            Application app = this._globalConfig.getApplication(appName);
            iDataStream ds  = app.getDataStream(dsName);

            //get the data record list and publish it
            try
            {
                //the data records
                Collection<String> drList = ds.getStorage().getRangeIds();
                CollectionTransport<String> ctDRList = new CollectionTransport<String>(drList);
                byte[] content = EncryptionHelper.encryptSymData(this._globalConfig.getKeyManager().getWCSymmKey(), ctDRList.toBSON());
                ContentObject co = ContentObject.buildContentObject(interest.name(), content);
                this._globalConfig.getCCNHandle().put(co);
            } 
            catch (PDCEncryptionException ex) {
                Logger.getLogger(ManageCommand.class.getName()).log(Level.SEVERE, null, ex);
                Log.error(ex);
            }
            catch (IOException ex)
            {
                Logger.getLogger(ManageCommand.class.getName()).log(Level.SEVERE, null, ex);
                Log.error(ex);
            }
            catch (PDCDatabaseException ex)
            {
                Logger.getLogger(ManageCommand.class.getName()).log(Level.SEVERE, null, ex);
                Log.error(ex);
            }

            return true;
        }

        //if we get here, the command isn't supported
        return false;
    }

    /**
     * Handle login commands
     * @param postfix
     * @param interest
     * @return
     *
     * /login/<WC_URI>/<user_hash>
     * /login/isAuthenticated/<user_hash>
     */
    private boolean handleLoginCmd(ContentName postfix, Interest interest)
    {
        //make sure there are enough components in the postfix
        if(postfix.count() < 2)
        {
            Log.error("No subcommand after /login/");
            return false;
        }

        if(postfix.stringComponent(1).equals(STR_isAuth))
        {
            try
            {
                if(this._wcPubKey == null)
                {
                    try {
                        Thread.sleep(SystemConfiguration.MEDIUM_TIMEOUT);
                    } catch (InterruptedException ex) {
                        Logger.getLogger(ManageCommand.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
                if(this._wcPubKey == null)
                {
                    Log.error("WC public key not yet known.");
                    return false;
                }
                //TODO use CommunicationHelper
                //AuthenticationResponse ar = new AuthenticationResponse(true);
                SecretKey symmKey = this._globalConfig.getKeyManager().getWCSymmKey();
                if(symmKey == null)
                {
                    symmKey = EncryptionHelper.generateSymKey();
                    this._globalConfig.getKeyManager().addWCSymmKey(symmKey);
                }

                MiscFuncs.printKeyToLog(symmKey, "Symmetric key: ");
                byte[] content = EncryptionHelper.wrapKey(_wcPubKey, symmKey);
                ContentObject co = ContentObject.buildContentObject(interest.name(), content);//symmKey.getEncoded());

                this._globalConfig.getCCNHandle().put(co);
                

                return true;
            } catch (IOException ex) {
                Logger.getLogger(ManageCommand.class.getName()).log(Level.SEVERE, null, ex);
            } catch (PDCEncryptionException ex) {
                Logger.getLogger(ManageCommand.class.getName()).log(Level.SEVERE, null, ex);
            }

            return false;
        }

        //otherwise the next string component will have the dotted WC namespace
        try 
        {
            //send ack
            String ack = "ACK";
            ContentObject co = ContentObject.buildContentObject(interest.name(), ack.getBytes());
            this._globalConfig.getCCNHandle().put(co);

            //send interest
            String wcNamespace = "ccnx:";
            for(int i = 1; i < postfix.count() - 1; i++)
                wcNamespace += "/" + postfix.stringComponent(i);
            Log.info("Sending interest for credentials: " + wcNamespace + "/login");
            ContentObject coWCPubKey = this._globalConfig.getCCNHandle().get(
                    ContentName.fromURI(wcNamespace + "/login"), SystemConfiguration.MEDIUM_TIMEOUT);

            if(coWCPubKey == null)
            {
                Log.warning("No credentials received from Web Client.");
                return false;
            }

            byte[] wcPubKeyBytes = EncryptionHelper.decryptAsymData(this._globalConfig.getKeyManager().getKeysForWC().getPrivate(), coWCPubKey.content());
            X509EncodedKeySpec pubKeySpec = new X509EncodedKeySpec(wcPubKeyBytes);
            KeyFactory keyFactory = KeyFactory.getInstance(UserConfiguration.defaultKeyAlgorithm());
            this._wcPubKey = keyFactory.generatePublic(pubKeySpec);
            
            //_credentials.fromBSON(coWCPubKey.content());
            Log.info("WC PublicKey Received: " + _wcPubKey);
        } 
        catch (InvalidKeySpecException ex)
        {
            Logger.getLogger(ManageCommand.class.getName()).log(Level.SEVERE, null, ex);
            Log.error(ex.getLocalizedMessage());
        }
        catch (NoSuchAlgorithmException ex)
        {
            Logger.getLogger(ManageCommand.class.getName()).log(Level.SEVERE, null, ex);
            Log.error(ex.getLocalizedMessage());
        }        
        catch (PDCEncryptionException ex)
        {
            Logger.getLogger(ManageCommand.class.getName()).log(Level.SEVERE, null, ex);
            Log.error(ex.getLocalizedMessage());
        }
        catch (MalformedContentNameStringException ex)
        {
            Logger.getLogger(ManageCommand.class.getName()).log(Level.SEVERE, null, ex);
            Log.error(ex.getLocalizedMessage());
        }
        catch (IOException ex)
        {
            Logger.getLogger(ManageCommand.class.getName()).log(Level.SEVERE, null, ex);
            Log.error(ex.getLocalizedMessage());
        }

        return true;
    }

	private boolean handleContentCmd(ContentName postfix, Interest interest)
	{
		if (postfix.count() != 3) {
			Log.error("Invalid arguments to getcontent command");
			return false;
		}

		final String s_app = postfix.stringComponent(0);
		final String s_ds = postfix.stringComponent(1);
		final String data_id = postfix.stringComponent(2);

		final Application app = _globalConfig.getApplication(s_app);
		if (app == null) {
			Log.error("No app " + s_app);
			return false;
		}

		final DataStream ds = app.getDataStream(s_ds);
		if (ds == null) {
			Log.error("No ds " + s_ds);
			return false;
		}
		try {
			final DataRecord record = ds.getStorage().getRecord(data_id);
			if (record == null) {
				Log.error("No record " + data_id);
				return false;
			}

			byte[] content = EncryptionHelper.encryptSymData(_globalConfig.getKeyManager().getWCSymmKey(), record.toBSON());
                        ContentObject co = ContentObject.buildContentObject(interest.name(), content);
                        _globalConfig.getCCNHandle().put(co);
		}
                catch (IOException ex) {
                    Log.error(ex);
                    return false;
                }
                catch (PDCEncryptionException ex) {
                    Log.error(ex);
                    return false;
                }
		catch (PDCDatabaseException ex) {
			Log.error("Unable to fetch the data from the database: " + ex.
					getLocalizedMessage());
			return false;
		}

		return true;
	}

    /**
     * Handles add command
     *
     * @param postfix
     * @param interest
     * @return
     *
     * /add/apps/<app_name>
     * /add/datastreams/<app_name>/<datastream_name>
     * /add/receiver/<app_name>/<datastream_name>/<receiver_uri>
     *
     */
    private boolean handleAddCmd(ContentName postfix, Interest interest)
    {
        //make sure there are more postifx components
        if(postfix.count() == 0)
        {
            Log.error("No subcommand after add.");
            return false;
        }

        //get the prefix
        int count = interest.name().count() - postfix.count() - 1;
        ContentName prefix = interest.name().cut(count);

        //if we're adding an app
        if(postfix.stringComponent(0).equals(STR_APPS))
        {
            if(postfix.count() < 2)
                return false;

            String appName = postfix.stringComponent(1);
            try
            {
                Application app = new Application(appName);
                this._globalConfig.addApplication(app);

                //re-list applications
                ContentName listAppCmd = ContentName.fromURI("/" + LIST_CMD + "/" + this.STR_APPS);
                Interest listAppInt = new Interest(prefix.append(listAppCmd));
                handleListCmd(listAppCmd, listAppInt);

                return this.putAck(interest.name());
            }
            catch (MalformedContentNameStringException ex) {
                Log.error(ex.getLocalizedMessage());
                return false;
            }
            catch (IOException ex)
            {
                Log.error(ex.getLocalizedMessage());
                return false;
            }

        }

        //if we're adding a datastream
        if(postfix.stringComponent(0).equals(STR_DS))
        {
            //make sure there's enough subcomponents
            if(postfix.count() < 3)
            {
                Log.error("Not enough subcomponents");
                return false;
            }

            //get the app
            iApplication app = this._globalConfig.getApplication(postfix.stringComponent(1));
            if(app == null)
            {
                //TODO send some response back saying app DNE
                Log.error("could not retrieve application");
                return false;
            }

            try
            {
                DataStream newStream = new DataStream(this._globalConfig.getCCNHandle(), app, postfix.stringComponent(2));
                app.addDataStream(newStream);
                return putAck(interest.name());
            }
            catch (IOException ex)
            {
                //TODO send back an error message
                Log.error(ex.getLocalizedMessage());
                return false;
            }
        }

        //check to see if we're adding a receiver
        if(postfix.stringComponent(0).equals(STR_Receiver))
        {
            if(postfix.count() < 4)
                return false;

            //get the app and datastream
            String appName      = postfix.stringComponent(1);
            String dsName       = postfix.stringComponent(2);
            iApplication app    = this._globalConfig.getApplication(appName);
            iDataStream ds      = app.getDataStream(dsName);

            //get the URI of the receiver
            String receiver_uri = "";
            for(int i = 3; i < postfix.count(); i++)
                receiver_uri += "/" + postfix.stringComponent(i);

            //create the receiver and add it to the datastream
            PDCReceiver receiver;
            try {
                receiver = new PDCReceiver(receiver_uri);
            } catch (MalformedContentNameStringException ex) {
                Log.error(ex.getLocalizedMessage());
                return false;
            }
            ds.addReceiver(receiver);

            this.putAck(interest.name());

            return true;
        }

        return false;
    }

    /**
     * Handles remove command
     *
     * @param postfix
     * @param interest
     * @return
     *
     * /remove/datastreams/<app_name>/<datastream_name>
     *
     */
    /*private boolean handleRemoveCmd(ContentName postfix, Interest interest)
    {
        //check for no subcommands
        if(postfix.count() == 0)
            return false;

        //check for remove datastream
        if(postfix.stringComponent(0).equals(STR_DS))
        {
            //make sure enough components in postfix
            if(postfix.count() < 3)
                return false;

            //get the application and datastream to remove
            String appName = postfix.stringComponent(1);
            Application app = this._globalConfig.getApplication(appName);
            String dataStream = postfix.stringComponent(2);

            //app.


        }

        return false;
    }*/

    /**
     * handle set publisher command
     *
     * @param postfix
     * @param interest
     * @return
     *
     * /set_publisher/<app_name>/<datastream_name>/<publisher_uri>
     */
    private boolean handleSetPubCmd(ContentName postfix, Interest interest)
    {
        //make sure enough information is provided
        if(postfix.count() < 3)
            return false;
        
        //get the application
        String app_name = postfix.stringComponent(0);
        iApplication app = this._globalConfig.getApplication(app_name);

        //get the datastream
        String ds_name = postfix.stringComponent(1);
        iDataStream ds = app.getDataStream(ds_name);

        //build the publisher uri
        String publisher_uri = "";
        for(int i = 2; i < postfix.count(); i++)
            publisher_uri += "/" + postfix.stringComponent(i);

        //create and set the publisher
        PDCPublisher publisher;
        try {
            publisher = new PDCPublisher(publisher_uri);
        } catch (MalformedContentNameStringException ex) {
            Log.error(ex.getLocalizedMessage());
            return false;
        }
        ds.setPublisher(publisher);

        this.putAck(interest.name());

        return true;
    }

    private boolean putAck(ContentName name)
    {
        try {
            String ack = "ACK";
            byte[] content = EncryptionHelper.encryptSymData(this._globalConfig.getKeyManager().getWCSymmKey(), ack.getBytes());
            ContentObject co = ContentObject.buildContentObject(name, content);
            this._globalConfig.getCCNHandle().put(co);
            return true;
        } catch (IOException ex) {
            Log.error(ex.getLocalizedMessage());
            return false;
        } catch (PDCEncryptionException ex) {
            Log.error(ex.getLocalizedMessage());
            return false;
        }
    }
}
