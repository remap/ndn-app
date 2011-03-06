package webClient.frontEnd;

import edu.ucla.cens.pdc.libpdc.iApplication;
import java.io.IOException;
import java.util.Collection;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import webClient.backEnd.PDCApps;
import webClient.ndn.test.PDCAppsTest;

/**
 * This class prints the apps available this user on this PDV instance
 * 
 * @author Alexander Bonomo
 */

public class AppServlet extends HttpServlet
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

        printApps(request, response);
    }

     /**
      * Prints the apps
      * 
      * @param response
      */
     private void printApps(HttpServletRequest request, HttpServletResponse response)
     {
        Collection<String> apps;
        //apps = PDCAppsTest.listApps();
        try
        {
            PDCApps appGetter = new PDCApps();
            apps = appGetter.getUserApps(this._userHash);
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

        for(String a : apps)
        {
            try
            {
                response.getWriter().println("<a href=\"" + request.getRequestURL().toString()
                        + "/app?" + VarNames.APPLICATION + "=" + a + "\"> " + a + "</a> <br />");
            }
            catch (IOException ex)
            {
                Logger.getLogger(AppServlet.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
     }
}
