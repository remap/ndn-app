package webClient.frontEnd;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import webClient.session.*;
import webClient.backEnd.PDCDataStreams;

/**
 *
 * @author Alexander Bonomo
 */
public class AddDSServlet extends HttpServlet
{
    private String m_userHash;

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException
    {
        response.setContentType("text/html");
        response.setStatus(HttpServletResponse.SC_OK);

        this.m_userHash = request.getParameter(VarNames.USER_HASH);
        String dsName = request.getParameter(VarNames.DATA_STREAM);

        PDCDataStreams pdcds = new PDCDataStreams();

        if(pdcds.addDataStream(m_userHash, dsName))
        {
            response.getWriter().println("<h1> Successfully added data stream : " + dsName + "</h1>");
        }
        else
        {
            response.getWriter().println("<h1> Could not add data stream. </h1>");
        }

    }
}
