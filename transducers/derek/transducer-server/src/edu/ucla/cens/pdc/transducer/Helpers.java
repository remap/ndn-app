/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.transducer;

import com.google.protobuf.ByteString;
import edu.ucla.cens.pdc.libpdc.datastructures.DataRecord;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCParseException;

/**
 *
 * @author Derek Kulinski
 */
public class Helpers {
	public static TransducerMsg.Message serializeData(DataRecord[][] input)
	{
		assert input != null;

		final TransducerMsg.Message.Builder msg_builder = TransducerMsg.Message.
				newBuilder();
		final TransducerMsg.Message.StreamData.Builder stream_builder = TransducerMsg.Message.StreamData.
				newBuilder();

		final int stream_count = input.length;
		for (int stream_no = 0; stream_no < stream_count; stream_no++) {
			final int records_count = input[stream_no].length;

			stream_builder.clear();
			for (int record_no = 0; record_no < records_count; record_no++) {
				final byte[] data = input[stream_no][record_no].toBSON();
				stream_builder.addEntry(ByteString.copyFrom(data));
			}

			msg_builder.addData(stream_builder.build());
		}

		return msg_builder.build();
	}

	public static DataRecord[][] deserializeData(TransducerMsg.Message message)
			throws PDCParseException
	{
		assert message != null;

		final int stream_count = message.getDataCount();
		final DataRecord[][] result = new DataRecord[stream_count][];

		int stream_no = 0;
		for (final TransducerMsg.Message.StreamData stream : message.getDataList()) {
			result[stream_no] = new DataRecord[stream.getEntryCount()];

			int data_no = 0;
			for (final ByteString data : stream.getEntryList()) {
				result[stream_no][data_no] = new DataRecord().fromBSON(
						data.toByteArray());
				data_no++;
			}

			stream_no++;
		}

		return result;
	}
}
