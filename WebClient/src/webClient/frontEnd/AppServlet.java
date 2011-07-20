package webClient.frontEnd;

import edu.ucla.cens.pdc.libpdc.exceptions.PDCEncryptionException;
import java.io.IOException;
import java.util.Collection;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import webClient.backEnd.PDCApps;
import webClient.exceptions.NoSuchUserHashException;

/**
 * This class prints the apps available this user on this PDV instance
 * 
 * @author Alexander Bonomo
 */
public class AppServlet extends HttpServlet {
	private String _userHash = null;

	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
					throws ServletException, IOException
	{
		response.setContentType("text/html");
		response.setStatus(HttpServletResponse.SC_OK);

		this._userHash = request.getParameter(VarNames.USER_HASH);
		if (this._userHash == null)
			response.getWriter().println("<h1> user hash not transferred. </h1>");

		response.getWriter().println("<h1> Your Apps. </h1>");

                printAddRemoveApps(request, response);
		printApps(request, response);
	}

	/**
	 * Prints the apps
	 *
	 * @param response
	 */
	private void printApps(HttpServletRequest request,
					HttpServletResponse response)
	{
		Collection<String> apps;
		try
                {
			//get the list of apps
			PDCApps appGetter = new PDCApps();
			apps = appGetter.getUserApps(this._userHash);
		}
		catch (NoSuchUserHashException ex) {
			Logger.getLogger(AppServlet.class.getName()).log(Level.SEVERE, null, ex);
			return;
		}
		catch (PDCEncryptionException ex) {
			Logger.getLogger(AppServlet.class.getName()).log(Level.SEVERE, null, ex);
			return;
		}
		catch (IOException ex) {
			Logger.getLogger(AppServlet.class.getName()).log(Level.SEVERE, null, ex);
			return;
		}

		//print a link for each app
		for (String a : apps)
			try {
				response.getWriter().println("<a href=\"" + request.getRequestURL().
								toString()
								+ "app?" + VarNames.USER_HASH + "=" + this._userHash + "&"
								+ VarNames.APPLICATION + "=" + a + "\"> " + a + "</a> <br />");
			}
			catch (IOException ex) {
				Logger.getLogger(AppServlet.class.getName()).log(Level.SEVERE, null, ex);
			}
	}

        private void printAddRemoveApps(HttpServletRequest request, HttpServletResponse response)
    {
        try
        {
            //print add stream
            response.getWriter().println("Add App: " + "<form method=\"post\" action=\"" + request.getRequestURL().toString() + "add" + "\" name=pdvform>");
            response.getWriter().println("<input type=\"text\" name=\"" + VarNames.APPLICATION + "\">");
            response.getWriter().println("<input type=\"submit\" value=\"Add\">");
            response.getWriter().println("<input type=\"hidden\" name=\"" + VarNames.USER_HASH
                    + "\" value=\"" + this._userHash + "\" <br />");

            response.getWriter().print("<br /> To remove an App click "
                    + "<a href=\"" + request.getRequestURL().toString() + "/remove?"
                    + VarNames.USER_HASH + "=" + this._userHash + "\">here. </a> <br /> <br />");
        }
        catch (IOException ex)
        {
            Logger.getLogger(DataStreamServlet.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
