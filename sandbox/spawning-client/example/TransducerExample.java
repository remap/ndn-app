/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package spawning.client;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Derek Kulinski
 */
public class TransducerExample implements iTransducer {
	@Override
	@SuppressWarnings("NestedAssignment")
	public void processData()
	{
		try {
			final InputStream is = System.in;
			final InputStreamReader isr = new InputStreamReader(is);
			final BufferedReader br = new BufferedReader(isr);

			String line;
			while ((line = br.readLine()) != null) {
				System.out.println("You said: >" + line + "<");
			}
		}
		catch (IOException ex) {
			Logger.getLogger(TransducerExample.class.getName()).
					log(Level.SEVERE, null, ex);
		}
	}
}
