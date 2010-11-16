/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pdc;

import java.io.IOException;
import org.ccnx.ccn.CCNFilterListener;
import org.ccnx.ccn.CCNHandle;
import org.ccnx.ccn.config.ConfigurationException;
import org.ccnx.ccn.impl.CCNFlowControl.SaveType;
import org.ccnx.ccn.io.content.CCNStringObject;
import org.ccnx.ccn.profiles.namespace.ParameterizedName.PrefixName;
import org.ccnx.ccn.protocol.ContentName;
import org.ccnx.ccn.protocol.Interest;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;

/**
 *
 * @author takeda
 */
public class NDNetwork implements CCNFilterListener {

	private CCNHandle _ccn_handle;
	private String _namespace_str;
	private ContentName _namespace;
	private ContentName _namespace_replication;

	public NDNetwork(String namespace) throws MalformedContentNameStringException, ConfigurationException, IOException {
		_ccn_handle = CCNHandle.open();
		_namespace_str = namespace;
		_namespace = ContentName.fromURI(namespace);
	}

	public boolean handleInterest(Interest interest) {
		throw new UnsupportedOperationException("Not supported yet.");
	}

	private enum namespaces {

		replication
	}

	private String getNamespace(namespaces type) {
		switch (type) {
			case replication:
				return _namespace_str + "/replicate";
		}

		return null;
	}

	public void listen() throws MalformedContentNameStringException, IOException {
		ContentName rep_name = ContentName.fromURI(_namespace, "replicate");
		_ccn_handle.registerFilter(rep_name, this);
	}
}
