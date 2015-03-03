package rhover;

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author josef.vitanostra
 */

class ThreadConnection extends Thread
{
    @Override
   public void run()
   {
       try {
           try {
               server serv=new server();
           } catch (InterruptedException ex) {
               Logger.getLogger(ThreadConnection.class.getName()).log(Level.SEVERE, null, ex);
           }
		  
        } catch (java.io.IOException ex) {
            java.util.logging.Logger.getLogger(server.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
     
   }
    synchronized void Stop()
	{
          
            server.StopConnection();
            Rhover.AreaOUTPUT.append("\nConnessione Terminata...");
		
    }
}