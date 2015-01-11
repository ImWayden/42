<div class="all">

<?php
include("../mysqli/sqli_connect.php");

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
	<h1>Supprimer un user</h1>
	<form action="ft_delete_member.php" method="POST" class="form_login">
		<div id="login_passwd">
			<label for="">Login</label><input id="input" type="text" name="name" placeholder="Login du user"/><br />
		</div>
		<div>
			<input class="bouton" type="submit" name="submit" value="OK"/>
		</div>
	</form>
</div>
</html>