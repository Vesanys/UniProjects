package rhover;
/**
 *
 * @author josef.vitanostra
 */
/*
=======================================================================
=======================================================================
*/
class EventiTastiera extends Thread implements java.awt.event.KeyListener
{
	/*
	 =======================================================================
	 =====================================================================*/	
        public static int setVelocityLabel=0;
           
        /*
	 -----------------------------------------------------------------------
	 Metodo che permette di riconoscere il tasto premuto
	 -----------------------------------------------------------------------
	 */
    @Override
	public synchronized void keyPressed(java.awt.event.KeyEvent e)
	{
           
		/*~~~~~~~~~~~~~~~~~~~~~~~~~*/
		/*Ricavo il codice del tasto premuto */ 
		int keyCode = e.getKeyCode();
		/*~~~~~~~~~~~~~~~~~~~~~~~~~*/

		switch(keyCode)
		{
		case java.awt.event.KeyEvent.VK_UP:
			{                       
				 DoRun	 r = new DoRun(); 
				 DoRun.stopThread=false;
				 r.setVelocity=setVelocityLabel;
				 r.start();				 
			}
			break;

		case java.awt.event.KeyEvent.VK_DOWN:
			{
				 DoRun	 r = new DoRun(); 
				 DoRun.stopThread=false;
				 r.setVelocity=-setVelocityLabel;
				 r.start();			 
			}
			break;

		case java.awt.event.KeyEvent.VK_LEFT:
			{
				 DoRun	 r = new DoRun(); 
				 DoRun.stopThread=false;
				 r.turn=true;
				 r.turnL=true;
				 r.setVelocity=setVelocityLabel;
				 r.start();
				 
			}
			break;

		case java.awt.event.KeyEvent.VK_RIGHT:
			{
				 DoRun	 r = new DoRun(); 
				 DoRun.stopThread=false;
				 r.turn=true;
				 r.turnL=false;
				 r.setVelocity=setVelocityLabel;
				 r.start();
				 
			}
			break;
		}
           
	}
	/*
	 -----------------------------------------------------------------------
	 Metodo che si attiva quando il tasto viene rilasciato
	 -----------------------------------------------------------------------
	 */
    @Override
	public void	keyReleased (java.awt.event.KeyEvent	 e) {
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	boolean	 serial = false; 
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	DoRun	 r = new DoRun(); 
	r.StopMe(serial);	
	}
	/*
	 -----------------------------------------------------------------------
	 -----------------------------------------------------------------------
	 */
    @Override
	public void	keyTyped(java.awt.event.KeyEvent	 e)	   { } 
   
}

