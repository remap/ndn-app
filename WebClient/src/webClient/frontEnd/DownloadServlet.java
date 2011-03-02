package webClient.frontEnd;

import java.io.IOException;
import java.util.Collection;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.ccnx.ccn.protocol.MalformedContentNameStringException;
import pdc.DataRecord;
import webClient.backEnd.PDCDataRecords;

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
        response.setContentType("text/html");
        response.setStatus(HttpServletResponse.SC_OK);

        response.getWriter().println("<h1> Here are the data records for this stream. </h1>");

        this.m_userHash = request.getParameter(VarNames.USER_HASH);
        //TODO make sure this isn't null
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
         Collection<DataRecord> records;
         try
         {
             PDCDataRecords pdcdr = new PDCDataRecords();
             records = pdcdr.getDataRecords(this.m_userHash);
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
         
         for(DataRecord dr : records)
         {
             //TODO print links for download
         }
     }
}
