/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package edu.ucla.cens.pdc.libpdc.core;

import java.io.IOException;
import org.ccnx.ccn.config.ConfigurationException;
import org.ccnx.ccn.impl.security.keys.BasicKeyManager;

/**
 *
 * @author Derek Kulinski
 */
public class PDCKeyManager extends BasicKeyManager {
	public PDCKeyManager() throws ConfigurationException, IOException
	{
		super();
	}
}
