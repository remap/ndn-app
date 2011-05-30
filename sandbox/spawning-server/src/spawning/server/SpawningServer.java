/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package spawning.server;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

/**
 *
 * @author takeda
 */
public class SpawningServer {
	/**
	 * @param args the command line arguments
	 */
	@SuppressWarnings("NestedAssignment")
	public static void main(String[] args)
			throws IOException
	{
		final ProcessBuilder builder = new ProcessBuilder("java", "-jar",
				"dist/spawning-client.jar", "example/Transducer.jar",
				"TransducerExample");

		builder.directory(new File(
				"/home/takeda/Documents/cens/ndn-app/sandbox/spawning-client"));
		final Process process = builder.start();

		process.getOutputStream().write("hello\n".getBytes());
		process.getOutputStream().flush();

		final InputStream is = process.getInputStream();
		final InputStreamReader isr = new InputStreamReader(is);
		final BufferedReader br = new BufferedReader(isr);

		String line;
		while ((line = br.readLine()) != null) {
			System.out.println(line);
		}
		System.out.println("Terminated with: " + process.exitValue());
	}
}