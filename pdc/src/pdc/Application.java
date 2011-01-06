/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pdc;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Stores information about applications that PDV handles
 * @author Derek Kulinski
 */
public class Application {
	final String name;
	//XXX: not thread safe
	private Map<String, DataStream> _data_stream = new HashMap<String, DataStream>();
	private Map<String, PDVNode> _nodes = new HashMap<String, PDVNode>();
	private PDVNode _uplink = null;
	private List<PDVNode> _downlinks = new ArrayList<PDVNode>();
	//XXX: not thread safe

	Application(String name)
	{
		this.name = name;
	}

	/**
	 * Check if given data stream exists
	 * @param id
	 * @return
	 */
	boolean data_stream_exists(String id)
	{
		return _data_stream.containsKey(id);
	}

	DataStream data_stream_get(String id)
	{
		return _data_stream.get(id);
	}

	DataStream data_stream_add(DataStream ds)
	{
		return _data_stream.put(ds.data_stream_id, ds);
	}
}
