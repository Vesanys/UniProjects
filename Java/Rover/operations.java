/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


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
                      case "Alza":{ 
                          // Rhover.AreaOUTPUT.setText(" ");
                          Rhover.AreaOUTPUT.append("\n telecamera su ");
                         
                      }
                          break;
                      case "Abbassa": {
                         // Rhover.AreaOUTPUT.setText(" ");
                          Rhover.AreaOUTPUT.append("\n telecamera giu");
                      }
                          break;
                      case "Ruota a sinistra": {
                         // Rhover.AreaOUTPUT.setText(" ");
                          Rhover.AreaOUTPUT.append("\n telecamera rotazione sinistra");
                      }
                          break;
                      case "Ruota a Destra": {
                          //Rhover.AreaOUTPUT.setText(" ");
                          Rhover.AreaOUTPUT.append("\n telecamera rotazionw destra");
                      }
                          break;
                      case "Scatta foto":{
                         // Rhover.AreaOUTPUT.setText(" ");
                          Rhover.AreaOUTPUT.append("\n foto scattata");
                      }
                          break;
                      case "Rec":{
                         // Rhover.AreaOUTPUT.setText(" ");
                          Rhover.AreaOUTPUT.append("\n registra");
                      }
                          break;
                  }
              
              
              }               
                  break;
              case 2:
              {
                  switch(nameFunction)
                  {
                      case "Alza": {
                         // Rhover.AreaOUTPUT.setText(" ");
                          Rhover.AreaOUTPUT.append("\n braccio su ");
                       
                      }
                          break;
                      case "Abbassa": {
                         // Rhover.AreaOUTPUT.setText(" ");
                          Rhover.AreaOUTPUT.append("\n braccio giu");
                      }
                          break;
                      case "Ruota a sinistra": {
                         // Rhover.AreaOUTPUT.setText(" ");
                          Rhover.AreaOUTPUT.append("\n braccio rotazione sinistra");
                      }
                          break;
                      case "Ruota a Destra": {
                        //  Rhover.AreaOUTPUT.setText(" ");
                          Rhover.AreaOUTPUT.append("\n braccio rotazione destra");
                      }
                          break;
                      case "Afferra": {
                         // Rhover.AreaOUTPUT.setText(" ");
                          Rhover.AreaOUTPUT.append("\n braccio in presa");
                      }
                          break;
                      case "Rilascia": {
                         // Rhover.AreaOUTPUT.setText(" ");
                          Rhover.AreaOUTPUT.append("\n braccio in rilascio");
                      }
                          break;                  
                  }
                   
              }break;
              case 3:
              {
                  switch(nameFunction)
                  {
                      case "ON":{
                          
                          //Rhover.AreaOUTPUT.setText(" ");
                          Rhover.AreaOUTPUT.append("\n Luce ON");
                      }
                          break;
                      case "OFF": {
                         // Rhover.AreaOUTPUT.setText(" ");
                          Rhover.AreaOUTPUT.append("\n Luce OFF");
                      }
                          break;
                      case "Ruota a sinistra": {
                         // Rhover.AreaOUTPUT.setText(" ");
                          Rhover.AreaOUTPUT.append("\n luce a sinistra");
                      }
                          break;
                      case "Ruota a Destra": {
                         // Rhover.AreaOUTPUT.setText(" ");
                          Rhover.AreaOUTPUT.append("\n luce a destra");
                      }
                          break;
                      case "Alza": {
                         // Rhover.AreaOUTPUT.setText(" ");
                          Rhover.AreaOUTPUT.append("\n luce sopra");
                      }
                          break;
                      case "Abbassa": {
                         // Rhover.AreaOUTPUT.setText(" ");
                          Rhover.AreaOUTPUT.append("\n luce giu");
                      }
                          break;
                  }  
                  
              }break;
        
          }
        
      //  }
        }
        }
    
    }