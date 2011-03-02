package webClient.frontEnd;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * This class allows a user to enter the URI of a PDV instance to connect to
 * @author Alexander Bonomo
 */
public class PDVServlet extends HttpServlet
{
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException
    {
        response.setContentType("text/html");
        response.setStatus(HttpServletResponse.SC_OK);

        response.getWriter().println("<h1>Enter URI of desired PDV instance:</h1> <br>");
        response.getWriter().println("<form method=\"post\" action=\"" + request.getRequestURL().toString() + PageDirectory.LOGIN + "\" name=pdvform>");
        response.getWriter().println("<input type=\"text\" name=\"pdvuri\"> <br>");
        response.getWriter().println("<input type=\"submit\" value=\"Enter\">");
    }
}
