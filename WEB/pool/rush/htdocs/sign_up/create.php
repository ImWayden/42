<?php
include("../mysqli/sqli_connect.php");

function check_serial($db)
{
	$row = mysqli_query($db, "SELECT login FROM `user`");
	while ($array = mysqli_fetch_array($row, MYSQLI_NUM))
	{
		if ($array[0] == $_POST['login'])
				return (FALSE);
	}
	return (TRUE);
}

$db = sql_connect();

if ($_POST['login'] === "" || $_POST['passwd'] === "")
{
	mysqli_close($db);
	header("Location: ./sign_up_empty.php");
}
else
{
	if (check_serial($db) != FALSE)
	{
		$login = $_POST['login'];
		$passwd = hash("whirlpool", $_POST['passwd']);
		$sql = "INSERT INTO `asb`.`user` (`login`, `passwd`, `admin`, `score`, `level`) VALUES ('$login', '$passwd', '0', 0, 0)";
		mysqli_query($db, $sql);
		mysqli_close($db);
		header("Location: ../sign_in/sign_in.php?sign_up=done");
	}
	else
	{
		mysqli_close($db);
		header("Location: ./sign_up_fail.php");
	}
}
?>
