<?php
  session_start();
  if($_SESSION["valutazioni"][$_REQUEST["filmTxt"]]<$_REQUEST["votoTxt"])
    $_SESSION["valutazioni"][$_REQUEST["filmTxt"]] = $_REQUEST["votoTxt"]; 
?>
<html>
<head>
<title>Valutazione inserita</title>
</head>
<body>
<?php
  echo "Inserita: ".$_REQUEST["filmTxt"]." voto ".$_REQUEST["votoTxt"]."<br />";
?>
<a href="form.html">Nuova valutazione</a><br />
<a href="raccolta.php">Lista valutazioni</a>
</body>
</html>
