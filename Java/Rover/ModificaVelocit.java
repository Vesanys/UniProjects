
/**
 *
 * @author josef
 */
class ModificaVelocit extends Thread
{
    public static boolean RealChoice=false;
   Tastiera tasto;
    //synchronized (gestione sezione critica)
    public synchronized void start(boolean isPlus)
    {
        if(RealChoice){
                        tasto=new Tastiera();
                        /* faccio partire il Thread*/
                        tasto.start();
                        }
      
            if(isPlus && Tastiera.setVelocityLabel < 100)
            {
                if(RealChoice){
                    /* assegno al JRadioButton l'ascoltatore per il tasto*/
                                client.plusButton1.addKeyListener(tasto);
                                }
                Tastiera.setVelocityLabel+=5;
                client.RoverVelocit.setText(""+Tastiera.setVelocityLabel);
            }
            else if(!isPlus && Tastiera.setVelocityLabel >-100)
                {
                    if(RealChoice){
                        /* assegno al JRadioButton l'ascoltatore per il tasto*/
                                    client.minusButton1.addKeyListener(tasto);
                                    }
                   Tastiera.setVelocityLabel-=5;
                    client.RoverVelocit.setText(""+Tastiera.setVelocityLabel);
                }
            else if(isPlus && Tastiera.setVelocityLabel >= 100 || !isPlus && Tastiera.setVelocityLabel <=-100)
            {
                client.AreaOUTPUT.append("Impossiile continuare a modificare la velocità limite max raggiunto\n");
            
            }      
    }
}