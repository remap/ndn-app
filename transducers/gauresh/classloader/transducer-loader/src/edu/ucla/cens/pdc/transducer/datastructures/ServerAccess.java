package edu.ucla.cens.pdc.transducer.datastructures;

public class ServerAccess {

	public static StreamData createNewStream(String appName,String streamId){
		return StreamData.createNewStream(appName,streamId);
	}
	public static StreamData getStream(String appName, String streamId) {
		return StreamData.getStream(appName,streamId);
	}

}
