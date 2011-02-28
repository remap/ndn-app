package webClient.frontEnd;

import java.io.IOException;
import java.util.Map;
import java.util.Set;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author Alexander Bonomo
 */

public class ConfigureServlet extends HttpServlet
{
    String m_userHash;

     @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException
    {
        response.setContentType("text/html");
        response.setStatus(HttpServletResponse.SC_OK);

        response.getWriter().println("<h1> Configure your settings. </h1>");

        this.m_userHash = request.getParameter(VarNames.USER_HASH);
    }
}
