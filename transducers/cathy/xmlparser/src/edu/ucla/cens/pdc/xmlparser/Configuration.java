package edu.ucla.cens.pdc.xmlparser;

import java.util.ArrayList;
import java.util.List;

public class Configuration {
	private String _app_id;

	private List<TransducerConfig> _transducer_list;
	//public List<String> outputField;

	public Configuration()
	{
		_app_id = null;
		_transducer_list = new ArrayList<TransducerConfig>();
		//outputField = new ArrayList<String>();
	}

	public String getAppId()
	{
		return _app_id;
	}

	public void setAppId(String id)
	{
		_app_id = id;
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
	public int size()
	{
		return _transducer_list.size();
	}

	/*public String getTransducerId(int i){ //return ith transducer name
	return transducerList.get(i).getTransducerId();
	}*/
	public List<TransducerConfig> getTransducerConfigList()
	{
		return _transducer_list;
	}

	public void addTransducer(TransducerConfig transducer)
	{
		_transducer_list.add(transducer);
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
