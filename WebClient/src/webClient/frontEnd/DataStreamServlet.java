package webClient.frontEnd;

/**
 *
 * @author Alexander Bonomo
 */

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

public class DataStreamServlet extends HttpServlet
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

     private void printRecordsforDownload(HttpServletRequest request, HttpServletResponse response)
     {
         //TODO: actually get the stream name
         String temp_stream_name = "stream";

         Collection<DataRecord> records;
         try
         {
             PDCDataRecords pdcdr = new PDCDataRecords();
             records = pdcdr.getDataRecords(this.m_userHash, temp_stream_name);
         }
         catch (IOException ex)
         {
            Logger.getLogger(DataStreamServlet.class.getName()).log(Level.SEVERE, null, ex);
            return;
         }
         catch (MalformedContentNameStringException ex)
         {
            Logger.getLogger(DataStreamServlet.class.getName()).log(Level.SEVERE, null, ex);
            return;
         }
         
         for(DataRecord dr : records)
         {
             //TODO print links for download
         }
     }
}
