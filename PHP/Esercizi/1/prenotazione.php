<?php
error_reporting(0); //lo inserisco per eliminare i warning dovuti alla non corrispondenza di una nuova prenotazione nell'array
session_start(); //faccio partire la sessione
$_SESSION["prenotazioni"][$_REQUEST["eventoTxt"]] += $_REQUEST["numTxt"];
 
?>

<html>
<head> Evento prenotato </head>
<body>
<?php
echo "Inserito: " .$_REQUEST["eventoTxt"]. " per posti: " .$_REQUEST["numTxt"]."</br>";
echo "totale: " .$_SESSION["prenotazioni"][$_REQUEST["eventoTxt"]]."</br>";
?>
<a href="form.html">Nuova prenotazione</a>
<a href="elabora.php">Lista prenotazioni</a>   
</body>
</html>
