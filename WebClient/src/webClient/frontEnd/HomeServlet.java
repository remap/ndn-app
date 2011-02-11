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

public class HomeServlet extends HttpServlet
{
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException
    {

        response.setContentType("text/html");
        response.setStatus(HttpServletResponse.SC_OK);

        if(isAuthenticatedUser(request))
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
        }
        else
        {
            //TODO redirect to login page to try again
        }
    }

    private boolean isAuthenticatedUser(HttpServletRequest request)
    {
        //TODO
        Map params = request.getParameterMap();

        for(Object k : params.keySet())
        {
            //response.getWriter().println("<h1>" + k.toString() + "</h1>");
            String[] s = (String[])params.get(k);
            //response.getWriter().println("<h1>" + s[0] + "</h1>");
            //response.getWriter().println();
        }

        return true;
    }
}
