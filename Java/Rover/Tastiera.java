
/**
 *
 * @author josef
 */
/*
=======================================================================
=======================================================================
*/
class Tastiera extends Thread implements  java.awt.event.KeyListener
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
	public void keyPressed( java.awt.event.KeyEvent e)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~*/
		/*Ricavo il codice del tasto premuto */ 
		int keyCode = e.getKeyCode();
		/*~~~~~~~~~~~~~~~~~~~~~~~~~*/

		switch(keyCode)
		{
		case  java.awt.event.KeyEvent.VK_UP: Connection.out.println(" 1"+setVelocityLabel);			 			
			break;

		case  java.awt.event.KeyEvent.VK_DOWN:Connection.out.println(" 2"+setVelocityLabel);			 			
			break;

		case  java.awt.event.KeyEvent.VK_LEFT: Connection.out.println(" 3"+setVelocityLabel);	
                        break;

		case  java.awt.event.KeyEvent.VK_RIGHT: Connection.out.println(" 4"+setVelocityLabel);	
			break;
		}
	}

	/*
	 -----------------------------------------------------------------------
	 Metodo che si attiva quando il tasto viene rilasciato
	 -----------------------------------------------------------------------
	 */
    @Override
	public void	keyReleased ( java.awt.event.KeyEvent	 e) {
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	 Connection.out.println(" 50");	
	}
	/*
	 -----------------------------------------------------------------------
	 -----------------------------------------------------------------------
	 */
    @Override
	public void	keyTyped( java.awt.event.KeyEvent	 e)	   { }
}
