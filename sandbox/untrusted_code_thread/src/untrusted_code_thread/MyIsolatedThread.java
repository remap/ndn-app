/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package untrusted_code_thread;

import java.lang.reflect.Method;

/**
 *
 * @author Derek Kulinski
 */
public class MyIsolatedThread extends Thread {
	private Object pass = new Object();

	private MyClassLoader loader = new MyClassLoader();

	private MySecurityManager sm = new MySecurityManager(pass);

	@Override
	public void run()
	{
		SecurityManager old = System.getSecurityManager();
		System.setSecurityManager(sm);
		try {
			runUntrustedCode();
		}
		finally {
			sm.disable(pass);
			System.setSecurityManager(old);
		}
	}

	private void runUntrustedCode()
	{
		Class<?> cls;
		Method method;

		try {
			cls = loader.loadClass("untrusted_code_thread.UntrustedCode");
			method = cls.getMethod("main", String[].class);
			method.invoke(null, new Object[]{null});
		}
		catch (Throwable t) {
			throw new Error("Got error while executing untrusted code", t);
		}
	}
}
