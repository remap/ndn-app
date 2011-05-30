package edu.ucla.cens.pdc.xmlparser;

import java.util.ArrayList;
import java.util.List;

public class TransducerConfig {
	private String _transducer_id;

	private String _code_source;

	private List<String> _input_stream_name; //input list

	private List<Integer> _input_stream_start;
	//private List<Integer> inputStreamCount; 
	//public List<String> field; //field list
	//public List<String> parameter; //parameter list (parameter name is ignored so far)

	private String _output_stream;

	public TransducerConfig()
	{
		_input_stream_name = new ArrayList<String>();
		_input_stream_start = new ArrayList<Integer>();
		//inputStreamCount = new ArrayList<Integer>();
		//field = new ArrayList<String>();
		//parameter = new ArrayList<String>();
	}

	public void setTransducerId(String id)
	{
		_transducer_id = id;
	}

	public String getTransducerId()
	{
		return _transducer_id;
	}

	public void setCodeSource(String source)
	{
		_code_source = source;
	}

	public String getCodeSource()
	{
		return _code_source;
	}

	public int inputStreamsize()
	{
		return _input_stream_name.size();
	}

	public void addInputStream(String name, int start)
	{
		_input_stream_name.add(name);
		_input_stream_start.add(start);
		//inputStreamCount.add(count);
	}

	public String getInputStreamName(int i)
	{
		return _input_stream_name.get(i);
	}

	public int getInputStreamStart(int i)
	{
		return _input_stream_start.get(i);
	}

	/*public int getInputStreamCount(int i){
	return inputStreamCount.get(i);
	}*/
	public void setOutputStream(String out)
	{
		_output_stream = out;
	}

	public String getOutputStream()
	{
		return _output_stream;
	}

	//TODO: update file
	public void updateInputStart(int index, int start)
	{
		_input_stream_start.set(index, start);
	}
}
