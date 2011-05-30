package edu.ucla.cens.pdc.xmlparser;

import java.util.ArrayList;
import java.util.List;

public class configuration {
	
	private String appId;
	private List<transducerconfig> transducerList;
	//public List<String> outputField;
		
	
	public configuration(){
		appId=null;
		transducerList = new ArrayList<transducerconfig>();
		//outputField = new ArrayList<String>();
	}
	
	public String getAppId(){
		return appId;
	};
	
	public void setAppId(String id){
		appId = id;
	}
	
	/*public List<String> outputField(){
		return outputField;
	}	
	public int outputFieldSize(){
		return outputField.size();
	}
	public String getOutputField(int i){
		return outputField.get(i);
	}*/
	
	
	public int size(){
		return transducerList.size();
	}
	
	/*public String getTransducerId(int i){ //return ith transducer name
		return transducerList.get(i).getTransducerId();
	}*/
	
	public List<transducerconfig> getTransducerConfigList(){
		return transducerList;
	}
	
	public void addTransducer(transducerconfig transducer){
		transducerList.add(transducer);
	}
		
	
	/*public int getInputSize(int i){
		return transducerList.get(i).getinputStreamSize();
	}
	
	
	public List<String> getInputStreamName(int i){
		return transducerList.get(i).;
	}
		
	public String getInput(int i, int j){
		return transducerList.get(i).input.get(j);
	}*/
	
	
	/*public List<String> getFieldList(int i){
		return transducerList.get(i).field;
	}
	public String getField(int i, int j){
		return transducerList.get(i).field.get(j);
	}
	
	public int getFieldSize(int i){
		return transducerList.get(i).field.size();
	}
	
	
	public List<String> getParameterList(int i){
		return transducerList.get(i).parameter;
	}
	public String getParameter(int i, int j){
		return transducerList.get(i).parameter.get(j);
	}
	
	public int getParameterSize(int i){
		return transducerList.get(i).parameter.size();
	}*/
	
}
