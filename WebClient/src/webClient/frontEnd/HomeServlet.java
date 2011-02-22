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
    private String _userHash = null;
    
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
            //get the user hash and pass it to the next page
            String userHashVar = "?" + VarNames.USER_HASH + "=" + this._userHash;

            //configure link
            response.getWriter().println("<a href=\"" + request.getRequestURL().toString()
                    + PageDirectory.CONFIGURE + userHashVar + "\"> Configure </a>");
            response.getWriter().println("<br />");

            //download link
            response.getWriter().println("<a href=\"" + PageDirectory.DOWNLOAD +
                    userHashVar + "\"> Download </a>");
            response.getWriter().println("<br />");

            //upload link
            response.getWriter().println("<a href=\"" + PageDirectory.UPLOAD +
                    userHashVar + "\"> Upload </a>");
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
            _userHash = md5Hash(pdv_uri, username, password);
            SessionManager.registerSession(_userHash);
            SessionManager.getSession(_userHash).setPdv_uri(pdv_uri);
        }

        return isAuthenticatedUser;
    }

    private String md5Hash(String pdv_uri, String username, String password)
    {
        return pdv_uri + username + password;
    }
}
