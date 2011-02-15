package webClient.frontEnd;

import org.eclipse.jetty.server.Server;
import org.eclipse.jetty.servlet.ServletContextHandler;
import org.eclipse.jetty.servlet.ServletHolder;
import org.eclipse.jetty.servlet.ServletContextHandler;
import webClient.ndn.test.NDNTestServlet;

/**
 *
 * @author Alexander Bonomo
 */
public class WebClientServer
{
    public static final long DEFAULT_TIMEOUT = 10000;

    private static int port         = 8081;
    private static String namespace = "/ucla.edu/webclient";

    public static String getNDNNamespace()
    {
        return namespace;
    }
    
    public static void main(String[] args)
    {
        processArgs(args);

        //TODO print this in the log
        System.out.println("Starting new server on port " + port);
        System.out.println("Using NDN namespace: " + namespace);

        Server server = new Server(port);

        //TODO: figure out what these options mean / how they work
        ServletContextHandler context = new ServletContextHandler(ServletContextHandler.SESSIONS | ServletContextHandler.SECURITY);
        context.setContextPath("/");
        server.setHandler(context);
        context.addServlet(new ServletHolder(new PDVServlet()), "/*");
        context.addServlet(new ServletHolder(new LoginServlet()), "/login/*");
        context.addServlet(new ServletHolder(new HomeServlet()), "/home/*");
        context.addServlet(new ServletHolder(new ConfigureServlet()), "/home/configure/*");
        context.addServlet(new ServletHolder(new AppServlet()), "/home/configure/app/*");
        context.addServlet(new ServletHolder(new DataStreamServlet()), "/home/configure/app/dataStream/*");
        context.addServlet(new ServletHolder(new DownloadServlet()), "/home/download/*");
        context.addServlet(new ServletHolder(new AppServlet()), "/home/download/app/*");
        context.addServlet(new ServletHolder(new DataStreamServlet()), "/home/download/app/dataStream/*");
        context.addServlet(new ServletHolder(new UploadServlet()), "/home/upload/*");
        context.addServlet(new ServletHolder(new NDNTestServlet()), "/home/test/*");

        try
        {
            server.start();
            server.join();
        }
        catch(InterruptedException e)
        {
            //TODO
        }
        catch(Exception e)
        {
            //TODO
        }
    }

    private static void usage()
    {
        System.out.println("Example usage:");
        System.out.println("java -jar WebClient.jar -port:8081 -namespace:/ucla.edu/webclient");
    }

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
