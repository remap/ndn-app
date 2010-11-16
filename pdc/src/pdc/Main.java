/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pdc;

import com.mongodb.Mongo;
import com.mongodb.DB;
import com.mongodb.DBCollection;
import com.mongodb.BasicDBObject;
import com.mongodb.DBObject;
import com.mongodb.DBCursor;
import com.mongodb.MongoException;
import java.net.UnknownHostException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author takeda
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Mongo m;
        try {
            m = new Mongo();

            DB db = m.getDB("mydb");
        } catch (UnknownHostException ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        } catch (MongoException ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
