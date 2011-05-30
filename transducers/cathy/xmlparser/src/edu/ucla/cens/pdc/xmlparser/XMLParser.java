/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.xmlparser;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;

import org.kxml2.io.KXmlParser;
import org.xmlpull.v1.XmlPullParser;
import org.xmlpull.v1.XmlPullParserException;

/**
 *
 * @author akl
 */
public class XMLParser {
	private KXmlParser _parser;

	private Configuration _config;

	public XMLParser()
	{
		_parser = new KXmlParser();
		_config = new Configuration();
	}

	public void setFileName(String filename)
			throws XmlPullParserException, FileNotFoundException
	{
		FileInputStream fis = new FileInputStream(filename);
		InputStreamReader isr = new InputStreamReader(fis);
		_parser.setInput(isr);
		//System.out.println("setFileName");
	}

	public Configuration parse()
			throws XmlPullParserException, IOException
	{
		_parser.nextTag();
		_parser.require(XmlPullParser.START_TAG, null, "application");
		//System.out.println("parsing application");  
		_parser.next();
		_config.setAppId(_parser.getText().trim());
		//System.out.println(parser.getText().trim());        

		while (_parser.nextTag() != XmlPullParser.END_TAG) {
			/*if(!parser.getName().equals("transducer")){ //not transducer configuration
			//System.out.println(parser.getName().trim());
			parser.require(XmlPullParser.START_TAG, null, "outputField");
			parser.next();
			config.outputField.add(parser.getText().trim());
			parser.nextTag();
			parser.require(XmlPullParser.END_TAG, null, "outputField");
			continue;
			}*/

			//transducer configuration
			//System.out.println(parser.getName());
			_parser.require(XmlPullParser.START_TAG, null, "transducer");
			//add new transducer configuration
			TransducerConfig configToAdd = new TransducerConfig();

			//inside transducer        	

			_parser.next();
			configToAdd.setTransducerId(_parser.getText().trim());         	//set transducer name
			//System.out.println(parser.getText().trim());

			while (_parser.nextTag() != XmlPullParser.END_TAG) {
				if (_parser.getName().equals("codeSource")) {
					_parser.require(XmlPullParser.START_TAG, null, "codeSource");
					_parser.next();
					configToAdd.setCodeSource(_parser.getText().trim());

					//System.out.println(parser.getText().trim());
					_parser.nextTag();
					_parser.require(XmlPullParser.END_TAG, null, "codeSource");
				} else if (_parser.getName().equals("inputStream")) {
					String streamName;
					int start;
					//int count;

					_parser.require(XmlPullParser.START_TAG, null, "inputStream");

					_parser.nextTag();
					_parser.require(XmlPullParser.START_TAG, null, "streamName");
					_parser.next();
					streamName = _parser.getText().trim();
					//System.out.println(parser.getText().trim());
					_parser.nextTag();
					_parser.require(XmlPullParser.END_TAG, null, "streamName");

					_parser.nextTag();
					_parser.require(XmlPullParser.START_TAG, null, "start");
					_parser.next();
					start = Integer.parseInt(_parser.getText().trim());
					//System.out.println(parser.getText().trim());
					_parser.nextTag();
					_parser.require(XmlPullParser.END_TAG, null, "start");

					/*parser.nextTag();
					parser.require(XmlPullParser.START_TAG, null, "count");
					parser.next();
					count = Integer.parseInt(parser.getText().trim());
					//System.out.println(parser.getText().trim());
					parser.nextTag();
					parser.require(XmlPullParser.END_TAG, null, "count");
					 */

					//add input to config
					configToAdd.addInputStream(streamName, start);

					_parser.nextTag();
					_parser.require(XmlPullParser.END_TAG, null, "inputStream");
				} /*else if(parser.getName().equals("field")){
				parser.require(XmlPullParser.START_TAG, null, "field");
				parser.next();
				//add field to config
				configToAdd.field.add(parser.getText().trim());
				
				parser.nextTag();//get endtag of input
				parser.require(XmlPullParser.END_TAG, null, "field");
				}*/ else if (_parser.getName().equals("outputStream")) {
					_parser.require(XmlPullParser.START_TAG, null, "outputStream");
					_parser.next();
					configToAdd.setOutputStream(_parser.getText().trim());
					_parser.nextTag();//get endtag        		
					_parser.require(XmlPullParser.END_TAG, null, "outputStream");
				} else
					throw new Error("tag not defined");
			}

			_parser.require(XmlPullParser.END_TAG, null, "transducer");
			_config.addTransducer(configToAdd);
		}
		_parser.require(XmlPullParser.END_TAG, null, "application");
		_parser.next();
		_parser.require(XmlPullParser.END_DOCUMENT, null, null);

		return _config;
	}
}
