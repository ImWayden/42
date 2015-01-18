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
			if ($array[1] == $pwd && $array[2] == "1")
			{
				$_SESSION['login'] = $_POST['login'];
				$_SESSION["admin"] = "1";
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
	header("Location: ./admin_sign_in_empty.php");
	exit;
}
if (check_serial($db) == FALSE)
{
	mysqli_close($db);
	header("Location: ./admin_sign_in_fail.php");
	exit;
}
else
{
	mysqli_close($db);
	header("Location: ../index.php");
	exit;
}
?>