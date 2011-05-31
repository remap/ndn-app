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
import java.net.MalformedURLException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Derek Kulinski
 */
public class Transducer {
	public static void main(String[] args)
	{
		Transducer t;

		if (args.length < 2) {
			System.err.println("Transducer called incorrectly");
			System.exit(10);
		}

		try {
			t = new Transducer(args[0], args[1]);
			t.start();
		}
		catch (ClassNotFoundException ex) {
			Logger.getLogger(Transducer.class.getName()).log(Level.SEVERE, null, ex);
		}
		catch (InstantiationException ex) {
			Logger.getLogger(Transducer.class.getName()).log(Level.SEVERE, null, ex);
		}
	}

	private static Class<? extends iTransducerClient> getTransducerClass(
			String archive, String class_name)
			throws MalformedURLException, ClassNotFoundException
	{
		final TransducerClassLoader loader = new TransducerClassLoader(archive);
		final Class<? extends iTransducerClient> transducer_class = loader.load(
				class_name);

		return transducer_class;
	}

	public Transducer(String archive, String class_name)
			throws ClassNotFoundException, InstantiationException
	{
		try {
			final Class<? extends iTransducerClient> cls = getTransducerClass(archive,
					class_name);

			_filter = cls.newInstance();
		}
		catch (IllegalAccessException ex) {
			throw new Error("Can't load transducer", ex);
		}
		catch (MalformedURLException ex) {
			throw new Error("Can't load transducer", ex);
		}

	}

	public void start()
	{
		final TransducerSecurityManager sm = new TransducerSecurityManager();
		System.setSecurityManager(sm);

		_running = true;

		while (_running) {
			processMessage();
		}
	}

	private void processMessage()
	{
		TransducerMsg.Message in_message, out_message;

		try {
			in_message = TransducerMsg.Message.parseFrom(System.in);

			if (in_message.hasCommand()) {
				processCommand(in_message);
				return;
			}

			out_message = processData(in_message);
			out_message.writeTo(System.out);
			System.out.flush();
		}
		catch (PDCParseException ex) {
			Logger.getLogger(Transducer.class.getName()).log(Level.SEVERE,
					"Unable to process the data", ex);
		}
		catch (IOException ex) {
			Logger.getLogger(Transducer.class.getName()).log(Level.SEVERE,
					"Error while handling the data", ex);
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

		assert message != null;

		final DataRecord[][] input = Helpers.deserializeData(message);
		assert input != null;

		final DataRecord[][] output = _filter.processData(input);
		assert output != null;

		return Helpers.serializeData(output);
	}

	private boolean _running = false;

	private iTransducerClient _filter;
}
