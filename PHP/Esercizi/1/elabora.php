<?php
error_reporting(0); //lo inserisco per eliminare i warning dovuti alla non dichiarazione di alcune variabili utilizzate(totale, etc)
session_start(); //faccio partire la sessione
?>

<html>
<head> Lista prenotazioni effettuate </head>
<body>
<?php
 foreach($_SESSION["prenotazioni"] as $evento=>$num)
 {
    echo $evento." per posti: ".$num."</br>";
    $totale+=$num;
    if($num>$max)
    {
        $max=$num;
        $eventomax=$evento;
    }
 }
 echo "</br><b>Totale persone</b> ".$totale."</br>";
echo "<b>Prenotazioni max:</b> ".$eventomax." per posti ".$max."</br>";
?>

</body>
</html>
