
/**
 *
 * @author josef.vitanostra
 */
 /*
================================================================================
DoRun 
Classe utilizzata per gestire i Thread creati per il moto del Rover	 
================================================================================
	 */

class DoRun extends Thread
{
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	public static  boolean      stopThread=true;
	public int                  setVelocity;
	public boolean              turn = false, turnL = false;
	boolean                     serial = false;
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	/*
	 -----------------------------------------------------------------------
	 Metodo che si attiva quando parte il Thread
	 -----------------------------------------------------------------------
	 */
    @Override
	public synchronized void run()
	{
		try
		{
		/*controllo che la variabile booleana turn sia impostata a false 
		 *se questo e' vero finche la variabile stopThread e' false 
                 * allora il Rover si muove*/
			if(!turn)
			{
				while(!stopThread)
				{	 
					if(setVelocity>=0){ 
							Rhover.AreaOUTPUT.append("\nComando ricevuto: Avanti");		
									}
									else
									{
							Rhover.AreaOUTPUT.append("\nComando ricevuto: Indietro");	
									}
					  Rhover.setMotors(setVelocity,setVelocity); 
					Thread.sleep(1000);
				}
			}
			/* altrimenti significa che l'utente ha pigiato un tasto 
             * per svoltare, controllo che sia quello di sinistra*/
			else if(turnL)
			{
			/*se è vero il rover gira a sinistra */
				while(!stopThread)
				{					
                    Rhover.AreaOUTPUT.append("\nComando ricevuto: Gira a sinistra");                            
					  Rhover.setMotors(-setVelocity,setVelocity);
					Thread.sleep(1000);
				}
			}
			else
			{
			/*altrimenti il Rover gira a destra*/
				while(!stopThread)
				{					
                    Rhover.AreaOUTPUT.append("\nComando ricevuto: Gira a destra");				
					  Rhover.setMotors(setVelocity,-setVelocity);				 
					Thread.sleep(1000);
				}
			}
		}
		catch(Exception e)
		{
			Rhover.AreaOUTPUT.setText("");
            Rhover.AreaOUTPUT.append("Errore durante l'invio dei Thread deputati al movimento ");                      
		}
	}

	/*
	 =======================================================================
	 Metodo che serve a fermare il Thread, infatti setta la variabile 
         * stopThread a true
	 =======================================================================
	 */
	synchronized void StopMe(boolean serial)
	{
	/*la variabile serial è indispensabile al funzionamento inquanto senza 
         * di essa il ciclo while terminerebbe istantaneamente Se siamo in 
         * modalità Seriale*/
		if(!serial)
		{
			stopThread = true;
		}
	}
}
