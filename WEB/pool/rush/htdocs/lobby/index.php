<?php
include("../mysqli/sqli_connect.php");
session_start();
?>

<!DOCTYPE html>
<html lang="fr">

<!-- HEADER -->

  <head>
	<?php require_once("../includes/head.php"); ?>
	<title>Index - Awesome Starships Battles II</title>
  </head>
  <body>

<!-- NAVBAR -->

<?php
if (isset($_SESSION['login']) && isset($_SESSION["admin"]))
{
  if ($_SESSION["admin"] === "0")
    require_once("../includes/nav_login.php");
  else
    require_once("../includes/nav_admin.php");
}
else
  require_once("../includes/nav_logout.php");
?>

<div class="container">
    <h1 style="text-align:center;">Awesome Starships Battles II</h1>

<!-- LOBBY -->

<div class="container">
  <div class="col-sm-12">
    <div style="width:100%;height:300px;background-color:grey;margin-bottom:1%;">
      <?php require_once("../lobby/speak.php"); ?>
    </div>
  </div>
</div>

<!-- FOOTER -->

    <hr>
    <?php require_once("../includes/footer.html"); ?>
    <!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js"></script>
    <script type="text/javascript">
      <?php require_once("../includes/script.js"); ?>
    </script>
  </body>
</html>