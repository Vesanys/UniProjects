/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package domotica;

/**
 *
 * @author josef
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;


public class Server extends javax.swing.JFrame {
 PrintWriter out;
  static BufferedReader	fromClient;
  String scelta;
    /**
     * Creates new form Server
     */
  
  public String lettore (Socket sock) throws IOException
  {
       BufferedReader	fromclient = new BufferedReader(new InputStreamReader(sock.getInputStream()));  
       String stringaletta=fromclient.readLine();
        return stringaletta;
  
  }
 class Operazioni extends Thread
 {
     String stringa;
     Socket frigo;
     
     @Override
     public void run()
     {
         
         try {
              while(true){
              scelta=Server.fromClient.readLine();
               System.out.println(scelta);
       
        switch(scelta)
        {
            case "Frigorifero": {   
                  if(frigo!=null)
                  {
                      frigo.close();
                  
                  }
               Frigorifero f= new Frigorifero();
               f.start();
                 frigo=new Socket("localhost",9077);
                /* aspettiamo la lista delle funzioni*/
               String funzioni=lettore(frigo); 
                 /*ora le inviamo al client*/
                out.println(funzioni);
             // frigo.close();
                /*attendiamo la scelta dell'utente*/
              //  String funzscelta=lettore(frigo);
                /*la inviamo al client*/
               // out.println(funzscelta);
               
              //  System.out.println(stringa);
            }
                break;
            case "TV": {
                TV tv=new TV();
                tv.start();
                Socket t=new Socket("localhost",9078);
                /* aspettiamo la lista delle funzioni*/
                String funzioni=lettore(t); 
                 /*ora le inviamo al client*/
                 out.println(funzioni);
               //  t.close();
            }
                break;
            case "Forno": {
                Forno forn=new Forno();
                forn.start();
                Socket forno=new Socket("localhost",9079);
                /* aspettiamo la lista delle funzioni*/
                 String funzioni=lettore(forno); 
                 /*ora le inviamo al client*/
                 out.println(funzioni);
                 //forno.close();
            }
                break;    
                case "Condizionatore": {
                Condizionatore cond=new Condizionatore();
                cond.start();
                Socket condiz=new Socket("localhost",9080);
                /* aspettiamo la lista delle funzioni*/
                  String funzioni=lettore(condiz); 
                 /*ora le inviamo al client*/
                 out.println(funzioni);
                 //condiz.close();
            }
                    break;
                case "Lavatrice": {
                Lavatrice lavatrice=new Lavatrice();
                lavatrice.start();
                Socket lavat=new Socket("localhost",9081);
                /* aspettiamo la lista delle funzioni*/
                 String funzioni=lettore(lavat); 
                 /*ora le inviamo al client*/
                 out.println(funzioni);
                 //lavat.close();
              //    String funzscelta=lettore(lavat);
               // System.out.println(funzscelta);
                  /*la inviamo al client*/
               // out.println(funzscelta);
            }
                    break;
        }
              }
         } catch (IOException ex) {
          
             
             Logger.getLogger(Server.class.getName()).log(Level.SEVERE, null, ex);
         }
     }
 
 }
 
    public Server() throws IOException {
       
        ServerSocket serv=new ServerSocket(8088);
        Socket incoming=serv.accept();
        
        System.out.println("Connessione ricevuta IP:" +incoming.getInetAddress());
        OutputStream output=incoming.getOutputStream(); 
         out=new PrintWriter(output,true);
        out.println("DFrigorifero$TV°Forno&Condizionatore!Lavatrice");
         	fromClient = new BufferedReader(new InputStreamReader(incoming.getInputStream()));   
     
        Server.Operazioni operations=new Server.Operazioni();
        operations.start();
         
        
    }
    public static void main(String[] args) throws IOException
    {
        Server serv=new Server();
    }

}