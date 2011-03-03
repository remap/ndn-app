package webClient.lib;

import edu.ucla.cens.pdc.libpdc.iBSONExportable;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Set;
import org.bson.BSONObject;

/**
 * This class is the authentication response from the PDV that lets the web client
 * know whether or not the user has been authenticated
 *
 * TODO this class should probably reside in the PDV somewhere
 *
 * @author Alexander Bonomo
 */
public class AuthenticationResponse implements iBSONExportable, BSONObject
{
    //map of the class variables
    private Map<String, Object> classVars = new LinkedHashMap<String, Object>();

    //keys for the map
    private static final String isAuthenticatedKey = "isAuthenticated";
    private static final String symkeyKey = "symkey";
    
    public AuthenticationResponse(boolean isAuthenticated)
    {
        this.classVars.put(AuthenticationResponse.isAuthenticatedKey, new Boolean(isAuthenticated));
        if(isAuthenticated)
        {
            //TODO create symmetric key
        }
    }

    /**
     * check the authentication response
     * @return
     */
    public boolean isAuthenticated()
    {
        return (Boolean)this.classVars.get(isAuthenticatedKey);
    }

    //TODO a getSymmetricKey() function
    
    public byte[] toBSON()
    {
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
