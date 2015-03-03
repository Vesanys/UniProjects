<?php

error_reporting(0);
session_start(); //faccio partire la sessione
$_SESSION["acquisti"][$_REQUEST["nomeProdotto"]] += $_REQUEST["numProdotto"];
?>
<html>
<head>
    <title>Raccolta Acquisti</title>
</head>
<body>
    <?php
    echo "Prodotto scelto: ".$_REQUEST["nomeProdotto"]." pezzi comprati: " ."$_REQUEST[numProdotto]<br/>";
    echo "Totale: " .$_SESSION["acquisti"][$_REQUEST["nomeProdotto"]]; 
    ?>
<br/> <a href="elabora.php">Prosegui</a>
<a href="form.html">Continua acquisti</a>
</body>
</html>
