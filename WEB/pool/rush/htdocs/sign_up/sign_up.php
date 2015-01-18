<?php
session_start();
?>

<!DOCTYPE html>
<html lang="fr">

<!-- HEADER -->

  <head>
	<?php require_once("../includes/head.php"); ?>
	<title>Sign-up - Awesome Starships Battles II</title>
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

    <hr>

<div class="login" style="text-align:center;">
	<h1>Inscription</h1>
	<form action="./create.php" method="POST" class="form_login">
		<div id="login_passwd">
			<label for="">Login</label><br />
      <input id="input" type="text" name="login" placeholder="Login"/><br />
			<label for="">Password</label><br />
      <input id="input" type="password" name="passwd" placeholder="Password"/><br />
		</div>
		<div style="margin-top:1%;">
      <button type="submit" class="btn btn-xs btn-primary" name="submit">OK</button>
		</div>
	</form>
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