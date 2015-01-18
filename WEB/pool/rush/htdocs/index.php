<?php
include("./mysqli/sqli_connect.php");
session_start();
?>

<!DOCTYPE html>
<html lang="fr">

<!-- HEADER -->

  <head>
	<?php require_once("./includes/head.php"); ?>
	<title>Index - Awesome Starships Battles II</title>
  </head>
  <body>

<!-- NAVBAR -->

<?php
if (isset($_SESSION['login']) && isset($_SESSION["admin"]))
{
  if ($_SESSION["admin"] === "0")
    require_once("./includes/nav_login.php");
  else
    require_once("./includes/nav_admin.php");
}
else
  require_once("./includes/nav_logout.php");
?>

<div class="container">
    <h1 style="text-align:center;">Awesome Starships Battles II</h1>

<!-- PANEL CONTROLE JOUEUR -->

    <div class="col-md-6" style="border:1px solid black;height:256px;">
      <h4 style="text-align:center;">
      <?php 
        if (isset($_SESSION['login']))
          echo "Joueur : ".str_replace('\' ', '\'', ucwords(str_replace('\'', '\' ', strtolower($_SESSION["login"]))));
        else
          print("Joueur Inconnu");
        ?>
      </h4>
      <hr>
      <!-- Choix de la faction -->
      <label style="margin-left:4%;">Factions</label>
      <select name="Factions">
        <option>Gentils</option>
        <option>Méchants</option>
        <option>Neutres</option>
      </select>

      <!-- Choix du vaisseau -->
      <label style="margin-left:2%;">Vaisseaux</label>
      <select name="Vaisseaux">
        <option>StarFighter</option>
        <option>Destructor</option>
        <option>LittleBird</option>
      </select>

      <!-- Choix de l'arme -->
      <label style="margin-left:2%;">Armes</label>
      <select name="Armes">
        <option>StoneFire</option>
        <option>Destructor3000</option>
        <option>CryBaby</option>
      </select>

      <hr>
      <div style="margin-left: 42%;">
        <button type="button" class="btn btn-xs btn-default" style="margin-left: 13%;">HAUT</button><br />
        <button type="button" class="btn btn-xs btn-default">GAUCHE</button>
        <button type="button" class="btn btn-xs btn-default">DROITE</button><br />
        <button type="button" class="btn btn-xs btn-default" style="margin-left: 14%;">BAS</button><br />
      </div>
      <div style="margin-bottom:1%;margin-top:3%;margin-left:45%;">
        <button type="button" class="btn btn-xs btn-danger" style="">FIRE</button>
        <button type="button" class="btn btn-xs btn-success" style="margin-left:2%;">BLOCK</button>
      </div>
    </div>

<!-- CHAT -->

<div class="col-md-6">
    <div style="width:100%;height:256px;background-color:grey;margin-bottom:1%;">
      <?php require_once("./lobby/speak.php"); ?>
    </div>
</div>

<!-- PLATEAU DE JEU -->

    <div class="col-md-12" style="border:1px solid black; margin-top:1%;">
      <h4 style="text-align:center;">Plateau de Jeu</h4>
      <div id="game" style="width:100%;height:700px;background-color:black;margin-bottom:1%;">
      </div>
    </div>

<!-- FOOTER -->

    <hr>
    <?php require_once("./includes/footer.html"); ?>
    <!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js"></script>
    <script type="text/javascript">
      <?php require_once("./includes/script.js"); ?>
    </script>
  </body>
</html>