/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package untrusted_code_thread;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.Reader;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Derek Kulinski
 */
public class MyClassLoader extends ClassLoader {
	static final Logger l = Logger.getLogger(MyClassLoader.class.getName());

	public MyClassLoader()
	{
		super(MyClassLoader.class.getClassLoader());
	}

	@Override
	public Class<?> loadClass(String name)
			throws ClassNotFoundException
	{
		System.out.println("loading class " + name);
//		l.log(Level.INFO, "Loading class {0}", name);
		return findClass(name);
	}

	@Override
	protected Class<?> findClass(String name)
			throws ClassNotFoundException
	{
		byte[] b;
		System.out.println("Searching for " + name);

		try {
			return findSystemClass(name);
		}
		catch (Exception ex) {
			System.out.println("Not a system class");
		}

		b = loadClassData(name);
		return defineClass(name, b, 0, b.length);
//		l.log(Level.INFO, "Searching for class {0}", name);
	}

	private byte[] loadClassData(String name)
			throws ClassNotFoundException
	{
		final File file = new File("build/classes", name.replace('.', '/').
				concat(".class"));
		BufferedInputStream bis = null;
		byte[] b;
		System.out.println("Loading " + name);

		try {
			final FileInputStream fis = new FileInputStream(file);
			final int len = (int) fis.getChannel().size();

			bis = new BufferedInputStream(fis);
			b = new byte[len];
			bis.read(b, 0, len);

			System.out.println("loaded " + b.length);

			return b;
		}
		catch (IOException ex) {
			throw new ClassNotFoundException("Error reading class file", ex);
		}
		finally {
			try {
				if (bis != null)
					bis.close();
			}
			catch (IOException ex) {
				throw new ClassNotFoundException("Unable to close file", ex);
			}
		}
	}
}
