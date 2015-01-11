<div class="all">

<?php
include("../mysqli/sqli_connect.php");
include("../shop/get_item.php");

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
$db = sql_connect();
$items = get_items($db);
$i = 0;
?>

<div class="empty_cart">
	<h4>Voici vos commande en cours</h4>
	<p>Vous n'avez pas de commandes en cours...</p>
</div>

</div>
</html>