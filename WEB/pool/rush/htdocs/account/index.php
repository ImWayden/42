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

	<body class="administration">
		<div id="div_middle">
			<h2>Bienvenue sur votre compte, <?php echo $_SESSION['login']; ?></h2>
			<h3>Que voulez-vous faire ?</h3>
			<ul class="ft_list">
				<li><a href="../account/modify_passwd.php">Changer votre Mot de Passe</a></li>
				<li><a href="../cart/index.php">Acceder a votre Panier</a></li>
				<li><a href="../orders/index.php">Voir mes commandes en cours</a></li>
			</ul>
		</div>
	</body>

</div>