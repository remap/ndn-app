package edu.ucla.cens.pdc.transducer.datastructures;

import edu.ucla.cens.pdc.libpdc.datastructures.*;
import edu.ucla.cens.pdc.libpdc.core.*;
import edu.ucla.cens.pdc.libpdc.*;


public final class StreamData {
	private final String streamId;
	private final String appName;
	private final List<DataRecord> dataStream;
	private final int start;
	private final int count;
	GlobalConfig config = GlobalConfig.getInstance();

	private StreamData(String appName,String streamId,Storage dataStore,int start, int count) {
		this.streamId = streamId;
		this.appName = appName;
		this.start = start;
		this.count = count;

		dataStream = dataStore.getRecords(start,count);

	}

	private StreamData(Application app,String appName,String streamId,int count){
		this.streamId = streamId;
		this.appName = appName;
		this.start = 0;
		this.count = count;
		dataStream = new DataStream(config.getHandle(),app,streamId);
		app.addDataStream(dataStream);
	}


	public StreamData getStream(String appName, String streamId,int start,int count){
		//TODO: Change the configuration object

		//Find whether the application already exists	
		Application app = config.getApplication(appName);
		if(app != null)	
			DataStream ds = app.getDataStream(streamId);
			if(ds != null)
				 return new StreamData(appName,streamId,ds.getStorage,start,count);
		return throw new SecurityException("Stream Does not Exists");

	}

	public StreamData createNewStream(String streamId, String appName,int count){

		Application app = config.getApplication(appName);
		if(app != null)
			if(app.getDataStream(streamId) == null) {
				StreamData data = new StreamData(app,appName,streamId,count);			
				return data;
			}
			else
				System.out.println("Please specify a different name for the stream");
		return null;
	}

	
	public void putDataInStream(Map m) {

		dataStream.add(new DataRecord(m));
	}

	public List<DataRecords> getDataStream(){
		return dataStream;
	}

}
