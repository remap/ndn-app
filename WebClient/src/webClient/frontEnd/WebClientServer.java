package webClient.frontEnd;

import org.eclipse.jetty.server.Server;
import org.eclipse.jetty.servlet.ServletContextHandler;
import org.eclipse.jetty.servlet.ServletHolder;
import org.eclipse.jetty.servlet.ServletContextHandler;
import webClient.log.Log;
import webClient.ndn.test.NDNTestServlet;

/**
 * This class holds the main function of the web client which sets up all the servlets
 * @author Alexander Bonomo
 */
public class WebClientServer
{
    public static final long DEFAULT_TIMEOUT = 10000;

    private static int port         = 8081;
    private static String namespace = "/ucla/edu/webclient";

    public static String getNDNNamespace()
    {
        return namespace;
    }
    
    public static void main(String[] args)
    {
        //process arguments
        processArgs(args);

        //start log
        Log log = new Log();

        Log.write("Starting new server on port " + port);
        Log.write("Using NDN namespace: " + namespace);

        Server server = new Server(port);

        //set up the servlets
        ServletContextHandler context = new ServletContextHandler(ServletContextHandler.SESSIONS | ServletContextHandler.SECURITY);
        context.setContextPath("/");
        server.setHandler(context);
        context.addServlet(new ServletHolder(new PDVServlet()), "/*");
        context.addServlet(new ServletHolder(new LoginServlet()), "/login/*");
        context.addServlet(new ServletHolder(new HomeServlet()), "/home/*");

        //configure servlets
        context.addServlet(new ServletHolder(new AppServlet()), "/home/configure/*");
        context.addServlet(new ServletHolder(new DataStreamServlet()), "/home/configure/app/*");
        context.addServlet(new ServletHolder(new ConfigureServlet()), "/home/configure/app/dataStream/*");
        
        //download servlets
        context.addServlet(new ServletHolder(new AppServlet()), "/home/download/*");
        context.addServlet(new ServletHolder(new DataStreamServlet()), "/home/download/app/*");
        context.addServlet(new ServletHolder(new DownloadServlet()), "/home/download/app/dataStream/*");

        context.addServlet(new ServletHolder(new UploadServlet()), "/home/upload/*");
        context.addServlet(new ServletHolder(new NDNTestServlet()), "/home/test/*");

        try
        {
            server.start();
            server.join();
        }
        catch(InterruptedException e)
        {
            return;
        }
        catch(Exception e)
        {
            return;
        }
    }

    //prints usage
    private static void usage()
    {
        System.out.println("Example usage:");
        System.out.println("java -jar WebClient.jar -port:8081 -namespace:/ucla.edu/webclient");
    }

    //processes arguments to the jar
    private static void processArgs(String[] args)
    {
        String portArg = "-port";
        String portArg2 = "-p";

        String namespaceArg = "-namespace";
        String namespaceArg2 = "-n";
        for(String s : args)
        {
            if(s.equalsIgnoreCase("help"))
            {
                usage();
                System.exit(0);
            }

            //make sure there are 2 components to the argument
            String[] arg = s.split(":");
            if(arg.length != 2)
            {
                usage();
                System.exit(1);
            }

            //if it's the port arg
            if(arg[0].equalsIgnoreCase(portArg) || arg[0].equalsIgnoreCase(portArg2))
                WebClientServer.port = (new Integer(arg[1])).intValue();

            //if it's the namespace arg
            if(arg[0].equalsIgnoreCase(namespaceArg) || arg[0].equalsIgnoreCase(namespaceArg2))
                WebClientServer.namespace = arg[1];
        }
    }
}
