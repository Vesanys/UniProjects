<?php
  session_start();
  if($_SESSION["punteggi"][$_REQUEST["gameTxt"]]<$_REQUEST["scoreTxt"])
    $_SESSION["punteggi"][$_REQUEST["gameTxt"]] = $_REQUEST["scoreTxt"]; 
?>
<html>
<head>
<title>Punteggio inserito</title>
</head>
<body>
<?php
  echo "Inserito: ".$_REQUEST["gameTxt"]." punti ".$_REQUEST["scoreTxt"]."<br />";
?>
<a href="form.html">Nuovo punteggio</a><br />
<a href="raccolta.php">Lista punteggi</a>
</body>
</html>
