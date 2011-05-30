/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package spawning.client;

import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;

/**
 *
 * @author Derek Kulinski
 */
public final class TransducerClassLoader extends URLClassLoader {
	public TransducerClassLoader(String path)
			throws MalformedURLException
	{
		super(new URL[]{new URL("jar:file://" + path + "!/")});
	}

	public Class<? extends iTransducer> load(String name)
			throws ClassNotFoundException
	{
		Object cls = loadClass("spawning.client." + name);

		return (Class<? extends iTransducer>) cls;
	}
}
