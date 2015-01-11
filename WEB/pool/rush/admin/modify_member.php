 <div class="all">

<?php
session_start();

if (isset($_SESSION['login']) && isset($_SESSION["admin"]))
{
	if ($_SESSION["admin"] === "0")
		require_once("../includes/header_login.php");
	else
		require_once("../includes/header_admin.php");
}
else
	require_once("../includes/header_logout.php");

require_once("../includes/footer.php");
?>

<div class="login">
	<h1>Modifier un user</h1>
	<form action="ft_modify_member.php" method="POST" class="form_login">
		<div id="login_passwd">
			<label for="">Login</label><input id="input" type="text" name="oldname" placeholder="Login du user"/><br />
			<hr>
			<label for="">Login</label><input id="input" type="text" name="newname" placeholder="Nouveau Login"/><br />
			<label for="">Password</label><input id="input" type="passwd" name="passwd" placeholder="Nouveau Password"/><br />
			<label for="">Role</label><input id="input" type="text" name="admin" placeholder="0 = user / 1 = admin"/><br />
		</div>
		<div>
			<input class="bouton" type="submit" name="submit" value="OK"/>
		</div>
	</form>
</div>
</div>
</html>