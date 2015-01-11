<div class="all">

<?php
include("../mysqli/sqli_connect.php");
include("./ft_add_item.php");

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

if (count($_POST))
{
	if ($_POST["name"] !== "" && $_POST["picture"] !== "" && $_POST["price"] !== "" && $_POST["stock"] !== "")
	{
		$db = sql_connect();
		ft_add_item($db, $_POST);
		mysqli_close($db);
	}
}
?>

<div class="login">
	<h1>Ajouter un produit</h1>
	<form action="add_item.php" method="POST" class="form_login">
		<div id="login_passwd">
			<label for="">Nom</label><input id="input" type="text" name="name" placeholder="Nom de l'article"/><br />
			<label for="">Photo</label><input id="input" type="text" name="picture" placeholder="URL Photo"/><br />
			<label for="">Prix</label><input id="input" type="text" name="price" placeholder="Prix"/><br />
			<label for="">Stock</label><input id="input" type="stock" name="stock" placeholder="Stock"/><br />
		</div>
		<div>
			<input class="bouton" type="submit" name="submit" value="OK"/>
		</div>
	</form>
</div>
</html>