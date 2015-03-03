package rhover;
/**
 *
 * @author josef.vitanostra
 */

class ModificaVelocita extends Thread
{
    public static boolean RealChoice=false;
    EventiTastiera tasto;
    //synchronized (gestione sezione critica)
    public synchronized void start(boolean isPlus)
    {
        if(RealChoice){
                        tasto=new EventiTastiera();
                        /* faccio partire il Thread*/
                        tasto.start();
                        }
      
            if(isPlus && EventiTastiera.setVelocityLabel < 100)
            {
                if(RealChoice){
                    /* assegno al JRadioButton l'ascoltatore per il tasto*/
                                Rhover.plusButton.addKeyListener(tasto);
                                }
                EventiTastiera.setVelocityLabel+=5;
                Rhover.RoverVelocity.setText(""+EventiTastiera.setVelocityLabel);
            }
            else if(!isPlus && EventiTastiera.setVelocityLabel > 0)
                {
                    if(RealChoice){
                        /* assegno al JRadioButton l'ascoltatore per il tasto*/
                                    Rhover.minusButton.addKeyListener(tasto);
                                    }
                    EventiTastiera.setVelocityLabel-=5;
                    Rhover.RoverVelocity.setText(""+EventiTastiera.setVelocityLabel);
                }
            else if(isPlus && EventiTastiera.setVelocityLabel >= 100 || !isPlus && EventiTastiera.setVelocityLabel <=0)
            {
                Rhover.AreaOUTPUT.append("Impossibile continuare a modificare la velocità limite max raggiunto\n");
            
            }      
    }
}
