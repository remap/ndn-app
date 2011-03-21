/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ccnxsigning;

import java.io.IOException;
import java.security.InvalidKeyException;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.ccnx.ccn.config.ConfigurationException;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;

/**
 *
 * @author Derek Kulinski
 */
public class Main {
	/**
	 * @param args the command line arguments
	 */
	public static void main(String[] args)
					throws ConfigurationException, InvalidKeyException
	{
		try {
			Signing app = new Signing("ccnx:/signing");
			app.setupKeys();
			app.startListening();
		}
		catch (IOException ex) {
			Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
		}
		catch (MalformedContentNameStringException ex) {
			Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
		}
	}
}
