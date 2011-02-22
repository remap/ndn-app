package webClient.frontEnd;

/**
 *
 * @author Alexander Bonomo
 */

import java.io.IOException;
import java.util.Collection;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import pdc.DataStream;
import webClient.backEnd.PDCDataStreams;

public class AppServlet extends HttpServlet
{
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException
    {
        response.setContentType("text/html");
        response.setStatus(HttpServletResponse.SC_OK);

        response.getWriter().println("<h1> Here are the data streams for this app. </h1>");
    
        printDataStreams(request, response);
    }

    private void printDataStreams(HttpServletRequest request, HttpServletResponse response)
    {
        //TODO actually get app name
        String appName = "app";

        PDCDataStreams streamGetter = new PDCDataStreams();
        Collection<DataStream> dataStreams;
        try
        {
            dataStreams = streamGetter.getDataStreams(appName, appName);
        } 
        catch (IOException ex)
        {
            Logger.getLogger(AppServlet.class.getName()).log(Level.SEVERE, null, ex);
            return;
        } 
        catch (MalformedContentNameStringException ex)
        {
            Logger.getLogger(AppServlet.class.getName()).log(Level.SEVERE, null, ex);
            return;
        }

        for(DataStream ds : dataStreams)
        {
            //TODO print link for each data stream
        }
    }
}
