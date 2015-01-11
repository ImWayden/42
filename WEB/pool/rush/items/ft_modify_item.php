<?php
include ("../mysqli/sqli_connect.php");

function check_exist($db)
{
	$row = mysqli_query($db, "SELECT ID FROM `product`");
	while ($array = mysqli_fetch_array($row, MYSQLI_NUM))
	{
		if ($array[0] == $_POST['ID'])
				return (FALSE);
	}
	return (TRUE);
}

$db = sql_connect();

if ($_POST["oldname"] === "" || check_exist($db) === FALSE)
{
	mysqli_close($db);
	header("Location: ../admin/admin_fail.php");
}
else
{
	$name = $_POST["oldname"];
	$price = $_POST["price"];
	$stock = $_POST["stock"];
	$picture = $_POST["picture"];
	$newname = $_POST["newname"];
	if ($_POST['price'])
	{
		$query = "UPDATE `product` SET `price`= '$price' WHERE ID = '$name'";
		mysqli_query($db, $query);
	}
	if ($_POST['stock'])
	{
		$query = "UPDATE `product` SET `stock`= '$stock' WHERE ID = '$name'";
		mysqli_query($db, $query);
	}
	if ($_POST['picture'])
	{
		$query = "UPDATE `product` SET `picture`= '$picture' WHERE ID = '$name'";
		mysqli_query($db, $query);
	}
	if ($_POST["newname"])
	{
		$query = "UPDATE `product` SET `ID`= '$newname' WHERE ID = '$name'";
		mysqli_query($db, $query);
	}
	mysqli_close($db);
	header("Location: ../admin/admin_succes.php") ;
}
?>