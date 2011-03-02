package webClient.frontEnd;

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

/**
 * This page displays the data streams for a particular app.
 * 
 * @author Alexander Bonomo
 */
public class DataStreamServlet extends HttpServlet
{
    private String m_userHash;
    private String m_hashParam; //the parameter passed to the next page
    
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException
    {
        response.setContentType("text/html");
        response.setStatus(HttpServletResponse.SC_OK);

        response.getWriter().println("<h1> Here are the data streams for this app. </h1>");

        this.m_userHash = request.getParameter(VarNames.USER_HASH);
        this.m_hashParam = "?" + VarNames.USER_HASH + "=" + this.m_userHash;

        printDataStreams(request, response);
    }

    /**
     * Prints the data streams for this app
     * @param request
     * @param response
     */
    private void printDataStreams(HttpServletRequest request, HttpServletResponse response)
    {
        //TODO actually get app name
        String appName = "app";

        PDCDataStreams streamGetter = new PDCDataStreams();
        Collection<DataStream> dataStreams;
        try
        {
            dataStreams = streamGetter.getDataStreams(this.m_userHash, appName);
        } 

        catch (IOException ex)
        {
            Logger.getLogger(DataStreamServlet.class.getName()).log(Level.SEVERE, null, ex);
            return;
        }        catch (MalformedContentNameStringException ex)
        {
            Logger.getLogger(DataStreamServlet.class.getName()).log(Level.SEVERE, null, ex);
            return;
        }

        for(DataStream ds : dataStreams)
        {
            //TODO print link for each data stream
        }
    }
}
