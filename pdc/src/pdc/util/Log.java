/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package pdc.util;

/**
 *
 * @author takeda
 */
public class Log {
	static boolean isAssertionEnabled = false;
	static {
		assert isAssertionEnabled = true;
	}

	public static void debug(Object o) {
		if (!isAssertionEnabled)
			return;

		System.err.println(o);
	}

	public static void error(Object o) {
		System.err.println(o);
	}
}
