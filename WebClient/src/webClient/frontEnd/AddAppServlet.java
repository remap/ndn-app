package webClient.frontEnd;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import webClient.backEnd.PDCApps;

/**
 *
 * @author ALexander Bonomo
 */
public class AddAppServlet extends HttpServlet
{
    private String m_userHash;

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException
    {
        response.setContentType("text/html");
        response.setStatus(HttpServletResponse.SC_OK);

        this.m_userHash = request.getParameter(VarNames.USER_HASH);
        String app = request.getParameter(VarNames.APPLICATION);

        PDCApps pdca = new PDCApps();

        if(pdca.addApp(m_userHash, app))
            response.getWriter().println("<h1> Successfully added app: " + app + "</h1>");
        else
            response.getWriter().println("<h1> Could not add app. </h1>");
    }
}
