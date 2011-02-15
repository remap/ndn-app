package webClient.session;

import java.lang.String;
import java.util.HashMap;

/**
 *
 * @author Alexander Bonomo
 */

public class SessionManager
{
    private static HashMap<String, Session> sessions = new HashMap<String, Session>();

    public static boolean isUserValid(String userHash)
    {
        return sessions.containsKey(userHash);
    }

    public static void registerSession(String userHash)
    {
        sessions.put(userHash, new Session());
    }

    public static void unregisterSession(String userHash)
    {
        sessions.remove(userHash);
    }

    public static Session getSession(String userHash)
    {
        return sessions.get(userHash);
    }
}
