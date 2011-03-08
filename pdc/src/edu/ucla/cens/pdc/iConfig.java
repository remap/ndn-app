/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package edu.ucla.cens.pdc;

import com.mongodb.DBObject;

/**
 *
 * @author Derek Kulinski
 */
public interface iConfig extends DBObject {
	public String getCollectionName();
	public String getConfigKey();
}
