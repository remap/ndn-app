/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package spawning.client;

import java.io.IOException;
import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;
import java.net.MalformedURLException;

/**
 *
 * @author takeda
 */
public class SpawningClient {
	private static Class<? extends iTransducer> getTransducerClass(String pkg,
			String cls_name)
			throws MalformedURLException, ClassNotFoundException
	{
		final TransducerClassLoader loader = new TransducerClassLoader(pkg);
		final Class<? extends iTransducer> transducer_class = loader.load(cls_name);

		return transducer_class;
	}

	private static iTransducer getTransducerInstance(
			Class<? extends iTransducer> cls)
			throws NoSuchMethodException, InstantiationException,
			IllegalAccessException, IllegalArgumentException,
			InvocationTargetException
	{
		final Constructor<? extends iTransducer> constructor = cls.getConstructor();
		return constructor.newInstance();
	}

	/**
	 * @param args the command line arguments
	 */
	@SuppressWarnings("NestedAssignment")
	public static void main(String[] args)
			throws IOException, ClassNotFoundException, InstantiationException,
			IllegalAccessException
	{
		TransducerSecurityManager sm = new TransducerSecurityManager();

		Class<? extends iTransducer> cls = getTransducerClass(args[0], args[1]);
		iTransducer instance = cls.newInstance();

		System.setSecurityManager(sm);

		instance.processData();
	}
}
