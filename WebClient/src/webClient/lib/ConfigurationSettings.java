package webClient.lib;

import edu.ucla.cens.pdc.libpdc.iBSONExportable;
import java.util.Map;
import java.util.Set;
import org.bson.BSONObject;

/**
 * The configuration settings for a data stream
 *
 * TODO maybe this should be implemented in the pdc instead
 * 
 * @author Alexander Bonomo
 */
public class ConfigurationSettings implements iBSONExportable, BSONObject
{

    public byte[] toBSON() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public iBSONExportable fromBSON(byte[] data) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public Object put(String string, Object o) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public void putAll(BSONObject bsono) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public void putAll(Map map) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public Object get(String string) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public Map toMap() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public Object removeField(String string) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public boolean containsKey(String string) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public boolean containsField(String string) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public Set<String> keySet() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

}
