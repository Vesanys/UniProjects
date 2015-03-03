<?php

//Inizialmente turno=1, per provare la generazione del turno successivo cambiare il valore in 2 e inserire MANUALMENTE nel DB i Winner_name prima di eseguire il file!
$num_turno = 1;
//Effettuo la connessione al DB
$conn = effettua_connesione();

if($num_turno==1)
{
	
	//effettuo la query per recuperare i nomi degli iscritti al torneo
	$query = "SELECT battletag FROM bc_tornei_iscritti";
	$result = mysql_query($query, $conn) or die('Errore durante la query di selezione nomi iscritti');
	
	// conto il numero di iscritti al torneo
	$numrows = mysql_num_rows($result);
	
	//function crea array
	$battletags = crea_array_nomi($result,$numrows);
	
	//controllo se il numero di partecipanti è DISPARI in questo caso aggiungo in ultima posizione la stringa NESSUNO prima di generare accoppiamenti
	if ($numrows % 2 != 0)$battletags[$numrows+1] = "NESSUNO";
	//richiamo la function "genera_turno()" che prende in input l'array dei partecipanti e il numero di partecipanti e restituisce l'array delle coppie pseudo-casuali
	echo "Scontri generati: <br/>";
	$coppie = genera_turno($battletags,$numrows);
	insert_matches($coppie,$num_turno,$numrows,$conn);
	
	//Effettuo una select per verificare l'effettivo inserimento nella tabella Matches
	$select_matches = "SELECT nome_primo_partecipante,nome_secondo_partecipante FROM tb_matches";
	$ris= mysql_query( $select_matches, $conn )or die('Errore durante la query di selezione dei matches');
	//conto il numero di scontri
	$num_rows = mysql_num_rows($ris);
	
	
	for($k=0;$k<$num_rows;$k++)
	{
		// recupero il contenuto di ogni record trovato
	    $risrow = mysql_fetch_row($ris);
		echo $risrow[0]."-".$risrow[1]."<br/>";
		
	}
	//aggiorno il numero dei turni
	$num_turno++;
}
else 
{
	
	//richiamo funzione pergenerare il TURNO SUCCESSIVO che necessita di 2 parametri: connessione,numero del turno da generare
	$coppie_successive=genera_turno_successivo($conn,$num_turno);
	//effettuo l'inserimento nella tabella matches per il turno successivo
	insert_matches($coppie_successive,$num_turno,count($coppie_successive),$conn);
	//riaggiorno il numero dei turni
	$num_turno++;
}


//FUNCTION Utilizzate

function effettua_connesione()
{
	//parametri di connessione al DB
	$servername = "localhost";
	$username = "root";
	$password = "";
	$dbname = "phpbb3";
	
	
	// Creo la connessione al DB
	$conn = mysql_connect($servername,$username,$password) or die('Errore');
	//seleziono il DB
	mysql_select_db($dbname, $conn);
	//restituisco il riferimento della connessione effettuata
	return $conn;
}
//funzione che permette di generare il primo turno di scontri
function genera_turno($battletags,$numrows)
{
	//generazione accoppiamenti casuali 
	for($i=0; $i < $numrows; $i+=2)
	{
		//se è la prima iterazione
		if($i==0)
		{
			//estraggo l'indice del primo estratto
			$i_prima_estrazione = array_rand($battletags, 1);
			//creo l'array e inserisco il primo nome
			$coppie = array($battletags[$i_prima_estrazione]);
			//cancello dall'array l'occorrenza estratta per evitare casi uguali
			unset($battletags[$i_prima_estrazione]);
			//ripeto i passi precedenti per la seconda iterazione
			$i_seconda_estrazione = array_rand($battletags, 1);
			array_push($coppie, $battletags[$i_seconda_estrazione]);
			unset($battletags[$i_seconda_estrazione]);
		}
		else
		{
			//se non è il primo accoppiamento,invece, estraggo l'indice del partecipante
			$i_prima_estrazione = array_rand($battletags, 1);
			//accodo il partecipante all'array
			array_push($coppie, $battletags[$i_prima_estrazione]);
			//cancello il nome dall'array
			unset($battletags[$i_prima_estrazione]);
			
			//ripeto i passi precedenti per il secondo 
			$i_seconda_estrazione = array_rand($battletags, 1);
			array_push($coppie, $battletags[$i_seconda_estrazione]);
			unset($battletags[$i_seconda_estrazione]);
			
		}
		
		//echo $coppie[$i] ."-". $coppie[$i+1]."<br/>";
	}
	
	//restituisco l'array delle coppie
	return $coppie;
}


//questa function deve essere chiamata DOPO il primo turno, serve a generare le fasi successive
function genera_turno_successivo($conn,$num_turno)
{
	
	//do pers contato che il campo Winner_name sia stato inserito dopo il primo turno
	//recupero i vincitori del turno precedente
	$winner_matches = "SELECT winner_name FROM tb_matches WHERE num_turno=$num_turno-1";
	//effettuo la query
	$result= mysql_query( $winner_matches, $conn)or die('Errore durante la query di selezione dei matches');
	//conto il numero di vincitori
	$numrows = mysql_num_rows($result);
	
	//function crea array
	$winner_battletags = crea_array_nomi($result,$numrows);
	
	//restituisco un array di coppie successive richiamando la funzione "genera_turno()" che crea gli scontri
	return $coppie_successive = genera_turno($winner_battletags,$numrows);
}

function crea_array_nomi($result,$numrows)
{
	// se il database è vuoto lo mostro
	if ($numrows == 0)
	  echo "Database vuoto!";
	// altrimenti
	else
	{	 
	
	 // genero un array con i nomi dei vincitori
	  for ($x = 0; $x < $numrows; $x++)
	  {  
	    // recupero il contenuto di ogni record rovato
	    $resrow = mysql_fetch_row($result);
	    //se è la prima iterazione salvo il nome in un array 
	    if($x==0)$ris = array($resrow[0]);
	    //altrimenti accodo il nuovo nome 
	    else array_push($ris, $resrow[0]);    
	  }
	}
	
	return $ris;
}

//funzione che effettua l'inserimento nel DB degli scontri e il relativo turno di riferimento
function insert_matches($coppie,$num_turno,$numrows,$conn)
{
	//insert nella tabella MATCHES degli accoppiamenti cosi ottenuti
	for($k=0;$k<$numrows;$k+=2)
	{
		//determino un indice per l'avversario
		$p = $k + 1;
		//effettuo l'insert
		$insert_matches = "INSERT INTO tb_matches (nome_primo_partecipante, nome_secondo_partecipante,winner_name,loser_name, tipo_match, num_turno)
		VALUES ('$coppie[$k]', '$coppie[$p]','NULL','NULL', 'BO3','$num_turno')";
	    $ris= mysql_query( $insert_matches, $conn )or die('Errore durante la query di inserimento dei matches');
	}
}

//chiusura connessione al DB
mysql_close($conn);
?>
