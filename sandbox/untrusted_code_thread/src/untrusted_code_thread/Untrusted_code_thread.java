/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package untrusted_code_thread;

/**
 *
 * @author takeda
 */
public class Untrusted_code_thread {
	/**
	 * @param args the command line arguments
	 */
	public static void main(String[] args)
			throws InterruptedException
	{
		Thread untrusted;

		TrustedCode trusted = new TrustedCode();
		trusted.doUnprivilegedStuff();
		trusted.doPrivilegedStuff();

		System.out.println("Loading untrusted code");

		untrusted = new MyIsolatedThread();
		untrusted.start();
		untrusted.join();

		System.out.println("Untrusted code ended its job");

		trusted.doUnprivilegedStuff();
		trusted.doPrivilegedStuff();
	}
}
