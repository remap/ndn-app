package edu.ucla.cens.pdc.transducer.datastructures;
import edu.ucla.cens.pdc.libpdc.exceptions.*;
import edu.ucla.cens.pdc.libpdc.stream.*;
import edu.ucla.cens.pdc.libpdc.transport.*;
import edu.ucla.cens.pdc.libpdc.unused.*;
import edu.ucla.cens.pdc.libpdc.util.*;
import edu.ucla.cens.pdc.libpdc.datastructures.*;
import edu.ucla.cens.pdc.libpdc.core.*;
import edu.ucla.cens.pdc.libpdc.*;
import java.util.*;
import java.io.IOException;


public final class StreamData {
	private final String streamId;
	private final String appName;
	private final DataStream ds;
	private String start;
	static GlobalConfig config = GlobalConfig.getInstance();

	private StreamData(String appName,String streamId,DataStream ds, int count) {
		this.streamId = streamId;
		this.appName = appName;
		this.ds = ds;

	}

	private StreamData(Application app,String appName,String streamId,int count) throws IOException{
		this.streamId = streamId;
		this.appName = appName;
		this.start = null;
		this.ds = new DataStream(config.getCCNHandle(),app,streamId);
			
	}


	public StreamData getStream(String appName, String streamId,int count){
		//TODO: Change the configuration object

		//Find whether the application already exists	
		Application app = config.getApplication(appName);
		if(app != null){	
			DataStream ds = app.getDataStream(streamId);
			if(ds != null){
				 return new StreamData(appName,streamId,ds,count);
			}
		}
		throw new SecurityException("Stream Does not Exists");

	}

	public static StreamData createNewStream(String streamId, String appName,int count){
		try{
		Application app = config.getApplication(appName);
		if(app != null)
			if(app.getDataStream(streamId) == null) {
				StreamData data = new StreamData(app,appName,streamId,count);			
				app.addDataStream(data.ds);
				return data;
			}
			else
				System.out.println("Please specify a different name for the stream");
		}catch(IOException e){
			return null;
		}
		System.out.println("Application not found");
		return null;
	}

	
	public boolean putDataInStream(Map m) {
		Storage storage = this.ds.getStorage();
		try {
			storage.insertRecord(new DataRecord(m));
		}catch(PDCDatabaseException pdcdbexp){
			return false;
		}
		return true;
		
	}

	public  Map[] getDataStream(int count){
		DataRecord[] listOfRec;
		Map[] listOfMap;
		Storage	storage = this.ds.getStorage();
		try {	
			listOfRec = storage.getRecords(this.start,count);
		}catch(PDCDatabaseException pdcdb){
			return null;
		}
	
		this.start = listOfRec[listOfRec.length - 1].getId().toStringMongod();
		//TODO:Make changes to the configuration update start
		listOfMap = new Map[listOfRec.length];
		
		for(int i = 0; i <  listOfRec.length; i++)
			listOfMap[i] = listOfRec[i].toMap();	


		return listOfMap;
	}

	

}
