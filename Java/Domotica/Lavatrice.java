/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package domotica;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
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
public class Lavatrice extends Thread {
     ServerSocket lavatrice = null;
   static Socket incoming = null;
    @Override
    public void run() 
    {
       
        try {
            lavatrice = new ServerSocket(9081);
            incoming = lavatrice.accept();
        } catch (IOException ex) {
            Logger.getLogger(Frigorifero.class.getName()).log(Level.SEVERE, null, ex);
        }
       
       
       System.out.println("Rivevuta connessione alla lavatrice da parte del client: "+incoming.getInetAddress()+
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
        out.println("FCentrifuga$Lavaggio a secco°Panni bianchi");
       // Operazioni operations= new Operazioni();
        //operations.start();
    }
}
class Operazioni extends Thread
{
    @Override
    public void run()
    {
        try {   
            while(true){
                        BufferedReader fromServer = new BufferedReader(new InputStreamReader(Lavatrice.incoming.getInputStream()));
                         String operazionescelta=fromServer.readLine();
                         
                         switch(operazionescelta)
                         {
                             case "Centrifuga":System.out.println("Centrifuga attivata");
                                 break;
                             case "Lavaggio a secco":System.out.println("Lavaggio a secco attivato");
                                 break;
                             case "Panni bianchi": System.out.println("Lavaggio per panni bianchi attivato");
                                 break;
                         }
                         
            }
        } catch (IOException ex) {
            Logger.getLogger(Operazioni.class.getName()).log(Level.SEVERE, null, ex);
        }
    
    }


}