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
public class Frigorifero extends Thread {
    ServerSocket frigoS = null;
    Socket incoming = null;
    @Override
    public void run() 
    {
       
        try {
            if(incoming==null)
            {
                System.out.println("connessione client rifiutata");
               // frigoS.close();
            
            }
           
            frigoS = new ServerSocket(9077);
            incoming = frigoS.accept();
            
        } catch (IOException ex) {
            Logger.getLogger(Frigorifero.class.getName()).log(Level.SEVERE, null, ex);
        }
       
       
       System.out.println("Rivevuta connessione al frigorifero da parte del client: "+incoming.getInetAddress()+
               "sulla porta: "+incoming.getLocalPort()); 
    /* ora il frigo invia al server la lista delle sue funzioni */
       OutputStream output = null; 
        try {
            output = incoming.getOutputStream();
        } catch (IOException ex) {
            Logger.getLogger(Frigorifero.class.getName()).log(Level.SEVERE, null, ex);
        }
        PrintWriter out=new PrintWriter(output,true);
        /*invio la lista*/
        out.println("FContenuto$Potenza°Temperatura");
    }
    
}
