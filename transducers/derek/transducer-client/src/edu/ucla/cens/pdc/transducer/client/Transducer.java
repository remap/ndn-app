/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.transducer.client;

import edu.ucla.cens.pdc.libpdc.datastructures.DataRecord;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCParseException;
import edu.ucla.cens.pdc.transducer.Helpers;
import edu.ucla.cens.pdc.transducer.TransducerMsg;
import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Derek Kulinski
 */
public class Transducer {
	public Transducer(int port, iTransducerClient filter)
	{
		this._port = port;
		this._filter = filter;
	}

	public void start()
	{
		_running = true;

		try {
			_socket = new ServerSocket(_port, 0, InetAddress.getLocalHost());

			while (_running) {
				final Socket client_socket = _socket.accept();
				processMessage(client_socket);
			}

			_socket.close();
		}
		catch (IOException ex) {
			throw new Error("Unable to create socket", ex);
		}
	}

	private void processMessage(Socket socket)
			throws IOException
	{
		TransducerMsg.Message in_message, out_message;

		try {
			in_message = TransducerMsg.Message.parseFrom(socket.getInputStream());

			if (in_message.hasCommand()) {
				processCommand(in_message);
				return;
			}

			out_message = processData(in_message);
			out_message.writeTo(socket.getOutputStream());
		}
		catch (PDCParseException ex) {
			Logger.getLogger(Transducer.class.getName()).log(Level.SEVERE,
					"Unable to process the data", ex);
		}
		catch (IOException ex) {
			Logger.getLogger(Transducer.class.getName()).log(Level.SEVERE,
					"Error while handling the data", ex);
		}
		finally {
			socket.close();
		}
	}

	private void processCommand(TransducerMsg.Message message)
	{
		switch (message.getCommand()) {
		case TERMINATE:
			_running = false;
			return;
		}
	}

	private TransducerMsg.Message processData(TransducerMsg.Message message)
			throws PDCParseException
	{
		//TODO: verify that we have proper number of streams with proper amount of data

		final DataRecord[][] input = Helpers.deserializeData(message);
		DataRecord[][] output;

		output = _filter.processData(input);
		assert output != null;

		return Helpers.serializeData(output);
	}

	static int main(String[] args)
	{
		Transducer t;
		int port;

		if (args.length < 1)
			return 10;

		try {
			port = Integer.parseInt(args[0]);

			t = new Transducer(port, new TransducerExample());
			t.start();
		}
		catch (NumberFormatException ex) {
			return 20;
		}

		return 0;
	}

	private int _port;

	private ServerSocket _socket;

	private boolean _running = false;

	private iTransducerClient _filter;
}
