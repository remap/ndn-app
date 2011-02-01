package webClient.frontEnd;

/**
 *
 * @author Alexander Bonomo
 */

import java.io.IOException;import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class LoginServlet extends HttpServlet
{
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException
    {
        response.setContentType("text/html");
        response.setStatus(HttpServletResponse.SC_OK);

        String loginHtml = "<font face=\"verdana,arial\" size=-1>\n"
            + "<center><table cellpadding=2 cellspacing=0 border=0>\n"
            + "<tr><td bgcolor=\"blue\"><table cellpadding=0 cellspacing=0 border=0 width=100%><tr><td bgcolor=\"blue\" align=center style=\"padding:2;padding-bottom:4\"><b><font size=-1 color=\"white\" face=\"verdana,arial\"><b>Enter your login and password</b></font></th></tr>\n"
            + "<tr><td bgcolor=\"white\" style=\"padding:5\"><br>\n"
            + "<form method=\"post\" action=\"" + PageDirectory.HOME + "\" name=pform>\n"
            + "<input type=\"hidden\" name=\"action\" value=\"login\">\n"
            + "<input type=\"hidden\" name=\"hide\" value=\"\">\n"
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
