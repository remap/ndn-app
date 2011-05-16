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
        byte[] md5bytes = md.digest();

        //convert it to a hex string
        StringBuffer md5strBuf = new StringBuffer();
        for(int i = 0; i < md5bytes.length; i++)
        {
            String hex = Integer.toHexString(0xFF & md5bytes[i]);
            if(hex.length() == 1) //check to see if a leading zero got chopped off
                md5strBuf.append('0');
            md5strBuf.append(hex);
        }

        return md5strBuf.toString();
    }

    /**
     * Also produces MD5 hash but on byte arrays
     * @param bytes
     * @return
     */
    public static byte[] md5Hash(byte[] bytes)
    {
        MessageDigest md;
        try
        {
            md = MessageDigest.getInstance("MD5");
        }
        catch (NoSuchAlgorithmException ex)
        {
            //this should never happen...
            java.util.logging.Logger.getLogger(Algorithms.class.getName()).log(Level.SEVERE, null, ex);
            return null;
        }
        md.reset();;
        md.update(bytes);
        return md.digest();
    }

    public String hexify(byte[] bytes)
    {
        String retStr = "";
        
        for(int i = 0; i + 4 <= bytes.length; i += 4)
        {
            byte[] current = {bytes[i], bytes[i+1], bytes[i+2], bytes[i+3]};


        }

        return null;
    }
}
