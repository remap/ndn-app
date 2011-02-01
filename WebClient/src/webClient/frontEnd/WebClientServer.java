package webClient.frontEnd;

import org.eclipse.jetty.server.Server;
import org.eclipse.jetty.servlet.ServletContextHandler;
import org.eclipse.jetty.servlet.ServletHolder;
import org.eclipse.jetty.servlet.ServletContextHandler;

/**
 *
 * @author Alexander Bonomo
 */
public class WebClientServer
{
    public static void main(String[] args)
    {
        int port = (new Integer(args[0])).intValue();

        //TODO print this in the log
        System.out.println("Starting new server on port " + port);

        Server server = new Server(port);

        //TODO: figure out what these options mean / how they work
        ServletContextHandler context = new ServletContextHandler(ServletContextHandler.SESSIONS | ServletContextHandler.SECURITY);
        context.setContextPath("/");
        server.setHandler(context);
        context.addServlet(new ServletHolder(new LoginServlet()), "/*");
        context.addServlet(new ServletHolder(new HomeServlet()), "/home/*");
        context.addServlet(new ServletHolder(new ConfigureServlet()), "/configure/*");
        context.addServlet(new ServletHolder(new DownloadServlet()), "/download/*");
        context.addServlet(new ServletHolder(new UploadServlet()), "/upload/*");

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
}
