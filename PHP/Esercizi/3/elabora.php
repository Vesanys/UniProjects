<?php
  session_start();
?>
<html>
<head>
<title>Lista valutazioni</title>
</head>
<body>
<h3>Valutazioni effettuate</h3>
<?php
  foreach($_SESSION["valutazioni"] as $film=>$voto) {
    echo $film." voto ".$voto."<br />";
    $totvoti += $voto;
    $totval++;
    if($voto>$maxvoto) {
       $maxvoto = $voto;
       $filmmax = $film;
    }
  }
  echo "<br /><b>Voto medio:</b> ".$totvoti/$totval."<br />";
  echo "<b>Voto max:</b> ".$filmmax." voto ".$maxvoto."<br />";
?>
</body>
</html>

