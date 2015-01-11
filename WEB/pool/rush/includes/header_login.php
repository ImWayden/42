<!DOCTYPE html>
<html>
	<head>
		<?php include("meta.html"); ?>
		<link href="../style/style.css" type="text/css" rel="stylesheet"/>
	</head>
	<header>
		<div>
			<h1>42 ft_minishop</h1>
			<div class="user" id="pseudo">
				User : <?PHP print($_SESSION["login"])?>
			</div>
			<div class="user">
				<button id="logout"><a href="../sign_out/sign_out.php">Logout</a></button>
			</div>
		</div>
		<ul class="menu">
			<li><a href="/index.php">Home</a></li>
			<li><a href="../shop/index.php">Shop</a></li>
			<li><a href="../cart/index.php">Panier</a></li>
			<li><a href="../account/index.php">Mon Compte</a></li>
		</ul>
	</header>