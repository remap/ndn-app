package webClient.ndn.test;

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
import webClient.lib.CollectionTransport;

/**
 *
 * @author Alexander Bonomo
 */
public class PDCAppsTest extends BasicCCNFilterListenerImpl
{
    private TestApplication app1;
    private TestApplication app2;
    private TestApplication app3;

    private LinkedHashMap<String, iApplication> apps = new LinkedHashMap<String, iApplication>();

    public PDCAppsTest(String namespace) throws MalformedContentNameStringException
    {
        super(namespace);

        try
        {
            app1 = new TestApplication("app1", namespace + "/app1");
            app2 = new TestApplication("app2", namespace + "/app2");
            app3 = new TestApplication("app3", namespace + "/app3");
        }
        catch (MalformedContentNameStringException ex)
        {
            Logger.getLogger(PDCAppsTest.class.getName()).log(Level.SEVERE, null, ex);
        }
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
    
    public static void main(String[] args)
    {
        String namespace;
        if(args.length > 0)
            namespace = args[0];
        else
            namespace = TestVars.PDV_NAMESPACE + "/apps";

        try
        {
            PDCAppsTest test = new PDCAppsTest(namespace);
            test.startListening();
        }
        catch (IOException ex)
        {
            Logger.getLogger(PDCAppsTest.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("Error when trying to start listening on the given namespace");
        }
        catch (MalformedContentNameStringException ex)
        {
            Logger.getLogger(PDCAppsTest.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("ERROR: Bad namespace.");
        }
    }
}
