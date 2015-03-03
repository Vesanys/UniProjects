<?php
  session_start();
?>
<html>
<head>
<title>Lista punteggi</title>
</head>
<body>
<h3>Punteggi inseriti</h3>
<?php
  foreach($_SESSION["punteggi"] as $game=>$score) {
    echo $game." punti ".$score."<br />";
    if($score>$maxscore) {
       $maxscore = $score;
       $gamemax = $game;
    }
  }
  echo "<br /><b>Punteggio massimo</b> ".$maxscore."<br />";
  echo "<b>Videogioco max:</b> ".$gamemax." punteggio ".$maxscore."<br />";
?>
</body>
</html>

