/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.libpdc.stream;

import edu.ucla.cens.pdc.libpdc.datastructures.DataRecord;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCDatabaseException;
import edu.ucla.cens.pdc.libpdc.iApplication;
import java.util.List;

/**
 *
 * @author Derek Kulinski
 */
abstract public class Storage {
	public Storage(iApplication app, String data_stream_id)
	{
		assert app != null;
		assert data_stream_id != null && data_stream_id.length() != 0;

		// Initialize your storage here as needed
	}

	/**
	 * The BSON ID of the last element in the table
	 * @return ID of the last element, or null if the database is empty
	 * @throws PDCDatabaseException on database failure
	 * used by transport
	 */
	abstract public String getLastEntry()
			throws PDCDatabaseException;

	/**
	 * Get the list of BSON IDs started from the beginning
	 * currently it would return all IDs in the database, but the code should
	 * work fine even if you return just N of them
	 * @return List of IDs, if database is empty still return list but with 0
	 * elements
	 * @throws PDCDatabaseException on database failure
	 * used by transport
	 */
	abstract public List<String> getRangeIds()
			throws PDCDatabaseException;

	/**
	 * Get the list of BSON IDs started from the BSON ID (not including it)
	 * currently it would return all IDs in the database in given criteria,
	 * but the code should work fine even if you return just N of them
	 * @param start BSON ID from which list should start
	 * @return List of IDs, if database is empty still return list but with 0
	 * elements
	 * @throws PDCDatabaseException on database failure
	 * used by transport
	 */
	abstract public List<String> getRangeIds(String start)
			throws PDCDatabaseException;

	/**
	 * Get the list of BSON IDs starting and ending on given BSON IDs.
	 * This list is inclusive.
	 * @param start starting BSON ID
	 * @param end ending BSON ID
	 * @return List of IDs, if database is empty still return list but with 0
	 * elements
	 * @throws PDCDatabaseException on database failure
	 * used by transport
	 */
	abstract public List<String> getRangeIds(String start, String end)
			throws PDCDatabaseException;

	/**
	 * Get specified record with given Id from the database
	 * @param id BSON ID
	 * @return the record, or null if it doesn't exist
	 * @throws PDCDatabaseException on database failure
	 * used by transport
	 */
	abstract public DataRecord getRecord(String id)
			throws PDCDatabaseException;

	/**
	 * Insert record to the database
	 * @param record record to be inserted
	 * @return returns true on success
	 * @throws PDCDatabaseException on database failure
	 * used by transport
	 */
	abstract public boolean insertRecord(DataRecord record)
			throws PDCDatabaseException;

	/**
	 * Get max count of records
	 * @param from starting from ID (not including it, null starts from beginning)
	 * @param count maximum number of records
	 * @return array of records
	 * @throws PDCDatabaseException on database failure
	 * used by transducers
	 */
	abstract public DataRecord[] getRecords(String from, int count)
			throws PDCDatabaseException;
}
