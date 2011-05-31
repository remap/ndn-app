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
import edu.ucla.cens.pdc.libpdc.util.Log;
import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.util.LinkedList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Derek Kulinski
 */
public class TransducerClient {
	public TransducerClient(String transducer_id, File directory, String jar_file,
			String class_name, DataStream[][] streams, int[] record_count)
	{
		_transducer_id = transducer_id;

		final List<String> args = new LinkedList<String>();
//		args.add("cat");
		args.add("java");
		args.add("-ea");
		args.add("-jar");
		args.add("dist/transducer-client.jar");
		args.add(jar_file);
		args.add(class_name);

		_transducer_proc_builder = new ProcessBuilder(args);
		_transducer_proc_builder.directory(directory);

		_in_streams = streams[0];
		_out_streams = streams[1];
		_in_stream_count = _in_streams.length;
		_in_stream_recordcount = record_count;

		_in_last_record = new String[_in_stream_count];
	}

	private synchronized void startTransducer()
	{
		if (_transducer_client != null)
			return;

		Log.debug("Starting " + _transducer_id + " transducer");

		try {
			_transducer_client = _transducer_proc_builder.start();
		}
		catch (IOException ex) {
			Logger.getLogger(TransducerClient.class.getName()).log(Level.SEVERE, null,
					ex);
		}
	}

	private synchronized void stopTransducer()
			throws IOException, InterruptedException
	{
		if (_transducer_client == null)
			return;

		TransducerMsg.Message.Builder builder = TransducerMsg.Message.newBuilder();
		builder.setCommand(TransducerMsg.Message.CommandType.TERMINATE);
		builder.build().writeTo(_transducer_client.getOutputStream());
		_transducer_client.getOutputStream().flush();
		_transducer_client.waitFor();
		_transducer_client = null;
	}

	public String getId()
	{
		return _transducer_id;
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

		Log.debug("Executing " + _transducer_id);
		startTransducer();

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

		Log.debug("Sending: " + message.toString());

//		OutputStream os = new FileOutputStream("output.dbg");
//		message.writeTo(os);
//		os.close();

		final OutputStream out = _transducer_client.getOutputStream();
		final InputStream in = _transducer_client.getInputStream();

		final InputStreamReader isr = new InputStreamReader(_transducer_client.
				getErrorStream());
		final BufferedReader br = new BufferedReader(isr);

		while (br.ready()) {
			System.err.println(br.readLine());
		}

		message.writeDelimitedTo(out);
		out.flush();

		while (br.ready()) {
			System.err.println(br.readLine());
		}

		result = TransducerMsg.Message.parseDelimitedFrom(in);

		while (br.ready()) {
			System.err.println(br.readLine());
		}

		Log.debug("Got: " + result.toString());

		data_result = Helpers.deserializeData(result);

		return data_result;
	}

	private final String _transducer_id;

	private final ProcessBuilder _transducer_proc_builder;

	private final int _in_stream_count;

	private final int[] _in_stream_recordcount;

	private final DataStream[] _in_streams;

	private final DataStream[] _out_streams;

	private Process _transducer_client;

	private String[] _in_last_record;
}
