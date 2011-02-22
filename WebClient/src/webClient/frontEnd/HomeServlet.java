package webClient.frontEnd;

/**
 *
 * @author Alexander Bonomo
 */

import java.io.IOException;import java.util.Map;
import java.util.Set;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import webClient.backEnd.PDCLogin;
import webClient.session.SessionManager;

public class HomeServlet extends HttpServlet
{
    private String userHash = "";
    
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException
    {
        PDCLogin pdcLogin;
        try
        {
            pdcLogin = new PDCLogin(WebClientServer.getNDNNamespace() + "/login");
        }
        catch(MalformedContentNameStringException e)
        {
            response.setContentType("text/html");
            response.setStatus(HttpServletResponse.SC_INTERNAL_SERVER_ERROR);
            response.getWriter().println(e.getMessage());
            return;
        }

        response.setContentType("text/html");
        response.setStatus(HttpServletResponse.SC_OK);

        if(isAuthenticatedUser(request, pdcLogin))
        {
            //configure link
            response.getWriter().println("<a href=\"" + request.getRequestURL().toString()
                    + PageDirectory.CONFIGURE + "\"> Configure </a>");
            response.getWriter().println("<br />");

            //download link
            response.getWriter().println("<a href=\"" + PageDirectory.DOWNLOAD +
                    "\"> Download </a>");
            response.getWriter().println("<br />");

            //upload link
            response.getWriter().println("<a href=\"" + PageDirectory.UPLOAD +
                    "\"> Upload </a>");
            response.getWriter().println("<br />");

            //test link
            response.getWriter().println("<a href=\"" + "test/" + "\"> Test </a> <br />");

            //TODO pass userHash to next page
        }
        else
        {
            //TODO redirect to login page to try again
        }
    }

    private boolean isAuthenticatedUser(HttpServletRequest request, PDCLogin pdcLogin)
    {
        String pdv_uri = request.getParameter("pdvuri");
        String username = request.getParameter("login");
        String password = request.getParameter("password");

        boolean isAuthenticatedUser = pdcLogin.isUserAuthenticated(pdv_uri, username, password);

        //if the user is authenticated, register a new session 
        if(isAuthenticatedUser)
        {
            userHash = md5Hash(pdv_uri, username, password);
            SessionManager.registerSession(userHash);
            SessionManager.getSession(userHash).setPdv_uri(pdv_uri);
        }

        return isAuthenticatedUser;
    }

    private String md5Hash(String pdv_uri, String username, String password)
    {
        return pdv_uri + username + password;
    }
}
