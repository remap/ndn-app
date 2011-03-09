package webClient.frontEnd;

import edu.ucla.cens.pdc.libpdc.DataRecord;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCEncryptionException;
import edu.ucla.cens.pdc.libpdc.exceptions.PDCParseException;
import java.io.IOException;
import java.util.Collection;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import webClient.backEnd.PDCDataRecords;
import webClient.exceptions.NoSuchUserHashException;
import webClient.session.SessionManager;

/**
 * This class displays the data records in a stream and allows the user to
 * download them.
 * 
 * @author Alexander Bonomo
 */
public class DownloadServlet extends HttpServlet
{
    private String m_userHash;

     @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException
    {
         this.m_userHash = request.getParameter(VarNames.USER_HASH);
         //TODO make sure this isn't null

         String dataStream = request.getParameter(VarNames.DATA_STREAM);
         SessionManager.getSession(m_userHash).setCurrentDataStream(dataStream);

         //check to see if a download was requested
         String record = request.getParameter(VarNames.DATA_RECORD);
         if(record != null)
         {
             DataRecord theRecord = this.getDataRecord(record, response);
             //TODO start download
         }

        response.setContentType("text/html");
        response.setStatus(HttpServletResponse.SC_OK);

        response.getWriter().println("<h1> Here are the data records for this stream. </h1>");
        printRecordsforDownload(request, response);
     }

     /**
      * This method prints the data records so that the user can select which one(s)
      * they would like to download.
      * 
      * @param request
      * @param response
      */
     private void printRecordsforDownload(HttpServletRequest request, HttpServletResponse response)
     {
         //get the list of records
         Collection<String> records;
         try
         {
             PDCDataRecords pdcdr = new PDCDataRecords();
             records = pdcdr.getDataRecordList(this.m_userHash);
             if(records == null)
             {
                 response.getWriter().println("There are no records in this data stream");
                 return;
             }
         }
         catch (NoSuchUserHashException ex)
         {
            Logger.getLogger(DownloadServlet.class.getName()).log(Level.SEVERE, null, ex);
            return;
         }
         catch (PDCEncryptionException ex)
         {
            Logger.getLogger(DownloadServlet.class.getName()).log(Level.SEVERE, null, ex);
            return;
         }
         catch (IOException ex)
         {
            Logger.getLogger(DownloadServlet.class.getName()).log(Level.SEVERE, null, ex);
            return;
         }         
         catch (MalformedContentNameStringException ex)
         {
            Logger.getLogger(DownloadServlet.class.getName()).log(Level.SEVERE, null, ex);
            return;
         }

         //print links for download
         for(String dr : records)
         {
            try 
            {
                response.getWriter().println("<a href=\"" + request.getRequestURL().toString()
                        + "?" + VarNames.DATA_RECORD + "=" + dr + "\"> " + dr
                        + "</a> <br />");
            }
            catch (IOException ex)
            {
                Logger.getLogger(DownloadServlet.class.getName()).log(Level.SEVERE, null, ex);
            }
         }
     }

     private DataRecord getDataRecord(String dataRecord, HttpServletResponse response)
     {
        PDCDataRecords pdcdr = new PDCDataRecords();
        try
        {
            try
            {
                return pdcdr.getDataRecord(m_userHash, dataRecord);
            }
            catch (PDCEncryptionException ex)
            {
                Logger.getLogger(DownloadServlet.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        catch (IOException ex)
        {
            Logger.getLogger(DownloadServlet.class.getName()).log(Level.SEVERE, null, ex);
        }
        catch (MalformedContentNameStringException ex)
        {
            Logger.getLogger(DownloadServlet.class.getName()).log(Level.SEVERE, null, ex);
        }
        catch (PDCParseException ex)
        {
            Logger.getLogger(DownloadServlet.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;
     }
}
