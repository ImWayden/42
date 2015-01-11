<?php
session_start();

if (isset($_SESSION['login']))
{
	if (isset($_SESSION["admin"]) && $_SESSION["admin"] === "0")
		require_once("../includes/header_login.php");
	else
		require_once("../includes/header_admin.php");
}
else
	require_once("../includes/header_logout.php");

require_once("../includes/footer.php");
?>

<div class="login">
	<h1>Connexion</h1>
	<form action="login_admin.php" method="POST" class="form_login">
		<div id="login_passwd">
			<label for="">Login</label><input id="input" type="text" name="login" placeholder="Login"/><br />
			<label for="">Password</label><input id="input" type="password" name="passwd" placeholder="Password"/><br />
		</div>
		<div>
			<input class="bouton" type="submit" name="submit" value="OK"/>
		</div>
	</form>
</div>
</html>