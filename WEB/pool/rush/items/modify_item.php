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
	<h1>Modifier un produit</h1>
	<form action="ft_modify_item.php" method="POST" class="form_login">
		<div id="login_passwd">
			<label for="">Nom</label><input id="input" type="text" name="oldname" placeholder="Nom de l'article"/><br />
			<hr>
			<label for="">Nom</label><input id="input" type="text" name="newname" placeholder="Nouveau Nom"/><br />
			<label for="">Photo</label><input id="input" type="text" name="picture" placeholder="Nouvelle Photo"/><br />
			<label for="">Prix</label><input id="input" type="text" name="price" placeholder="Nouveau Prix"/><br />
			<label for="">Stock</label><input id="input" type="stock" name="stock" placeholder="Nouveau Stock"/><br />
		</div>
		<div>
			<input class="bouton" type="submit" name="submit" value="OK"/>
		</div>
	</form>
</div>
</div>
</html>