

import java.awt.Color;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;

/**
 *
 * @author josef
 */
/*
================================================================================
Classe Connection
viene utilizzata per impostare una connessione con il Server
================================================================================
	 */
class	Connection
{
  /* dichiaro la Socket fuori dal costruttore Connection per permettere la 
   * chiusura della stessa da parte tasto stopConnection*/
    public static Socket clien;
    public static PrintWriter out;
   // public static String	InputServer;
    public static BufferedReader	fromServer;
	/*
	 =======================================================================
	 Costruttore della classe Connection
	 =======================================================================
	 */
public Connection() throws UnknownHostException, IOException
  {
           /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
            /* chiamo il metodo per connettermi e creare lo stream in 
              * output*/
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	try
	{    	/*
	 * apro una socket che mi permetterà di collegarmi all'indirizzo d
         * el server sulla porta specificata */
        clien = new Socket(client.campoIPServer.getText(), 8080);
        out=StreamOutput();
                 	}
        catch(Exception e)
            {
               /* in caso di errore
                * pulisco l'area di testo*/
                client.AreaOUTPUT.setText("");
                /* e indico che è avvenuto un errore all'indirizzo specificato*/
		client.AreaOUTPUT.append("\nConnessione non andata a buon fine "
                        + "con indirizzo:"+client.campoIPServer.getText()+"\nRitenta");
            }
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/				
    
	  
        /*pulisco l'area di testo*/
        client.AreaOUTPUT.setText("");
        /* stampo le informazioni di connessione*/
	client.AreaOUTPUT.append("\nConnesso al Server all'indirizzo: " 
          +clien.getInetAddress() +"\nConnesso sulla porta: " +clien.getPort());
        
        /*qui aspetto la lista dei devices connessi al rover*/
       // BufferedReader	fromServer = new BufferedReader(new InputStreamReader(clien.getInputStream()));
        /*ricevo la lista dal client*/
         //String	InputServer = fromServer.readLine();
         /*istanzio un nuovo oggetto per i devices passandogli la lista*/
        String InputServer=StreamInput();
        Devices dev=new Devices(InputServer);
               
        
        /* setto il colore della variabile che indica lo stato della 
         * connessione a verde*/
        client.labelStatoRV.setBackground(Color.green);       
        /* disabilito il campo IPServer, il tasto della connessione e 
         * abilito quello per la disconnessione*/
        client.campoIPServer.setEnabled(false);
        client.connectionButton.setEnabled(false);
        client.stopConnection.setEnabled(true);        

	// abilito i choices
        client.choiceDevices.setEnabled(true);
        client.choiceFunctions.setEnabled(true);
}
static void CloseConnection() throws IOException
{
            clien.close();

}
static PrintWriter StreamOutput() throws UnknownHostException, IOException
{
/* Se viene inserito qualcosa allora.. */	
if(client.campoIPServer.getText() != null)
    {   		
        /* istruzioni che permettono di inviare al server una stringa di testo*/
	OutputStream	outStream = clien.getOutputStream();
	PrintWriter	out = new PrintWriter(outStream, true);
        return out;
    }
        return null;
}

static String StreamInput() throws IOException
{
 BufferedReader	fromServer = new BufferedReader(new InputStreamReader(clien.getInputStream()));
        /*ricevo la lista dal client*/
         String	InputServer = fromServer.readLine();
        return InputServer;
}
}