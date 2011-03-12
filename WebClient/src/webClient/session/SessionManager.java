package webClient.session;

import java.lang.String;
import java.util.HashMap;
import javax.crypto.SecretKey;

/**
 * This class houses static methods to manage session on the web client.
 * @author Alexander Bonomo
 */

public class SessionManager
{
    private static HashMap<String, Session> sessions = new HashMap<String, Session>();

    /**
     * Checks to see if the given user hash is valid
     * @param userHash
     * @return
     */
    public static boolean isUserValid(String userHash)
    {
        return sessions.containsKey(userHash);
    }

    /**
     * Registers a new session
     * @param userHash
     * @param symmetricKey
     */
    public static void registerSession(String userHash, SecretKey symmetricKey)
    {
        sessions.put(userHash, new Session(symmetricKey));
    }

    /**
     * Terminates a session
     * @param userHash
     */
    public static void unregisterSession(String userHash)
    {
        sessions.remove(userHash);
    }

    /**
     * Retrieves a session
     * @param userHash
     * @return
     */
    public static Session getSession(String userHash)
    {
        return sessions.get(userHash);
    }
}
