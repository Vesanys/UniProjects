<?php
error_reporting(0);
session_start(); //faccio partire la sessione
?>

<html>
<head>
    <title>Carrello</title>
</head>
<body>
    <?php
    foreach($_SESSION["acquisti"] as $prodotto=>$num)
    {
        $totale+=$num;
        if($num>$max)
        {
            $prodottoMax=$prodotto;
            $max=$num;
            
            
        }
        echo "</br><b>Prodotto acquistat: </b> ".$prodotto.", quantit�: ".$num."</br>";
    }
     echo "</br><b>Totale prodotti acquistati</b> ".$totale."</br>";
     echo "<b>Il prodotto maggiormente acquistato �:</b> ".$prodottoMax."</br>";
    ?>
</body>
</html>