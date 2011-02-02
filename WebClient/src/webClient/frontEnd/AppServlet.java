package webClient.frontEnd;

/**
 *
 * @author Alexander Bonomo
 */

import java.io.IOException;
import java.util.Collection;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import pdc.DataStream;
import webClient.backEnd.PDCDataStreams;

public class AppServlet extends HttpServlet
{
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException
    {
        response.setContentType("text/html");
        response.setStatus(HttpServletResponse.SC_OK);

        response.getWriter().println("<h1> Here are the data streams for this app. </h1>");
    
        printDataStreams(request, response);
    }

    private void printDataStreams(HttpServletRequest request, HttpServletResponse response)
    {
        //TODO actually get app name
        String appName = "app";

        Collection<DataStream> dataStreams = PDCDataStreams.getDataStreams(appName);

        for(DataStream ds : dataStreams)
        {
            //TODO print link for each data stream
        }
    }
}
