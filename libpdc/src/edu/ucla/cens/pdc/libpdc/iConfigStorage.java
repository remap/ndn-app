/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc;

import java.io.IOException;

/**
 *
 * @author Derek Kulinski
 */
public interface iConfigStorage {
	public Object loadEntry(String group, String name)
					throws IOException;

	public void saveEntry(iState object)
					throws IOException;

	public void removeEntry(String group, String name)
					throws IOException;
}
