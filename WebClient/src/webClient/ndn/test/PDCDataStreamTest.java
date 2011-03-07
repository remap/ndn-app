package webClient.ndn.test;

import edu.ucla.cens.pdc.Application;
import edu.ucla.cens.pdc.MongoDataStream;
import edu.ucla.cens.pdc.libpdc.DataStream;
import edu.ucla.cens.pdc.libpdc.iApplication;
import edu.ucla.cens.pdc.libpdc.iDataStream;
import java.io.IOException;
import java.lang.String;
import java.util.Collection;
import java.util.LinkedList;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.ContentObject;
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import webClient.lib.BasicCCNFilterListenerImpl;
import webClient.lib.CollectionTransport;

/**
 *
 * @author Alexander Bonomo
 */
public class PDCDataStreamTest extends BasicCCNFilterListenerImpl implements Runnable
{
    static DataStream ds1;
    static DataStream ds2;
    static DataStream ds3;

    static TestApplication theApp;

    public PDCDataStreamTest(String namespace) throws MalformedContentNameStringException
    {
        super(namespace);
    }

    private void initialize(String appName)
    {
        theApp = (TestApplication) PDCAppsTest.getApp(appName);
   
        ds1 = new MongoDataStream(theApp, "1");
        ds2 = new MongoDataStream(theApp, "2");
        ds3 = new MongoDataStream(theApp, "3");

        //TODO this method signature should accept type iDataStream instead of DataStream
        theApp.addDataStream(ds1);
        theApp.addDataStream(ds2);
        theApp.addDataStream(ds3);
    }

    @Override
    public boolean handleInterest(Interest intrst)
    {
        System.out.println("Received Interest.");

        //get the postfix which should be the app name
        ContentName root, name, postfix;
        root = TestPDVInstance.getNamespace();
        name = intrst.name();
        postfix = name.postfix(root);

        String strAppName = postfix.toString();
        if(strAppName.startsWith("/"))
            strAppName = strAppName.substring(1);
        initialize(strAppName);

        //get the collection to transport over the network
        CollectionTransport<String> ctDataStreams = new CollectionTransport<String>(theApp.listDataStreams());

        ContentObject coApps = ContentObject.buildContentObject(m_namespace, ctDataStreams.toBSON());
        try
        {
            this.m_ccnHandle.put(coApps);
        }
        catch (IOException ex)
        {
            Logger.getLogger(PDCDataStreamTest.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }
        return true;
    }

    public void run()
    {
        try
        {
            this.startListening();
        }
        catch (IOException ex)
        {
            Logger.getLogger(PDCDataStreamTest.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
