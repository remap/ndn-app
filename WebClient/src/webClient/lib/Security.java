package webClient.lib;

import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.NoSuchAlgorithmException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * This class is for security functions for others to use
 * @author Alexander Bonomo
 */
public class Security
{
    /**
     * This function generates a public/private key pair
     * @param keysize - the size of the keys
     * @return - the new public/private key pair
     */
    public static KeyPair generateKeyPair(int keysize)
    {
        KeyPairGenerator kpg;
        try
        {
            kpg = KeyPairGenerator.getInstance("RSA");
        }
        catch (NoSuchAlgorithmException ex)
        {
            //this should never happen
            Logger.getLogger(Security.class.getName()).log(Level.SEVERE, null, ex);
            return null;
        }
        kpg.initialize(keysize);
        return kpg.generateKeyPair();
    }
}
