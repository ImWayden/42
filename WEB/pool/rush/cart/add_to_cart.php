<?php
include ("../mysqli/sqli_connect.php");

session_start();

if (isset($_SESSION['cart']))
	$cart = unserialize($_SESSION['cart']);
$id = $_GET['item'];
$db = sql_connect();
$row = mysqli_query($db, "SELECT * FROM `product`");

while ($array = mysqli_fetch_array($row, MYSQLI_NUM))
{
	if ($array[0] == $id)
	{
		if ($array[2] != 0)
		{
			$stock = $array[2] - 1;
			$query = "UPDATE `product` SET `stock`= '$stock' WHERE `ID` = '$id'";
			mysqli_query($db, $query);
			$cart['price'] += $array[1];
			$cart[$id]++;
			$_SESSION['cart'] = serialize($cart);
			header("Location: ../shop/index.php");
		}
		else
		{
			header("Location: ../shop/index.php");
		}
	}
	header("Location: ../shop/index.php");
}
?>