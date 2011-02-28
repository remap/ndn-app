/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package edu.ucla.cens.pdc.libpdc;

/**
 *
 * @author Derek Kulinski
 */
public interface iBSONExportable {
	/**
	 * Generate a BSON representation of the object
	 * @return BSON encoded as an array of bytes
	 */
	public byte[] toBSON();

	/**
	 * Generate new DataRecord instance from BSON input
	 * @param data array of bytes representing a BSON object
	 * @return new instance of DataRecord
	 */
	public DataRecord fromBSON(byte[] data);
}
