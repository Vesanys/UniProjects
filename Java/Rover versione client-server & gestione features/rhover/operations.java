/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package rhover;

/*classe che si occupa delle operazioni*/
 class operations extends Thread
    {
      static String nameFunction;
       public static int i;
       public static boolean stop=false;
     
     @Override
     synchronized public void run()
        {
            if(stop==false){
   
        /*ricavo il nome della funzione richiesta eliminando il primo carattere*/
          //String nameFunction=InClient;
               stop=true;
          /*effettuo uno switch in base alla scelta fatta dall utente*/
          switch(Devicess.scelta)
          {          
              case 1:
              {               
                  /*altro switch per identificare la specifica funzione dello specifico device scelto dall'utente*/
                  switch(nameFunction)
                  {
                      case "Alza":Devicess.outTelecamera.println("Alza");
                         break;
                      case "Abbassa":  Devicess.outTelecamera.println("Abbassa"); 
                          break;
                      case "Ruota a sinistra":  Devicess.outTelecamera.println("Ruota a sinistra");
                          break;
                      case "Ruota a Destra":  Devicess.outTelecamera.println("Ruota a destra");
                          break;
                      case "Scatta foto":  Devicess.outTelecamera.println("Scatta foto");
                          break;
                      case "Rec": Devicess.outTelecamera.println("Rec");
                          break;
                  }        
              }               
                  break;
              case 2:
              {
                  switch(nameFunction)
                  {
                      case "Alza": Devicess.outBraccio.println("Alza");
                          break;
                      case "Abbassa": Devicess.outBraccio.println("Abbassa");
                          break;
                      case "Ruota a sinistra": Devicess.outBraccio.println("Ruota a sinistra");
                          break;
                      case "Ruota a Destra": Devicess.outBraccio.println("Ruota a destra");
                          break;
                      case "Afferra": Devicess.outBraccio.println("Afferra");
                          break;
                      case "Rilascia":Devicess.outBraccio.println("Rilascia");
                          break;                  
                  }
                   
              }break;
              case 3:
              {
                  switch(nameFunction)
                  {
                      case "ON":Devicess.outLuce.println("ON");
                          break;
                      case "OFF": Devicess.outLuce.println("OFF");
                          break;
                      case "Ruota a sinistra": Devicess.outLuce.println("Ruota a sinistra");
                          break;
                      case "Ruota a Destra": Devicess.outLuce.println("Ruota a destra");
                          break;
                      case "Alza":Devicess.outLuce.println("Alza");
                          break;
                      case "Abbassa": Devicess.outLuce.println("Abbassa");
                          break;
                  }  
                  
              }break;
        
          }
      
        }
        }
    
    }