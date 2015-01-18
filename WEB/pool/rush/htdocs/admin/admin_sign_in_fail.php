<?php
session_start();
?>

<!DOCTYPE html>
<html lang="fr">

<!-- HEADER -->

  <head>
	<?php require_once("../includes/head.php"); ?>
	<title>Admin - Sign-in - Awesome Starships Battles II</title>
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

    <hr>

      <div class="alert alert-danger" role="alert">
        <strong>Oh snap !</strong> Login ou Password incorrect...
      </div>

<div class="login">
	<h1>Connexion</h1>
	<form action="login_admin.php" method="POST" class="form_login">
		<div id="login_passwd">
			<label for="">Login</label><br />
      <input id="input" type="text" name="login" placeholder="Login"/><br />
			<label for="">Password</label><br />
      <input id="input" type="password" name="passwd" placeholder="Password"/><br />
		</div>
		<div>
			<input class="bouton" type="submit" name="submit" value="OK"/>
		</div>
	</form>
	<div class="fail">
		</br>
		Incorrect Admin-Login or Admin-Password </br>
		Please try again
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