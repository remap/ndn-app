/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package edu.ucla.cens.pdc.util;

import java.util.Collection;
import java.util.Iterator;

/**
 *
 * @author Derek Kulinski
 */
public class StringUtil {
	public static String join(Collection<String> list, String delimiter) {
		if (list == null || list.isEmpty())
			return "";

		Iterator<String> iter = list.iterator();
		StringBuilder sb = new StringBuilder(iter.next());
		while (iter.hasNext())
			sb.append(delimiter).append(iter.next());

		return sb.toString();
	}

	public static String stripPrefixChar(String s, String prefix) {
		return s.startsWith(prefix) ? s.substring(1) : s;
	}
}
