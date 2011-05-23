package webClient.frontEnd;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * This class displays the login page to the user then passes the login credentials
 * to the homepage.
 * 
 * @author Alexander Bonomo
 */
@SuppressWarnings("serial")
public class LoginServlet extends HttpServlet {
	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException
	{
		String pdv_uri = request.getParameter(VarNames.PDV_URI);
		String pdv_key = request.getParameter(VarNames.PDV_PUBKEY);

		response.setContentType("text/html");
		response.setStatus(HttpServletResponse.SC_OK);

		//index of where to end the substring of the current URL
		int endIndex = request.getRequestURL().toString().length()
				- PageDirectory.LOGIN.length();

		String loginHtml = "<font face=\"verdana,arial\" size=-1>\n"
				+ "<center><table cellpadding=2 cellspacing=0 border=0>\n"
				+ "<tr><td bgcolor=\"blue\"><table cellpadding=0 cellspacing=0 border=0 width=100%><tr><td bgcolor=\"blue\" align=center style=\"padding:2;padding-bottom:4\"><b><font size=-1 color=\"white\" face=\"verdana,arial\"><b>Enter your login and password</b></font></th></tr>\n"
				+ "<tr><td bgcolor=\"white\" style=\"padding:5\"><br>\n"
				+ "<form method=\"post\" action=\"" + request.getRequestURL().substring(
				0, endIndex) + PageDirectory.HOME + "\" name=pform>\n"
				+ "<input type=\"hidden\" name=\"action\" value=\"login\">\n"
				+ "<input type=\"hidden\" name=\"hide\" value=\"\">\n"
				+ "<input type=\"hidden\" name=\"" + VarNames.PDV_URI + "\" value=\""
				+ pdv_uri + "\">\n"
				+ "<input type=\"hidden\" name=\"" + VarNames.PDV_PUBKEY + "\" value=\""
				+ pdv_key + "\">\n"
				+ "<center><table>\n"
				+ "<tr><td><font face=\"verdana,arial\" size=-1>Login:</td><td><input type=\"text\" name=\"login\"></td></tr>\n"
				+ "<tr><td><font face=\"verdana,arial\" size=-1>Password:</td><td><input type=\"password\" name=\"password\"></td></tr>\n"
				+ "<tr><td><font face=\"verdana,arial\" size=-1>&nbsp;</td><td><font face=\"verdana,arial\" size=-1><input type=\"submit\" value=\"Enter\"></td></tr>\n"
				+ "<tr><td colspan=2><font face=\"verdana,arial\" size=-1>&nbsp;</td></tr>\n"
				//+ "<tr><td colspan=2><font face=\"verdana,arial\" size=-1>Lost your username or password? Find it <a href="http://www.authpro.com/auth/deluxe/?action=lost">here</a>!</td></tr>\n"
				//+ "<tr><td colspan=2><font face=\"verdana,arial\" size=-1>Not member yet? Click <a href="http://www.authpro.com/auth/deluxe/?action=reg">here</a> to register.</td></tr>\n"
				+ "</table></center>\n"
				+ "</form>\n"
				+ "</td></tr></table></td></tr></table>\n";

		response.getWriter().println(loginHtml);
	}
}
