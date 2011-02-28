package webClient.frontEnd;

/**
 *
 * @author Alexander Bonomo
 */

import java.io.IOException;
import java.util.Collection;
import java.util.Map;
import java.util.Set;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import webClient.backEnd.PDCApps;
import pdc.Application;

public class DownloadServlet extends HttpServlet
{
    private String _userHash = null;

     @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException
    {
        response.setContentType("text/html");
        response.setStatus(HttpServletResponse.SC_OK);

        this._userHash = request.getParameter(VarNames.USER_HASH);
        if(this._userHash == null)
            response.getWriter().println("<h1> user hash not transferred. </h1>");

        response.getWriter().println("<h1> View and download your data. </h1>");

        printApps(response);
    }

     private void printApps(HttpServletResponse response)
     {
         //TODO actually get username
        Collection<Application> apps;
        try
        {
            PDCApps appGetter = new PDCApps();
            apps = appGetter.getUserApps(this._userHash);
        }
        catch (IOException ex)
        {
            Logger.getLogger(DownloadServlet.class.getName()).log(Level.SEVERE, null, ex);
            return;
        }
        catch (MalformedContentNameStringException ex)
        {
            Logger.getLogger(DownloadServlet.class.getName()).log(Level.SEVERE, null, ex);
            return;
        }

        for(Application a : apps)
        {
            //TODO print a hyperlink for the app on a new line
        }

        /*
         * Notes on design proceeding from here:
         * Have a links to a DataStreamServlet class with a hidden "download" option
         * and on the Configure page also have links to DataStreamServlet
         * with "configure" as the hidden option
         *
         * This begs the question should we do the same for this download page
         * and the configure page.
         *
         * Guess I need to figure out exactly what we should configure
         */
     }
}
