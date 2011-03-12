package webClient.log;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Date;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * This class represents the log for the web client.  It runs on a separate thread,
 * and you call the static Log.write() method to write to the log.
 * @author Alexander Bonomo
 */
public class Log extends Thread
{
    //log file
    private static String logFileName = "WebClient.log";
    private static PrintStream logFile = null;

    private static boolean hasStarted = false;
    private static boolean doStop = false;

    private static LinkedBlockingQueue<String> queue = new LinkedBlockingQueue<String>();

    public Log()
    {
        this.start();
    }

    private void open() throws FileNotFoundException
    {
        logFile = new PrintStream(new FileOutputStream(logFileName, true));
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

        try
        {
            open();
        }
        catch (FileNotFoundException ex)
        {
            Logger.getLogger(Log.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("Could not open log file.");
            return;
        }
        
        hasStarted = true;

        while(!doStop)
        {
            String s;
            try
            {
                s = queue.take();
            }
            catch (InterruptedException ex)
            {
                Logger.getLogger(Log.class.getName()).log(Level.SEVERE, null, ex);
                //doesn't matter, just continue
                continue;
            }

            Date timestamp = new Date();
            logFile.println("[" + timestamp.toString() + "]: " + s);
            System.out.println(s);
        }
    }
}
