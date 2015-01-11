<?php
session_start();

if (isset($_SESSION['login']))
	require_once("../includes/header_login.php");
else
	require_once("../includes/header_logout.php");

require_once("../includes/footer.php");
?>

<div class="login">
	<h1>Modification du Mot de Passe</h1>
	<form action="modify.php" method="POST" class="form_login">
		<div id="login_passwd">
			<label for="">Old Pass</label><input id="input" type="password" name="old_passwd" placeholder="Ancien Password"/><br />
			<label for="">New Pass</label><input id="input" type="password" name="new_passwd" placeholder="Nouveau Password"/><br />
		</div>
		<div>
			<input class="bouton" type="submit" name="submit" value="OK"/>
		</div>
	</form>
	<div class="fail">
		</br>
		Please fill all the fields
	</div>
</div>