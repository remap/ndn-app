package webClient.lib;

import java.security.KeyFactory;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.security.PublicKey;
import java.security.spec.InvalidKeySpecException;
import java.security.spec.X509EncodedKeySpec;
import java.util.logging.Level;
import org.ccnx.ccn.config.UserConfiguration;
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

    public static String bytesToHexStr(byte[] bytes)
    {
        StringBuffer buff = new StringBuffer();
        
        for(int i = 0; i < bytes.length; i++)
        {
            String hex = Integer.toHexString(0xFF & bytes[i]);
            if(hex.length() == 1)
                buff.append('0');
            buff.append(hex);
        }

        return buff.toString();
    }

    public static byte[] hexStrToBytes(String hex)
    {
        byte[] keyBytes = new byte[hex.length() / 2];
        for(int i = 0; i < hex.length(); i += 2)
        {
            keyBytes[i/2] = (byte) ((Character.digit(hex.charAt(i), 16) << 4)
                    + Character.digit(hex.charAt(i+1), 16));
        }
        return keyBytes;
    }

    public static PublicKey bytesToPubKey(byte[] bytes)
    {
        X509EncodedKeySpec pubKeySpec = new X509EncodedKeySpec(bytes);
        try
        {
            KeyFactory keyFactory = KeyFactory.getInstance(UserConfiguration.defaultKeyAlgorithm());
            return keyFactory.generatePublic(pubKeySpec);
        }
        catch (InvalidKeySpecException ex)
        {
            java.util.logging.Logger.getLogger(Algorithms.class.getName()).log(Level.SEVERE, null, ex);
        }
        catch (NoSuchAlgorithmException ex)
        {
            java.util.logging.Logger.getLogger(Algorithms.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;
    }
}
