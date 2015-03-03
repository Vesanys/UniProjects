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
import java.net.Socket;

/**
 *
 * @author josef
 */
public class Devicess {
   public static int scelta=0;
   public static String nameDevice;
   public static BufferedReader inputT,inputB,inputL;
   public static PrintWriter outTelecamera,outBraccio,outLuce;
   public static boolean stopConnessioneTelecamera=false,stopConnessioneBraccio=false,stopConnessioneLuce=false;
  private Socket telecamera,braccio,luc;
   
    Devicess(String InputClient) throws IOException
    {
         /*switch che in base al nome del device invia la lista di funzioni disponibili per quel device*/
          switch(Devicess.nameDevice)
          {
           case "Telecamera a infrarossi": {
                                             Devicess.scelta=1;
                                             if(!stopConnessioneTelecamera){
                                                 stopConnessioneTelecamera=true;
                                             Telecamera telec=new Telecamera();
                                             telec.start();
                                              telecamera=new Socket("localhost",9001);
                                             InputStreamReader fromTelecamera=new InputStreamReader(telecamera.getInputStream());
                                              inputT=new BufferedReader(fromTelecamera);
                                             String inTel=inputT.readLine();                                       
                                             server.out.println(inTel);
                                             server.out.flush();
                                             OutputStream output= telecamera.getOutputStream(); 
                                             outTelecamera=new PrintWriter(output,true);
                                             }
                                             else
                                             {
                                                Telecamera.outFunctions();
                                               String listafunzioni=inputT.readLine();                                       
                                             server.out.println(listafunzioni);
                                             }                                     
           }
            break;
            case "Braccio":{
                             Devicess.scelta=2;
                             if(!stopConnessioneBraccio){
                                 stopConnessioneBraccio=true;
                              Braccio brac=new Braccio();
                              brac.start();
                               braccio=new Socket("localhost",9002);
                              InputStreamReader fromBraccio=new InputStreamReader(braccio.getInputStream());
                              inputB=new BufferedReader(fromBraccio);
                              String inBrac=inputB.readLine();                                       
                              server.out.println(inBrac);
                              server.out.flush();
                              OutputStream output= braccio.getOutputStream(); 
                              outBraccio=new PrintWriter(output,true);
                             }  else
                                 {
                                   Braccio.outFunctions();
                                   String listafunzioni=inputB.readLine();                                       
                                   server.out.println(listafunzioni);
                                   }                                    
            }           
            break;
            case "Luce":{
                          Devicess.scelta=3;
                          if(!stopConnessioneLuce){
                              stopConnessioneLuce=true;                         
                          Luce luce=new Luce();
                          luce.start();
                           luc=new Socket("localhost",9003);
                          InputStreamReader fromLuce=new InputStreamReader(luc.getInputStream());
                          inputL=new BufferedReader(fromLuce);
                          String inLuce=inputL.readLine();                                       
                          server.out.println(inLuce);
                          server.out.flush();
                          OutputStream output= luc.getOutputStream(); 
                          outLuce=new PrintWriter(output,true);
                          }  else
                            {
                               Luce.outFunctions();
                               String listafunzioni=inputL.readLine();                                       
                               server.out.println(listafunzioni);
                              }                                   
            }
            break;
            default:break;
         }        
    }   
}
