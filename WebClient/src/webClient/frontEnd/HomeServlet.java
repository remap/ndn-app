package webClient.frontEnd;

import edu.ucla.cens.pdc.libpdc.exceptions.PDCEncryptionException;
import java.io.IOException;
import java.security.NoSuchAlgorithmException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import webClient.backEnd.PDCLogin;
import webClient.exceptions.NoPDVResponseException;
import webClient.lib.Algorithms;
import webClient.lib.Security;
import webClient.log.Log;
import webClient.session.SessionManager;

/**
 * This class displays the home page to the user.  This is the main page where
 * the user can select what to do.
 * @author Alexander Bonomo
 */
@SuppressWarnings("serial")
public class HomeServlet extends HttpServlet {
	private String _userHash = null;

	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException
	{
		PDCLogin pdcLogin;
		try {
			String pdv_uri = request.getParameter(VarNames.PDV_URI);
			String pdv_key = request.getParameter(VarNames.PDV_PUBKEY);
			String username = request.getParameter("login");
			String password = request.getParameter("password");
			pdcLogin = new PDCLogin(WebClientServer.getNDNNamespace() + "/login",
					pdv_uri, pdv_key, username, password);
		}
		catch (NoPDVResponseException ex) {
			Logger.getLogger(HomeServlet.class.getName()).log(Level.SEVERE, null, ex);
			return;
		}
		catch (MalformedContentNameStringException e) {
			response.setContentType("text/html");
			response.setStatus(HttpServletResponse.SC_INTERNAL_SERVER_ERROR);
			response.getWriter().println(e.getMessage());
			return;
		}

		response.setContentType("text/html");
		response.setStatus(HttpServletResponse.SC_OK);
		response.getWriter().println("<h1>Home Page.</h1>");
		try {
			if (isAuthenticatedUser(request, pdcLogin)) {
				//get the user hash and pass it to the next page
				String userHashVar = "?" + VarNames.USER_HASH + "=" + this._userHash;
				//configure link
				response.getWriter().println("<a href=\"" + request.getRequestURL().
						toString() + PageDirectory.CONFIGURE + userHashVar
						+ "\"> Configure </a>");
				response.getWriter().println("<br />");
				//download link
				response.getWriter().println("<a href=\"" + PageDirectory.DOWNLOAD
						+ userHashVar + "\"> Download </a>");
				response.getWriter().println("<br />");
				//upload link
				response.getWriter().println("<a href=\"" + PageDirectory.UPLOAD
						+ userHashVar + "\"> Upload </a>");
				response.getWriter().println("<br />");
				//test link
				response.getWriter().println("<a href=\"" + "test/"
						+ "\"> Test </a> <br />");
			} else {
				//redirect to login page to try again
				String loginURL = request.getRequestURL().substring(0, request.
						getRequestURL().length() - PageDirectory.HOME.length())
						+ PageDirectory.LOGIN;
				response.getWriter().println("<meta http-equiv=\"REFRESH\" content=\"0;url="
						+ loginURL + "\">");
			}
		}
		catch (PDCEncryptionException ex) {
			Logger.getLogger(HomeServlet.class.getName()).log(Level.SEVERE, null, ex);
			response.getWriter().println("Encryption Error: Try again.");
			//redirect to login page to try again
			String loginURL = request.getRequestURL().substring(0, request.
					getRequestURL().length() - PageDirectory.HOME.length())
					+ PageDirectory.LOGIN;
			response.getWriter().println("<meta http-equiv=\"REFRESH\" content=\"0;url="
					+ loginURL + "\">");
		}
	}

	/**
	 * Checks to see if the username and password are valid
	 * @param request
	 * @param pdcLogin
	 * @return
	 */
	private boolean isAuthenticatedUser(HttpServletRequest request,
			PDCLogin pdcLogin)
			throws PDCEncryptionException
	{
		String pdv_uri = request.getParameter(VarNames.PDV_URI);
		String username = request.getParameter("login");
		String password = request.getParameter("password");

		boolean isAuth = pdcLogin.isUserAuthenticated(pdv_uri, username, password);
		this._userHash = pdcLogin.getUserHash();
		/*try {
		SessionManager.registerSession(this._userHash, Security.generateSymmKey("DES"));
		SessionManager.getSession(this._userHash).setPDV_URI(pdv_uri);
		} catch (NoSuchAlgorithmException ex) {
		Logger.getLogger(HomeServlet.class.getName()).log(Level.SEVERE, null, ex);
		return false;
		}*/
		return isAuth;
	}
}
