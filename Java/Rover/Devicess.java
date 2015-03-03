/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


import java.io.IOException;

/**
 *
 * @author josef
 */
public class Devicess {
   public static int scelta=0;
   public static String nameDevice;
    Devicess(String InputClient) throws IOException
    {
        
        //Rhover.AreaOUTPUT.append("\ndispositivo "+Devicess.nameDevice);
        /* elimino il primo carattere dal nome del device*/
         //nameDevice=InputClient.substring(1);
       /*creo un oggetto della classe operation che si occuperà di gestire le operazioni*/
         
         /*switch che in base al nome del device invia la lista di funzioni disponibili per quel device*/
          switch(Devicess.nameDevice)
          {
           case "Telecamera a infrarossi": {
                                             Devicess.scelta=1;
                                             server.out.println("Alza!Abbassa*Ruota a sinistra^Ruota a Destra$Scatta foto°Rec");
                                             server.out.flush();
           }
            break;
            case "Braccio":{
                             Devicess.scelta=2;
                             server.out.println("Alza!Abbassa*Ruota a sinistra^Ruota a Destra$Afferra°Rilascia");
                             server.out.flush();
            }
            
            break;
            case "Luce":{
                          Devicess.scelta=3;
                          server.out.println("ON!OFF*Ruota a sinistra^Ruota a Destra$Alza°Abbassa");
                          server.out.flush();
            }
            break;
            default:break;
         }
   
        
    }
   
}
