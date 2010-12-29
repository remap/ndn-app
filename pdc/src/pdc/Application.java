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
 *
 * @author takeda
 */
class Application {

	final String name;
	//XXX: not thread safe
	private Map<String, DataStream> _data_stream = new HashMap<String, DataStream>();
	private Map<String, PDVNode> _nodes = new HashMap<String, PDVNode>();
	private List<PDVNode> _uplinks = new ArrayList<PDVNode>();
	private List<PDVNode> _downlinks = new ArrayList<PDVNode>();
	//XXX: not thread safe

	enum NodeType {

		UPLINKS,
		DOWNLINKS
	}

	enum Operation {

		ADD,
		REMOVE
	}

	Application(String name) {
		this.name = name;
	}

	void set_node(NodeType type, Operation operation, PDVNode node) {
		List<PDVNode> list = null;

		switch (type) {
			case DOWNLINKS:
				list = _downlinks;
				break;
			case UPLINKS:
				list = _uplinks;
		}

		assert list != null;

		switch (operation) {
			case ADD:
				list.add(node);
				break;
			case REMOVE:
				list.remove(node);
		}
	}

	/**
	 * Check if given data stream exists
	 * @param id
	 * @return
	 */
	boolean data_stream_exists(String id) {
		return _data_stream.containsKey(id);
	}

	/**
	 * Get an encryption key for given data stream
	 * @param id
	 * @return key or null if doesn't exists
	 */
	byte[] data_stream_get_key(String id) {
		DataStream ds = _data_stream.get(id);
		if (ds == null)
			return null;

		return ds.key;
	}

	/**
	 * Set an encryption key for a given acl hash
	 * @param id
	 * @param key
	 */
	void data_stream_set_key(String id, final byte[] key) {
		DataStream ds = _data_stream.get(id);
		if (ds == null) {
			ds = new DataStream(name, id);
			ds.key = key.clone();
			_data_stream.put(id, ds);

			return;
		}

		ds.key = key.clone();
	}
}
