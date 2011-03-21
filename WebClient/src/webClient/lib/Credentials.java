package webClient.lib;

import edu.ucla.cens.pdc.libpdc.iBSONExportable;
import java.security.PublicKey;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Set;
import org.bson.BSONDecoder;
import org.bson.BSONEncoder;
import org.bson.BSONObject;

/**
 * This class holds the user's credentials as well as the WC's public key and is
 * translated to BSON before being sent via NDN
 * @author Alexander Bonomo
 */
public class Credentials implements iBSONExportable, BSONObject
{
    Map<String, Object> credentialsAndKey;

    //the keys for the map
    private static final String usernameKey = "username";
    private static final String passwordKey = "password";
    private static final String pubkeyKey   = "pubkey";

    public Credentials(String username, String password, PublicKey pubKey)
    {
        this.credentialsAndKey = new LinkedHashMap<String, Object>();
        this.credentialsAndKey.put(Credentials.usernameKey, username);
        this.credentialsAndKey.put(Credentials.passwordKey, password);
        this.credentialsAndKey.put(Credentials.pubkeyKey, pubKey);
    }

    public String getUsername()
    {
        return (String) this.credentialsAndKey.get(Credentials.usernameKey);
    }

    /**
     * This method returns the password as a string.
     *
     * TODO: will want to eventually only allow a (MD5) hash of the credentials
     * (username + password)  to be accessed
     * @return
     */
    public String getPassword()
    {
        return (String) this.credentialsAndKey.get(Credentials.passwordKey);
    }

    public PublicKey getPublicKey()
    {
        return (PublicKey) this.credentialsAndKey.get(Credentials.pubkeyKey);
    }
    
    public byte[] toBSON()
    {
        try
        {
            BSONEncoder encoder = new BSONEncoder();
            return encoder.encode(this);
        }
        catch(RuntimeException re)
        {
            return null;
        }
    }

    public Credentials fromBSON(byte[] data)
    {
        try
        {
            BSONDecoder decoder = new BSONDecoder();
            this.putAll(decoder.readObject(data));

            return this;
        }
        catch(RuntimeException e)
        {
            return null;
        }
    }

    public Object put(String string, Object o)
    {
        return this.credentialsAndKey.put(string, o);
    }

    public void putAll(BSONObject bsono) 
    {
        this.putAll(bsono.toMap());
    }

    public void putAll(Map map)
    {
        this.credentialsAndKey.putAll(map);
    }

    public Object get(String string)
    {
        if(!this.credentialsAndKey.containsKey(string))
            return null;
        return this.credentialsAndKey.get(string);
    }

    public Map toMap()
    {
        return this.credentialsAndKey;
    }

    public Object removeField(String string) 
    {
        return this.credentialsAndKey.remove(string);
    }

    public boolean containsKey(String string)
    {
        return this.credentialsAndKey.containsKey(string);
    }

    public boolean containsField(String string) 
    {
        return this.credentialsAndKey.containsKey(string);
    }

    public Set<String> keySet()
    {
        return this.credentialsAndKey.keySet();
    }

}
