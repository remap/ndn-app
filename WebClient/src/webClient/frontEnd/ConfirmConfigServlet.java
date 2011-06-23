package webClient.frontEnd;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import webClient.backEnd.PDCDataStreams;

/**
 *
 * @author Alexander Bonomo
 */
public class ConfirmConfigServlet extends HttpServlet
{
    String m_userHash;

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException
    {
        this.m_userHash = request.getParameter(VarNames.USER_HASH);

        PDCDataStreams pdcds = new PDCDataStreams();

        response.setContentType("text/html");
        response.setStatus(HttpServletResponse.SC_OK);

        //check to see if we set publisher
        if(request.getParameter(VarNames.SUBMIT).equals("set"))
        {
            String publisherURI = request.getParameter(VarNames.PUBLISHER);
            if(pdcds.setPublisher(m_userHash, publisherURI))
                response.getWriter().println("<h1> Successfully set publisher: " + publisherURI + "</h1>");
            else
                response.getWriter().println("<h1> Could not set publisher. </h1>");
        }

        //check to se if we add receiver
        if(request.getParameter(VarNames.SUBMIT).equals("add"))
        {
            String receiverURI = request.getParameter(VarNames.RECEIVER);
            if(pdcds.addReceiver(m_userHash, receiverURI))
                response.getWriter().println("<h1> Successfully added receiver: " + receiverURI + "</h1>");
            else
                response.getWriter().println("<h1> Could not add receiver. </h1>");
        }
        
    }
}
