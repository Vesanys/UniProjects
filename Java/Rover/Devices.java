/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author josef
 */
public class Devices {
    Devices(String InputServer) throws IOException
    {
        /*spezzetto la lista ottenuta*/
        String firstDevice=InputServer.substring(0,InputServer.indexOf('!'));
        String secondDevice=InputServer.substring(InputServer.indexOf('!')+1,InputServer.indexOf('*'));
        String terzoDevice= InputServer.substring(InputServer.indexOf('*')+1);
        
        /*carico la lista nei choices*/
        client.choiceDevices.addItem(" ");
        client.choiceDevices.addItem(firstDevice);
        client.choiceDevices.addItem(secondDevice);
        client.choiceDevices.addItem(terzoDevice);
       
        /*aspetto che l'utente scelga il device*/
         client.choiceDevices.addItemListener(new ItemListener()
        {
            @Override
            public void itemStateChanged(ItemEvent e) {
                 waitList pl=new waitList();
                client.AreaOUTPUT.setText("");
              // pl.interrupt();
                /*quando l'utente sceglie un device ricavo il nome del device scelto e lo invio al server*/
                String nameDevice= client.choiceDevices.getSelectedItem();
                client.AreaOUTPUT.append("\nDispositivo scelto "+nameDevice);
                Connection.out.println("D"+nameDevice);               
                  pl.start();
            }
        
        });
 
    
    }
    
}
 class waitList extends Thread
 { 
    @Override
    public void run() 
    {
                     
        try {
            /*ripulisco il menu a tendina*/
             client.choiceFunctions.removeAll();
             /* leggo dal server*/
             String InputServer = Connection.StreamInput();
           /*spezzetto la lista delle funzioni*/
              String firstFunction=InputServer.substring(0,InputServer.indexOf('!'));              
              String secondFunction=InputServer.substring(InputServer.indexOf('!')+1,InputServer.indexOf('*'));
              String thirdFunction=InputServer.substring(InputServer.indexOf('*')+1,InputServer.indexOf('^'));
              String fourthFunction=InputServer.substring(InputServer.indexOf('^')+1,InputServer.indexOf('$'));
              String fifthFunction=InputServer.substring((InputServer.indexOf('$')+1),InputServer.indexOf('°'));
              String sixthFunction=InputServer.substring((InputServer.indexOf('°')+1));
               
              /*carico le funzioni in un menu a tendina*/
               client.choiceFunctions.addItem("");
               client.choiceFunctions.addItem(firstFunction);
               client.choiceFunctions.addItem(secondFunction);
               client.choiceFunctions.addItem(thirdFunction);
               client.choiceFunctions.addItem(fourthFunction);
               client.choiceFunctions.addItem(fifthFunction);
               client.choiceFunctions.addItem(sixthFunction);
                           
               
              /*lego un ascoltatore per catturare la scelta dell utente*/ 
        client.choiceFunctions.addItemListener(new ItemListener()
        {
            @Override
            public void itemStateChanged(ItemEvent e) {
                /*quando l'utente sceglie una funzione di un determinato device ricavo il nome della funzione scelta*/
                 String nameFunction= client.choiceFunctions.getSelectedItem();
                  client.AreaOUTPUT.setText("");
                client.AreaOUTPUT.append("\nFunzione scelta "+nameFunction);
                /*effettuo l'invio al server tramite lo stream in out aggiungendoci F come identificatore di funzione*/
                 Connection.out.println("F"+nameFunction);
                 Connection.out.flush();
            }
        
        });
        
       
        } catch (IOException ex) {
            Logger.getLogger(waitList.class.getName()).log(Level.SEVERE, null, ex);
        }               
    }
    

}