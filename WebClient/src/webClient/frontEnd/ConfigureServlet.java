package webClient.frontEnd;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import webClient.backEnd.PDCConfig.ConfigSettings;

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
        
        response.setContentType("text/html");
        response.setStatus(HttpServletResponse.SC_OK);

        response.getWriter().println("<h1> Configure your settings. </h1>");

        ConfigSettings currentSettings = getCurrentSettings();

    }

    private ConfigSettings getCurrentSettings()
    {
        return null;
    }
    
    private void displayCurrentSettings(ConfigSettings settings)
    {
        //TODO
    }
}
