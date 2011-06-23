package webClient.frontEnd;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import webClient.lib.ConfigurationSettings;
import webClient.session.SessionManager;

/**
 * This page allows a user to modify the configuration settings for a datastream
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
        this.m_userHash = request.getParameter(VarNames.USER_HASH);
        String dsName = request.getParameter(VarNames.DATA_STREAM);
        SessionManager.getSession(m_userHash).setCurrentDataStream(dsName);
        
        response.setContentType("text/html");
        response.setStatus(HttpServletResponse.SC_OK);

        response.getWriter().println("<h1> Configure this data stream. </h1>");
 
        response.getWriter().println("Set Publisher: ");
        response.getWriter().println("<form method=\"post\" action=\"" + request.getRequestURL().toString() + "/confirm_config\" name=set_pub_form>");
        response.getWriter().println("<input type=\"text\" name=\"" + VarNames.PUBLISHER + "\">");
        response.getWriter().println("<input type=\"hidden\" name=\"" + VarNames.USER_HASH + "\" value=\"" + this.m_userHash + "\">");
        response.getWriter().println("<input type=\"submit\" name=\"" + VarNames.SUBMIT + "\" value=\"set\"> <br> <br>");

        response.getWriter().println("Add Receiver: ");
        response.getWriter().println("<input type=\"text\" name=\"" + VarNames.RECEIVER + "\">");
        response.getWriter().println("<input type=\"hidden\" name=\"" + VarNames.USER_HASH + "\" value=\"" + this.m_userHash + "\">");
        response.getWriter().println("<input type=\"submit\" name=\"" + VarNames.SUBMIT + "\" value=\"add\">");

    }

}
