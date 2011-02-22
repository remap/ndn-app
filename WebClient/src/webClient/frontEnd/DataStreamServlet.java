package webClient.frontEnd;

/**
 *
 * @author Alexander Bonomo
 */

import java.io.IOException;
import java.util.Collection;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import pdc.DataRecord;
import webClient.backEnd.PDCDataRecords;

public class DataStreamServlet extends HttpServlet
{
     @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException
    {
        response.setContentType("text/html");
        response.setStatus(HttpServletResponse.SC_OK);

        response.getWriter().println("<h1> Here are the data records for this stream. </h1>");


     }

     private void printRecordsforDownload(HttpServletRequest request, HttpServletResponse response)
     {
         //TODO: actually get the stream name
         String temp_stream_name = "stream";

         Collection<DataRecord> records = PDCDataRecords.getDataRecords(temp_stream_name, temp_stream_name);

         for(DataRecord dr : records)
         {
             //TODO print links for download
         }
     }
}
