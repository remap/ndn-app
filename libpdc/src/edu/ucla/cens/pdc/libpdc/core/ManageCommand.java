/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc.core;

import edu.ucla.cens.pdc.libpdc.Application;
import edu.ucla.cens.pdc.libpdc.Constants;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCDatabaseException;
import edu.ucla.cens.pdc.libpdc.iDataStream;
import edu.ucla.cens.pdc.libpdc.transport.CollectionTransport;
import edu.ucla.cens.pdc.libpdc.util.AuthenticationResponse;
import edu.ucla.cens.pdc.libpdc.util.Log;
import edu.ucla.cens.pdc.libpdc.util.WCCredentials;
import java.io.IOException;
import java.util.Collection;
import java.util.Set;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.ccnx.ccn.config.SystemConfiguration;
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
public class ManageCommand extends GenericCommand
{    
    //ManageCommand constants
    public static final String LIST_CMD    = "list";
    public static final String LOGIN_CMD   = "login";
    public static final String STR_APPS    = "apps";
    public static final String STR_DS      = "datastreams";
    public static final String STR_DR      = "datarecords";
    public static final String STR_isAuth  = "isAuthenticated";

    //private member variables
    private GlobalConfig _globalConfig;
    private WCCredentials _credentials;

    public ManageCommand()
    {
        super(Constants.STR_MANAGE);
        _globalConfig   = GlobalConfig.getInstance();
        _credentials    = new WCCredentials();
    }

    /* Commands:
     * 
     * /list/apps
     * /list/datastreams/<app_name>
     * /list/datarecords/<app_name>/<datastream_name>
     *
     * /login/<dottedWC>
     * /login/isAuthenticated
     */

    @Override
    boolean processCommand(ContentName postfix, Interest interest)
    {
        //make sure there is a command
        if (postfix.count() == 0)
        {
            Log.error("No subcommand!");
            return false;
	}

        //check if it's the list command
        if(postfix.stringComponent(0).equals(LIST_CMD))
            return handleListCmd(postfix, interest);

        //check for login command
        if(postfix.stringComponent(0).equals(LOGIN_CMD))
            return handleLoginCmd(postfix, interest);

        //more commands here...

        //if we get here, the command isn't supported
        return false;
    }

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
            ContentObject co = ContentObject.buildContentObject(interest.name(), ctApps.toBSON());
            try {
                _globalConfig.getCCNHandle().put(co);
            } catch (IOException ex) {
                Logger.getLogger(ManageCommand.class.getName()).log(Level.SEVERE, null, ex);
            }
            //TODO use communication helper for encryption

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
            CollectionTransport<String> ctDS = new CollectionTransport<String>(dataStreams);
            ContentObject co = ContentObject.buildContentObject(interest.name(), ctDS.toBSON());
            try {
                _globalConfig.getCCNHandle().put(co);
            } catch (IOException ex) {
                Logger.getLogger(ManageCommand.class.getName()).log(Level.SEVERE, null, ex);
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
                ContentObject co = ContentObject.buildContentObject(interest.name(), ctDRList.toBSON());
                this._globalConfig.getCCNHandle().put(co);
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
            if(this._credentials == null)
            {
                try {
                    Thread.sleep(SystemConfiguration.MEDIUM_TIMEOUT);
                } catch (InterruptedException ex) {
                    Logger.getLogger(ManageCommand.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
            if(this._credentials == null)
                return false;

            //TODO use CommunicationHelper
            AuthenticationResponse ar = new AuthenticationResponse(true);
            ContentObject co = ContentObject.buildContentObject(interest.name(), ar.toBSON());
            try {
                this._globalConfig.getCCNHandle().put(co);
            } catch (IOException ex) {
                Logger.getLogger(ManageCommand.class.getName()).log(Level.SEVERE, null, ex);
            }

            return true;
        }

        //otherwise the final string component will have the dotted WC namespace
        try 
        {
            //send ack
            ContentObject co = ContentObject.buildContentObject(interest.name(), null);
            this._globalConfig.getCCNHandle().put(co);

            //send interest
            String wcNamespace = postfix.stringComponent(1).replace('.', '/');
            ContentObject coCredentials = this._globalConfig.getCCNHandle().get(
                    ContentName.fromURI(wcNamespace + "/login"), SystemConfiguration.MEDIUM_TIMEOUT);

            //TODO decrypt with private key...

            _credentials = _credentials.fromBSON(coCredentials.content());

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
}
