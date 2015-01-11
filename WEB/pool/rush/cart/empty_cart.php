<?php
include ("../mysqli/sqli_connect.php");

session_start();

if (isset($_SESSION['cart']))
{
	$db = sql_connect();
	$cart = unserialize($_SESSION['cart']);
	foreach ($cart as $key => $val)
	{
		if ($key != "price")
		{
			$query = "UPDATE `product` SET `stock`= (`stock` + '$val') WHERE `ID` = '$key'";
			$cart[$key] = 0;
			mysqli_query($db, $query);
		}
	}
	$cart['price'] = 0;
	$_SESSION['cart'] = NULL;
}
header("Location: index.php");
?>