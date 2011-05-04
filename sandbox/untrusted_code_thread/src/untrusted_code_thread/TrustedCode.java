/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package untrusted_code_thread;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Derek Kulinski
 */
public class TrustedCode {
	final static Logger l = Logger.getLogger(TrustedCode.class.getName());

	public void doUnprivilegedStuff()
	{
		System.out.println("Hello from the privileged code");
	}

	public void doPrivilegedStuff()
	{
		final File test_file = new File("test-privileged.txt");
		PrintWriter pw;

		test_file.delete();
		try {
			pw = new PrintWriter(test_file);
			pw.println("Hello world!");
			pw.close();
		}
		catch (FileNotFoundException ex) {
			l.log(Level.SEVERE, "Unable to write to the file", ex);
		}		
	}
	
	
}
