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
public class Luce extends Thread {
    static  PrintWriter out;
     @Override
    public void run()
    {
        ServerSocket luce;
        try {
            luce = new ServerSocket(9003);
            Socket incoming=luce.accept();
             OutputStream output= incoming.getOutputStream(); 
              out=new PrintWriter(output,true);           
              outFunctions();
              
               InputStreamReader fromServer=new InputStreamReader(incoming.getInputStream());
                BufferedReader input=new BufferedReader(fromServer);
                while(true){
                    String inServer=input.readLine(); 
                    
                    switch(inServer)
                {
                    case "ON":Rhover.AreaOUTPUT.append("\n comandi ricevuto dalla luce: "+inServer);
                        break;
                    case "OFF":Rhover.AreaOUTPUT.append("\n comandi ricevuto dalla luce: "+inServer);
                        break;
                    case "Ruota a sinistra":Rhover.AreaOUTPUT.append("\n comandi ricevuto dalla luce: "+inServer);
                        break;
                    case "Ruota a destra":Rhover.AreaOUTPUT.append("\n comandi ricevuto dalla luce: "+inServer);
                        break;
                    case "Alza":Rhover.AreaOUTPUT.append("\n comandi ricevuto dalla luce: "+inServer);
                        break;
                    case "Abbassa":Rhover.AreaOUTPUT.append("\n comandi ricevuto dalla luce: "+inServer);
                        break;
                }
                }
                
        } catch (IOException ex) {
            Logger.getLogger(Telecamera.class.getName()).log(Level.SEVERE, null, ex);
        }
}
      public static void outFunctions()
    {
         out.println("ON!OFF*Ruota a sinistra^Ruota a Destra$Alza£Abbassa");
    
    
    }
}