/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package rhover;

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
 * @author josef.vitanostra
 */
public class Telecamera extends Thread {
    static PrintWriter out;
    @Override
    public void run()
    {
        ServerSocket telecamera;
        try {
            telecamera = new ServerSocket(9001);
            Socket incoming=telecamera.accept();
             System.out.println("connessione ricevuta alla telecamera");
             OutputStream output= incoming.getOutputStream(); 
              out=new PrintWriter(output,true);
              outFunctions();
              
               InputStreamReader fromServer=new InputStreamReader(incoming.getInputStream());
                BufferedReader input=new BufferedReader(fromServer);
                while(true){
                    String inServer=input.readLine(); 
                    
                    switch(inServer)
                {
                    case "Alza":Rhover.AreaOUTPUT.append("\n comandi ricevuto dalla telecamera: "+inServer);
                        break;
                    case "Abbassa":Rhover.AreaOUTPUT.append("\n comandi ricevuto dalla telecamera: "+inServer);
                        break;
                    case "Ruota a sinistra":Rhover.AreaOUTPUT.append("\n comandi ricevuto dalla telecamera: "+inServer);
                        break;
                    case "Ruota a destra":Rhover.AreaOUTPUT.append("\n comandi ricevuto dalla telecamera: "+inServer);
                        break;
                    case "Scatta foto":Rhover.AreaOUTPUT.append("\n comandi ricevuto dalla telecamera: "+inServer);
                        break;
                    case "Rec":Rhover.AreaOUTPUT.append("\n comandi ricevuto dalla telecamera: "+inServer);
                        break;
                }
                }
                
        } catch (IOException ex) {
            Logger.getLogger(Telecamera.class.getName()).log(Level.SEVERE, null, ex);
        }         
    
    }
   public static void outFunctions()
    {
         out.println("Alza!Abbassa*Ruota a sinistra^Ruota a Destra$Scatta foto£Rec");
    
    
    }
}
