package webClient.log;

import java.util.ArrayList;

/**
 *
 * @author Alexander Bonomo
 */
public class Log extends Thread
{
    private static boolean hasStarted = false;
    private static boolean doStop = false;

    private static ArrayList<String> queue = new ArrayList();

    public Log()
    {
        this.start();
    }

    private void open()
    {
        //TODO
    }

    public static void close()
    {
        doStop = true;
    }

    public static synchronized void write(String s)
    {
        queue.add(s);
    }

    @Override
    public void run()
    {
        if(hasStarted)
            return;

        open();
        hasStarted = true;

        while(!doStop)
        {
            String s = queue.remove(0);

            //TODO write string s to the log
        }

        //TODO close log file
    }
}
