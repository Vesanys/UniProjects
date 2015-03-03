package rhover;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

/**
 *
 * @author josef.vitanostra
 */
/*
================================================================================
================================================================================
*/
class	server
{
	/*
	 =======================================================================
	 =======================================================================
	 */
    protected static ServerSocket server;
    protected static InetAddress IndirizzoServer;
    protected static PrintWriter out;
    protected static Socket incoming;

    public server() throws  java.io.IOException, InterruptedException
	{      
            Rhover.AreaOUTPUT.append("\nIn attesa di una connessione...");  
                incoming=CreateConnection();   
               /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
        
            
                if(incoming!=null){
		
                                    Rhover.labelStatoRV.setBackground(java.awt.Color.green);
                                    Rhover.AreaOUTPUT.append("\n\nConnessione ricevuta. IP "
                                                + "Client: " +incoming.getInetAddress() 
                                                +" alla PORTA: " +incoming.getLocalPort());
                
                                    Rhover.closeConnectionButton.setEnabled(true);
                                    //chiamo il metodo per creare lo stream in out                               
                                   PrintWriter out=StreamOutput();
                                    /*invio la lista al client*/
                                    out.println("Telecamera a infrarossi!Luce*Braccio");
                                    out.flush();/*scarico il buffer*/
                                    
                                    
                                    try
                                    {
				
                                        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
                                        /*
                                        * creo il buffer per la lettura dello stream in input
                                        */
			                 
                                        
                                        BufferedReader	fromClient = new BufferedReader  
                                                (new InputStreamReader(incoming.getInputStream()));
                                          
			
                                        while(true)
                                        {
                                            String InputClient = fromClient.readLine(); 
                                            
                                            if(InputClient.charAt(0) =='F'){
                                                operations.nameFunction=InputClient.substring(1);
                                               // Rhover.AreaOUTPUT.append("\nfunzione "+operations.InClient);
                                                operations op=new operations();
                                                operations.stop=false;
                                                /*faccio partire il thread*/
                                                 op.start();
                                                                            
                                            }
                                            else if(InputClient.charAt(0) =='D')
                                            {
                                                  operations.stop=true;
                                                /* elimino il primo carattere dal nome del device*/
                                                Rhover.AreaOUTPUT.setText("");  
                                                Devicess.nameDevice=InputClient.substring(1);
                                                Rhover.AreaOUTPUT.append("\ndispositivo "+Devicess.nameDevice);
                                                Devicess dev=new Devicess(InputClient);
                                                                                    
                                            }
                                            else
                                            {
                                                SendCommands(InputClient);
                                            
                                            }
                                        }

                                    }
                                    catch(java.io.IOException | java.lang.NumberFormatException e)
                                    {
                                       e.printStackTrace();
		}
	}
               
}
    /*metodo per creare lo stream in output*/
static PrintWriter StreamOutput() throws IOException
{
     OutputStream	outStream = incoming.getOutputStream();
     out = new PrintWriter(outStream, true);
    
    return out;
}  
/*metodo per creare il buffer dello stram in input*/
static BufferedReader StreamInput() throws IOException
{       
     BufferedReader	fromClient = new BufferedReader(new InputStreamReader(incoming.getInputStream()));   
    return fromClient;
}
/*metodo che ha il compito di creare la connessione al server*/
static Socket CreateConnection() throws  java.io.IOException
{
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
            server = new ServerSocket(8088);
            /* ottengo il mio(server) indirizzo ip tramite il metodo "getLocalHost()" */
             IndirizzoServer = InetAddress.getLocalHost();
            /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			/* utilizzo append invece di setText per avere piu linee di stampa*/
            Rhover.AreaOUTPUT.append("\nIP SERVER: " +IndirizzoServer
                +"\n sono in ascolto sulla PORTA: " +server.getLocalPort()
                +"\n");
         /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
             	Socket incoming = server.accept(); 
            /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 
   

  return incoming;
}
/*metodo che ha il compito di chiudere la connessione*/
static void StopConnection()
{
try{
   incoming.close();
   System.out.println("ciao");
   }catch(Exception e)
   {
        Rhover.AreaOUTPUT.append("\nErrore durante il tentativo di chiusura della connessione");
   }

}
public void SendCommands(String InputClient)
        {
               /*
				 * Splitto il buffer letto in input dal client 
                                 * in modo tale da riconoscere il tasto e la 
                                 * velocità
				 */
				String	command = InputClient.substring(1, 2);

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				String	vel = InputClient.substring(2);
				int velocity = Integer.parseInt(vel);
				DoRun	r = new DoRun();
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				switch(command)
				{
				case "1":
					{
						DoRun.stopThread = false;
						r.setVelocity = velocity;
						r.start();
					}
					break;

				case "2":
					{
						DoRun.stopThread = false;
						r.setVelocity = -velocity;
						r.start();
					}
					break;

				case "3":
					{
						DoRun.stopThread = false;
						r.turn = true;
						r.turnL = true;
						r.setVelocity = velocity;
						r.start();
					}
					break;

				case "4":
					{
						DoRun.stopThread = false;
						r.turn = true;
						r.turnL = false;
						r.setVelocity = velocity;
						r.start();
					}
					break;

				case "5":
					{
						/*~~~~~~~~~~~~~~~~~~~*/
						boolean serial = false;
						/*~~~~~~~~~~~~~~~~~~~*/

						r.StopMe(serial);
					}

				default:
					break;
				}
			}       
}


