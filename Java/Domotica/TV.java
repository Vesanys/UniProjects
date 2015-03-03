/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package domotica;

import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author josef
 */
public class TV extends Thread{
    @Override
    public void run()
    {
         ServerSocket TVS = null;
         Socket incoming = null;
        try {
            TVS = new ServerSocket(9078);
            incoming = TVS.accept();
        } catch (IOException ex) {
            Logger.getLogger(Frigorifero.class.getName()).log(Level.SEVERE, null, ex);
        }
       
       
       System.out.println("Rivevuta connessione alla TV da parte del client: "+incoming.getInetAddress()+
               "sulla porta: "+incoming.getLocalPort()); 
    
       
       
       /* ora la tv invia al server la lista delle sue funzioni */
       OutputStream output = null; 
        try {
            output = incoming.getOutputStream();
        } catch (IOException ex) {
            Logger.getLogger(Frigorifero.class.getName()).log(Level.SEVERE, null, ex);
        }
        PrintWriter out=new PrintWriter(output,true);
        /*invio la lista*/
        out.println("FON$OFF°Cambia Canale");
    }
    
}
    

