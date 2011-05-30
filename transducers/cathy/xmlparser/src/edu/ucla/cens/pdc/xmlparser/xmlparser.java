/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.ucla.cens.pdc.xmlparser;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;

import org.kxml2.io.KXmlParser;
import org.xmlpull.v1.XmlPullParser;
import org.xmlpull.v1.XmlPullParserException;

/**
 *
 * @author akl
 */
public class xmlparser {    
    private KXmlParser parser;
    private configuration config;
    
    xmlparser(){        
        parser=new KXmlParser();
        config = new configuration();
    }
    
    
        
    void setFileName(String filename) throws XmlPullParserException, FileNotFoundException{ 	
    	FileInputStream fis = new FileInputStream(filename);
    	InputStreamReader isr = new InputStreamReader(fis);
    	parser.setInput(isr);
    	//System.out.println("setFileName");
    }
    
    configuration parse() throws Exception{        
        parser.nextTag();    	        	
        parser.require(XmlPullParser.START_TAG, null, "application");
        //System.out.println("parsing application");  
        parser.next();
        config.setAppId(parser.getText().trim());
		//System.out.println(parser.getText().trim());        
        
        while (parser.nextTag () != XmlPullParser.END_TAG){             	
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
        	parser.require(XmlPullParser.START_TAG, null, "transducer");        	        	
        	//add new transducer configuration
        	transducerconfig configToAdd = new transducerconfig();
        	
        	//inside transducer        	
        	
        	parser.next();	        	        	
        	configToAdd.setTransducerId(parser.getText().trim());         	//set transducer name
        	//System.out.println(parser.getText().trim());
        	
        	while (parser.nextTag () != XmlPullParser.END_TAG){         	            
        		if(parser.getName().equals("codeSource")){
        			parser.require(XmlPullParser.START_TAG, null, "codeSource");
        			parser.next();
        			configToAdd.setCodeSource(parser.getText().trim());
        			
        			//System.out.println(parser.getText().trim());
        			parser.nextTag();
        			parser.require(XmlPullParser.END_TAG, null, "codeSource");
        		}
        		
        		else if(parser.getName().equals("inputStream")){
           			String streamName;
           			int start;
           			//int count;
           			
        			parser.require(XmlPullParser.START_TAG, null, "inputStream");
        			
        			parser.nextTag();
        			parser.require(XmlPullParser.START_TAG, null, "streamName");
        			parser.next();
        			streamName = parser.getText().trim();
        			//System.out.println(parser.getText().trim());
        			parser.nextTag();
        			parser.require(XmlPullParser.END_TAG, null, "streamName");
        			
        			parser.nextTag();
        			parser.require(XmlPullParser.START_TAG, null, "start");
        			parser.next();
        			start = Integer.parseInt(parser.getText().trim());
        			//System.out.println(parser.getText().trim());
        			parser.nextTag();
        			parser.require(XmlPullParser.END_TAG, null, "start");
        			
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
        			
        			parser.nextTag();
        			parser.require(XmlPullParser.END_TAG, null, "inputStream");
        		}
        		/*else if(parser.getName().equals("field")){
        			parser.require(XmlPullParser.START_TAG, null, "field");
        			parser.next();
        			//add field to config
        			configToAdd.field.add(parser.getText().trim());
        			
        			parser.nextTag();//get endtag of input
        			parser.require(XmlPullParser.END_TAG, null, "field");
        		}*/
        		
        		else if(parser.getName().equals("outputStream")){
        			parser.require(XmlPullParser.START_TAG, null, "outputStream");        			
        			parser.next();
           			configToAdd.setOutputStream(parser.getText().trim());        				
        			parser.nextTag();//get endtag        		
        			parser.require(XmlPullParser.END_TAG, null, "outputStream");
        		}
        		
        		else{
        			throw new Exception("tag not defined");
        		}
        	}
        	
        	parser.require(XmlPullParser.END_TAG, null, "transducer");
        	config.addTransducer(configToAdd);
        }
        parser.require(XmlPullParser.END_TAG, null, "application");
        parser.next();
        parser.require(XmlPullParser.END_DOCUMENT, null, null);
     
        return config;
    }
}
