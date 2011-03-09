package webClient.ndn.test;

import java.util.logging.Level;
import java.util.logging.Logger;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;

/**
 *
 * @author Alexander Bonomo
 */
public class TestPDVInstance
{
    private static ContentName cnNamespace;

    public static ContentName getNamespace()
    {
        return cnNamespace;
    }

    public static void main(String[] args)
    {
        //set up the namespace
        String namespace;
        if(args.length > 0)
            namespace = args[0];
        else
            namespace = TestVars.PDV_NAMESPACE;
        try
        {
            cnNamespace = ContentName.fromURI(namespace);
        }
        catch (MalformedContentNameStringException ex)
        {
            Logger.getLogger(TestPDVInstance.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("ERROR: bad namespace");
        }

        //set up portions of PDV instance
        PDCAppsTest         appsTest;
        PDCDataStreamTest   dsTest;
        try
        {
            appsTest    = new PDCAppsTest       (namespace + "/apps");
            dsTest      = new PDCDataStreamTest (namespace + "/datastreams");
        }
        catch (MalformedContentNameStringException ex)
        {
            Logger.getLogger(TestPDVInstance.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("FATAL ERROR: bad namespace");
            return;
        }

        (new Thread(appsTest)).start();
        (new Thread(dsTest)).start();
    }
}
