<?php
include("../mysqli/sqli_connect.php");

session_start();

if (isset($_SESSION['cart']))
{
	$cart = unserialize($_SESSION['cart']);
	$id = $_GET['item'];
	$db = sql_connect();
	$row = mysqli_query($db, "SELECT * FROM `product`");
	while ($array = mysqli_fetch_array($row, MYSQLI_NUM))
	{
		if ($array[0] == $id )
		{
			$stock = $array[2] + 1;
			$query = "UPDATE `product` SET `stock`= '$stock' WHERE `ID` = '$id'";
			mysqli_query($db, $query);
			$cart[$id]--;
			$cart['price'] -= $array[1];
			$_SESSION['cart'] = serialize($cart);
		}
	}
}
header("Location: index.php");
mysqli_close($db);
?>