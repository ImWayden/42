<?php
include ("../mysqli/sqli_connect.php");

function check_exist($db)
{
	$row = mysqli_query($db, "SELECT login FROM `user`");
	while ($array = mysqli_fetch_array($row, MYSQLI_NUM))
	{
		if ($array[0] == $_POST['newname'])
				return (FALSE);
	}
	return (TRUE);
}

$db = sql_connect();

if ($_POST["oldname"] === "" || check_exist($db) === FALSE)
{
	mysqli_close($db);
	header("Location: ./admin_fail.php");
}
else
{
	$name = $_POST["oldname"];
	$size = $_POST["admin"];
	$passwd = hash("whirlpool", $_POST["passwd"]);
	$newname = $_POST["newname"];
	if ($_POST['passwd'])
	{
		$query = "UPDATE `user` SET `passwd`= '$passwd' WHERE login = '$name'";
		mysqli_query($db, $query);
	}
	if ($_POST['admin'] === 0 || $_POST['admin'] === 1)
	{
		$query = "UPDATE `user` SET `admin`= '$admin' WHERE login = '$name'";
		mysqli_query($db, $query);
	}
	if ($_POST["newname"])
	{
		$query = "UPDATE `user` SET `login`= '$newname' WHERE login = '$name'";
		mysqli_query($db, $query);
	}
	mysqli_close($db);
	header("Location: ./admin_succes.php");
}
?> 