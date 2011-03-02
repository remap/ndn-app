package webClient.session;

import pdc.Application;
import pdc.DataStream;

/**
 *
 * @author Alexander Bonomo
 */
public class Session
{
    /**
     * The URI of the PDV instance
     */
    private String pdv_uri;

    /**
     * PDV instance URI getter
     * @return - the URI of the PDV instance as a String
     */
    public String getPDV_URI()
    {
        return pdv_uri;
    }

    /**
     * PDV instance URI setter
     * @param pdv_uri - the URI of the PDV instance
     */
    public void setPDV_URI(String pdv_uri)
    {
        this.pdv_uri = pdv_uri;
    }

    ////////////////////////////////////////////////////////////////////////////

    /**
     * Possible actions the user could currently be doing.
     */
    public static enum CurrentAction
    {
        DOWNLOAD,
        CONFIGURE,
        UPLOAD
    }

    private CurrentAction currentAction;

    /**
     * Gets the current action.
     * @return - returns null if no action has been selected yet.
     */
    public CurrentAction getCurrentAction()
    {
        return this.currentAction;
    }

    /**
     * Set the current action
     * @param ca - the current action to be set
     */
    public void setCurrentAction(CurrentAction ca)
    {
        this.currentAction = ca;
    }

    /**
     * Resets the current action, current application, and current data stream
     * to null.
     *
     * This should only be called from the home page, or when the web client
     * wants to go back to the home page or earlier.
     */
    public void resetCurrentAction()
    {
        this.currentAction = null;
        this.currentApp = null;
        this.currentDS = null;
    }

    ////////////////////////////////////////////////////////////////////////////

    /**
     * The current application the user has selected
     */
    private Application currentApp;

    /**
     * Gets the current application the user has selected
     * @return - the current app
     */
    public Application getCurrentApp()
    {
        return this.currentApp;
    }

    /**
     * Sets the current app to what the user has selected
     * @param currentApp - the selected app
     */
    public void setCurrentApp(Application currentApp)
    {
        this.currentApp = currentApp;
    }

    ////////////////////////////////////////////////////////////////////////////

    /**
     * The current data stream the user has selected
     */
    private DataStream currentDS;

    public DataStream getCurrentDataStream()
    {
        return this.currentDS;
    }

    public void setCurrentDataStream(DataStream ds)
    {
        this.currentDS = ds;
    }

    ////////////////////////////////////////////////////////////////////////////
}
