package webClient.frontEnd;

import edu.ucla.cens.pdc.libpdc.stream.DataStream;
import java.io.IOException;
import java.util.Collection;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import webClient.backEnd.PDCDataStreams;
import webClient.session.SessionManager;

/**
 * This page displays the data streams for a particular app.
 * 
 * @author Alexander Bonomo
 */
@SuppressWarnings("serial")
public class DataStreamServlet extends HttpServlet
{
    private String m_userHash;
    
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException
    {
        response.setContentType("text/html");
        response.setStatus(HttpServletResponse.SC_OK);

        response.getWriter().println("<h1> Here are the data streams for this app. </h1>");

        this.m_userHash = request.getParameter(VarNames.USER_HASH);

        printAddRemoveStreams(request, response);
        printDataStreams(request, response);
    }

    /**
     * Prints the data streams for this app
     * @param request
     * @param response
     */
    private void printDataStreams(HttpServletRequest request, HttpServletResponse response)
    {
        String appID = request.getParameter(VarNames.APPLICATION);
        SessionManager.getSession(this.m_userHash).setCurrentApp(appID);

        //get the data streams
        PDCDataStreams streamGetter = new PDCDataStreams();
        Collection<String> dataStreams;
        try
        {
            dataStreams = streamGetter.getDataStreams(this.m_userHash, appID);
        } 

        catch (IOException ex)
        {
            Logger.getLogger(DataStreamServlet.class.getName()).log(Level.SEVERE, null, ex);
            return;
        }
        catch (MalformedContentNameStringException ex)
        {
            Logger.getLogger(DataStreamServlet.class.getName()).log(Level.SEVERE, null, ex);
            return;
        }

        try
        {
            response.getWriter().println("<h2> Streams: </h2>");
            //print a link for each stream
            for(String ds : dataStreams)
            {
                response.getWriter().println("<a href=\"" + request.getRequestURL().toString()
                    + "/dataStream?" + VarNames.USER_HASH + "=" + this.m_userHash + "&"
                    + VarNames.DATA_STREAM + "=" + ds + "\"> " + ds + "</a> <br />");
            }
        }
        catch (IOException ex)
        {
            Logger.getLogger(AppServlet.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    private void printAddRemoveStreams(HttpServletRequest request, HttpServletResponse response)
    {
        try
        {
            //print add stream
            response.getWriter().println("Add Stream: " + "<form method=\"post\" action=\"" + request.getRequestURL().toString() + "/add" + "\" name=pdvform>");
            response.getWriter().println("<input type=\"text\" name=\"" + VarNames.DATA_STREAM + "\">");
            response.getWriter().println("<input type=\"submit\" value=\"Add\">");
            response.getWriter().println("<input type=\"hidden\" name=\"" + VarNames.USER_HASH
                    + "\" value=\"" + this.m_userHash + "\" <br />");

            response.getWriter().print("<br /> To remove a stream click "
                    + "<a href=\"" + request.getRequestURL().toString() + "/remove?"
                    + VarNames.USER_HASH + "=" + this.m_userHash + "\">here. </a> <br /> <br />");
        }
        catch (IOException ex)
        {
            Logger.getLogger(DataStreamServlet.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
