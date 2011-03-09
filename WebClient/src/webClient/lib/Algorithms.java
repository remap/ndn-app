package webClient.lib;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.logging.Level;
import org.eclipse.jetty.util.log.Logger;

/**
 * This class holds algorithms for others to use
 * @author Alexander Bonomo
 */
public class Algorithms
{
    /**
     * Produces an MD5 hash string of the pdv_uri
     * @param str - the string to produce a hash of
     * @return - a string representing an MD5 hash of the original string
     */
    public static String md5HashStr(String str)
    {
        MessageDigest md;
        try
        {
            md = MessageDigest.getInstance("MD5");
        }
        catch (NoSuchAlgorithmException ex)
        {
            //this should never happen
            java.util.logging.Logger.getLogger(Algorithms.class.getName()).log(Level.SEVERE, null, ex);
            return null;
        }
        md.reset();
        md.update(str.getBytes());
        return new String(md.digest());
    }

    public static byte[] md5Hash(byte[] bytes)
    {
        MessageDigest md;
        try
        {
            md = MessageDigest.getInstance("MD5");
        }
        catch (NoSuchAlgorithmException ex)
        {
            //this should never happen ..
            java.util.logging.Logger.getLogger(Algorithms.class.getName()).log(Level.SEVERE, null, ex);
            return null;
        }
        md.reset();;
        md.update(bytes);
        return md.digest();
    }
}
