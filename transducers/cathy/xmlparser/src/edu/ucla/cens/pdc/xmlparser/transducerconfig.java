package edu.ucla.cens.pdc.xmlparser;

import java.util.ArrayList;
import java.util.List;

public class transducerconfig {
	private String transducerId;
	private String codeSource;
	private List<String> inputStreamName; //input list
	private List<Integer> inputStreamStart;
	//private List<Integer> inputStreamCount; 
	//public List<String> field; //field list
	//public List<String> parameter; //parameter list (parameter name is ignored so far)
	private String outputStream;
	
	public transducerconfig(){
		inputStreamName = new ArrayList<String>();
		inputStreamStart = new ArrayList<Integer>();
		//inputStreamCount = new ArrayList<Integer>();
		//field = new ArrayList<String>();
		//parameter = new ArrayList<String>();
	}
	
	public void setTransducerId(String id){
		transducerId = id;
	}
	public String getTransducerId(){
		return transducerId;
	}
	
	public void setCodeSource(String source){
		codeSource = source;
	}
	
	public String getCodeSource(){
		return codeSource;
	}
	
	public int inputStreamsize(){
		return inputStreamName.size();
	}
	
	public void addInputStream(String name, int start){
		inputStreamName.add(name);
		inputStreamStart.add(start);
		//inputStreamCount.add(count);
	}
	
	public String getInputStreamName(int i){
		return inputStreamName.get(i);
	}
	
	public int getInputStreamStart(int i){
		return inputStreamStart.get(i);
	}
	
	/*public int getInputStreamCount(int i){
		return inputStreamCount.get(i);
	}*/
	 
	public void setOutputStream(String out){
		outputStream = out;
	}
	public String getOutputStream(){
		return outputStream;
	}
	
	//TODO: update file
	public void updateInputStart(int index, int start){
		inputStreamStart.set(index, start);
	}
}
