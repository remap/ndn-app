package webClient.ndn.test;

import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.ccnx.ccn.config.ConfigurationException;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;

/**
 *
 * @author Alexander Bonomo
 */

public class NDNTestServlet extends HttpServlet
{
    NDNTest _test;

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException
    {
        _test = new NDNTest("/ucla.edu/host/borges.metwi/status/html");
        _test.start();
        /*try
        {
            _test.listen();
        }
        catch (ConfigurationException ex)
        {
            response.getWriter().println(ex.getMessage() + "<br />");
            Logger.getLogger(NDNTestServlet.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println(ex.getMessage());
        }
        catch (MalformedContentNameStringException ex)
        {
            response.getWriter().println(ex.getMessage() + "<br />");
            Logger.getLogger(NDNTestServlet.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println(ex.getMessage());
        }*/

        response.setContentType("text/html");
        response.setStatus(HttpServletResponse.SC_OK);

        while(!_test.isContentReady())
        {
            try {
                (Thread.currentThread()).sleep(500);
            } catch (InterruptedException ex) {
                Logger.getLogger(NDNTestServlet.class.getName()).log(Level.SEVERE, null, ex);
            }
        }

        if(_test.getContent() != null)
            response.getWriter().println(_test.getContent());
        else
            response.getWriter().println("<h1> No Content</h1>");
    }
}
