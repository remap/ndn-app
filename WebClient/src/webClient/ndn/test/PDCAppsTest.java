package webClient.ndn.test;

import edu.ucla.cens.pdc.libpdc.Application;
import edu.ucla.cens.pdc.libpdc.iApplication;
import java.io.IOException;
import java.util.Collection;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.ccnx.ccn.protocol.ContentObject;
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import webClient.lib.BasicCCNFilterListenerImpl;
import edu.ucla.cens.pdc.libpdc.transport.CollectionTransport;

/**
 * This class simulates the PDV app listing functionality
 * @author Alexander Bonomo
 */
public class PDCAppsTest extends BasicCCNFilterListenerImpl implements Runnable
{
    static TestApplication app1;
    static TestApplication app2;
    static TestApplication app3;

    private LinkedHashMap<String, iApplication> apps = new LinkedHashMap<String, iApplication>();

    public PDCAppsTest(String namespace) throws MalformedContentNameStringException
    {
        super(namespace);

        app1 = new TestApplication("app1", namespace + "/app1");
        app2 = new TestApplication("app2", namespace + "/app2");
        app3 = new TestApplication("app3", namespace + "/app3");
        
        apps.put(app1.getAppName(), app1);
        apps.put(app2.getAppName(), app2);
        apps.put(app3.getAppName(), app3);
    }


    public boolean handleInterest(Interest intrst)
    {
        System.out.println("Received Interest.");
        CollectionTransport<String> ctApps = new CollectionTransport<String>(this.listApps());

        ContentObject coApps = ContentObject.buildContentObject(this.m_namespace, ctApps.toBSON());
        try
        {
            this.m_ccnHandle.put(coApps);
        }
        catch (IOException ex)
        {
            Logger.getLogger(PDCAppsTest.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }
        return true;
    }
    
    public Collection<String> listApps()
    {
        LinkedList<String> appList = new LinkedList<String>();

        for(iApplication a : apps.values())
        {
            appList.add(a.getAppName());
        }

        return appList;
    }

    static iApplication getApp(String appName)
    {
        if(appName.equalsIgnoreCase("app1"))
            return app1;
        else if(appName.equalsIgnoreCase("app2"))
            return app2;
        else if(appName.equalsIgnoreCase("app3"))
            return app3;
        else
            return null;
    }

    public void run()
    {        
        try
        {
            this.startListening();
        }
        catch (IOException ex)
        {
            Logger.getLogger(PDCAppsTest.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("Error when trying to start listening on the given namespace");
        }
    }
}
