<?php
session_start();

if (isset($_SESSION['cart']))
{	
	if (isset($_SESSION['login']))
		echo "Merci pour votre commande !";
	else
	{
		header("Location: ../sign_in/sign_in.php");
		exit("Merci de vous connecter avant de valider votre panier.");
	}
	$cart = unserialize($_SESSION['cart']);
	foreach ($cart as $key => $val)
	{
		if ($key != "price")
			$cart[$key] = 0;
	}
	$cart['price'] = 0;
	$_SESSION['cart'] = NULL;
}
header("Location: index.php");
?>