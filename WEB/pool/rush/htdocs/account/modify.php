<?php
include("../mysqli/sqli_connect.php");

function check_serial($db)
{
	$row = mysqli_query($db, "SELECT * FROM `user`");

	while ($array = mysqli_fetch_array($row, MYSQLI_NUM))
	{
		if ($array[0] == $_SESSION['login'])
		{
			$pwd = hash("whirlpool", $_POST['old_passwd']);
			$npwd = hash("whirlpool", $_POST['new_passwd']);
			$login = $_SESSION['login'];
			if ($array[1] == $pwd)
			{
				$query = "UPDATE `user` SET `passwd`= '$npwd' WHERE `login` = '$login'";
				mysqli_query($db, $query);
				return (TRUE);
			}
		}
	}
	return (FALSE);
}

session_start();
$db = sql_connect();

if ($_POST['old_passwd'] === "" || $_POST['new_passwd'] === "")
{
	mysqli_close($db);
	header("Location: ./modify_empty.php");
	exit;
}
if (check_serial($db) == FALSE)
{
	mysqli_close($db);
	header("Location: ./modify_fail.php");
	exit;
}
else
{
	mysqli_close($db);
	header("Location: ../index.php");
	exit;
}
?>