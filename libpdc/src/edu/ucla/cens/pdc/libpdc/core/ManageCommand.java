/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc.core;

import edu.ucla.cens.pdc.libpdc.Application;
import edu.ucla.cens.pdc.libpdc.Constants;
import edu.ucla.cens.pdc.libpdc.transport.CollectionTransport;
import edu.ucla.cens.pdc.libpdc.util.Log;
import java.io.IOException;
import java.util.Set;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.ContentObject;
import org.ccnx.ccn.protocol.Interest;

/**
 *
 * @author Derek Kulinski, Alexander Bonomo
 */
public class ManageCommand extends GenericCommand
{
    //ManageCommand constants
    public static final String LIST_CMD    = "list";
    public static final String STR_APPS    = "apps";
    public static final String STR_DS      = "datastreams";
    
    /*
     * Root: <PDV>/manage/...
     */

    public ManageCommand()
    {
        super(Constants.STR_MANAGE);
    }

    /* Commands:
     * 
     * /list/apps
     * /list/datastreams/<app_name>
     *
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

        //more commands here...

        //if we get here, the command isn't supported
        return false;
    }

    private boolean handleListCmd(ContentName postfix, Interest interest)
    {
        GlobalConfig globalConfig = GlobalConfig.getInstance();

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
            Set<String> apps = globalConfig.getAppList();
            
            //send it across the network
            CollectionTransport<String> ctApps = new CollectionTransport<String>(apps);
            ContentObject co = ContentObject.buildContentObject(interest.name(), ctApps.toBSON());
            try {
                globalConfig.getCCNHandle().put(co);
            } catch (IOException ex) {
                Logger.getLogger(ManageCommand.class.getName()).log(Level.SEVERE, null, ex);
            }
            //TODO use communication helper for encryption

            return true;
        }

        //make sure there are enough components in the postfix for datastreams
        if(postfix.count() < 3)
        {
            Log.error("Cannot list DataStreams. No app specified.");
            return false;
        }

        //datastreams
        if(postfix.stringComponent(1).equals(STR_DS))
        {
            Log.info("Received list datastreams command for " + postfix.stringComponent(2));
            
            //get the list of data streams
            String appName          = postfix.stringComponent(2);
            Application app         = globalConfig.getApplication(appName);
            Set<String> dataStreams = app.getDataStreamList();

            Log.info("Sending back list: " + dataStreams.toString());
            
            //send it across the network
            CollectionTransport<String> ctDS = new CollectionTransport<String>(dataStreams);
            ContentObject co = ContentObject.buildContentObject(interest.name(), ctDS.toBSON());
            try {
                globalConfig.getCCNHandle().put(co);
            } catch (IOException ex) {
                Logger.getLogger(ManageCommand.class.getName()).log(Level.SEVERE, null, ex);
            }

            //TODO use communication helper for encryption

            return true;
        }

        //if we get here, the command isn't supported
        return false;
    }
}
