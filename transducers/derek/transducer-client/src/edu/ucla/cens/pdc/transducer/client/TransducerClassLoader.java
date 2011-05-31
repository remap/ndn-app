/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.transducer.client;

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
//		super(new URL[]{new URL("file:///home/takeda/Documents/cens/ndn-app/transducers/derek/transducer-client/examples/")});
	}

	@SuppressWarnings("unchecked")
	public Class<? extends iTransducerClient> load(String name)
			throws ClassNotFoundException
	{
		Object cls = loadClass("edu.ucla.cens.pdc.transducer.client." + name);

		return (Class<? extends iTransducerClient>) cls;
	}
}
