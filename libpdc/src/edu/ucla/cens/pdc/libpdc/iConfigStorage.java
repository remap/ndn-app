/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;

/**
 *
 * @author Derek Kulinski
 */
public interface iConfigStorage {
	public ByteArrayInputStream loadEntry(String group, String name)
					throws IOException;

	public void saveEntry(String obj_group, String obj_key,
					ByteArrayOutputStream byte_out)
					throws IOException;

	public void removeEntry(String group, String name)
					throws IOException;
}
