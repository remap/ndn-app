/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.transducer;

import edu.ucla.cens.pdc.libpdc.datastructures.DataRecord;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCDatabaseException;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCParseException;
import edu.ucla.cens.pdc.libpdc.stream.DataStream;
import edu.ucla.cens.pdc.libpdc.stream.Storage;
import java.io.IOException;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;

/**
 *
 * @author Derek Kulinski
 */
public class TransducerClient {
	public TransducerClient(String class_name, DataStream[][] streams,
			int[] record_count)
			throws UnknownHostException
	{
		_transducer_class_name = class_name;
		_host = InetAddress.getLocalHost();
		_port = 1234;

		_in_streams = streams[0];
		_out_streams = streams[1];
		_in_stream_count = _in_streams.length;
		_in_stream_recordcount = record_count;
	}
	
	private void startTransducer()
	{
//		ProcessBuilder proc_build = new ProcessBuilder("java", );
	}

	public void newDataCheck()
			throws PDCDatabaseException, IOException, PDCParseException
	{
		assert _in_stream_count > 0;

		assert _in_streams != null && _in_streams.length == _in_stream_count : _in_streams;
		assert _in_last_record != null && _in_last_record.length == _in_stream_count : _in_last_record;
		assert _in_stream_recordcount != null && _in_stream_recordcount.length
				== _in_stream_count : _in_stream_recordcount;

		//make sure we have enough data
		final DataRecord[][] all_records = new DataRecord[_in_stream_count][];
		for (int i = 0; i < _in_stream_count; i++) {
			final DataStream ds = _in_streams[i];
			final Storage store = ds.getStorage();
			final String last = _in_last_record[i];
			final int count = _in_stream_recordcount[i];

			//XXX: Naive implementation, needs to cache results
			all_records[i] = store.getRecords(last, count);

			if (all_records[i].length < _in_stream_recordcount[i])
				return;
		}

		//send data to transducer
		final DataRecord[][] output = processData(all_records);

		//set last mark
		for (int i = 0; i < _in_stream_count; i++) {
			final DataRecord last_record = all_records[i][all_records[i].length - 1];
			_in_last_record[i] = last_record.getId().toStringMongod();
		}

		//write the records
		for (int i = 0; i < _out_streams.length; i++) {
			Storage store = _out_streams[i].getStorage();
			for (int j = 0; j < output[i].length; j++)
				store.insertRecord(output[i][j]);
		}
	}

	private DataRecord[][] processData(DataRecord[][] input)
			throws IOException, PDCParseException
	{
		final TransducerMsg.Message message = Helpers.serializeData(input);
		TransducerMsg.Message result;
		DataRecord[][] data_result;

		final Socket sock = new Socket(_host, _port);

		try {
			message.writeTo(sock.getOutputStream());
			result = TransducerMsg.Message.parseFrom(sock.getInputStream());

			data_result = Helpers.deserializeData(result);

			return data_result;
		}
		finally {
			sock.close();
		}
	}

	private final InetAddress _host;

	private int _port;

	private final String _transducer_class_name;

	private final int _in_stream_count;

	private final int[] _in_stream_recordcount;

	private final DataStream[] _in_streams;

	private final DataStream[] _out_streams;

	private String[] _in_last_record;
}
