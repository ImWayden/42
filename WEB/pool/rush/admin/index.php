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
			<h2>Bienvenue sur la page d'administration, <?php echo $_SESSION['login']; ?></h2>
			<h3>Que voulez-vous faire ?</h3>
			<ul class="ft_list">
				<li><a href="../items/add_item.php">Ajouter un Article</a></li>
				<li><a href="../items/modify_item.php">Modifier un Article</a></li>
				<li><a href="../items/delete_item.php">Supprimer un Article</a></li>
				<li><a href="./modify_member.php">Modifier un Membre</a></li>
				<li><a href="./delete_member.php">Supprimer un Membre</a></li>
			</ul>
		</div>
	</body>
</div>
</html>