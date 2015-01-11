<?php
session_start();

if (isset($_SESSION['login']))
	require_once("../includes/header_login.php");
else
	require_once("../includes/header_logout.php");

require_once("../includes/footer.php");
?>

<div class="login">
	<h1>Inscription</h1>
	<form action="./create.php" method="POST" class="form_login">
		<div id="login_passwd">
			<label for="">Login</label><input id="input" type="text" name="login" placeholder="Login"/><br />
			<label for="">Password</label><input id="input" type="passwd" name="passwd" placeholder="Password"/><br />
		</div>
		<div>
			<input class="bouton" type="submit" name="submit" value="OK"/>
		</div>
	</form>
	<div class="fail">
		</br>
		This login is already used </br>
		Please try an other one
	</div>
</div>
</html>