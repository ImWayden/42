<?php
include("../mysqli/sqli_connect.php");

function check_serial($db)
{
	$row = mysqli_query($db, "SELECT * FROM `user`");
	while ($array = mysqli_fetch_array($row, MYSQLI_NUM))
	{
		if ($array[0] == $_POST['login'])
		{
			$pwd = hash("whirlpool", $_POST['passwd']);
			if ($array[1] == $pwd)
			{
				$_SESSION['login'] = $_POST['login'];
				$_SESSION["admin"] = $array[2];
				return (TRUE);
			}
		}
	}
	return (FALSE);
}

session_start();
$db = sql_connect();

if ($_POST['login'] === "" || $_POST['passwd'] === "")
{
	mysqli_close($db);
	header("Location: ./sign_in_empty.php");
}
if (check_serial($db) == FALSE)
{
	mysqli_close($db);
	header("Location: ./sign_in_fail.php");
}
else
{
	mysqli_close($db);
	header("Location: ../index.php");
}
?>