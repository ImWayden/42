<?php
include("mysqli.php");

function sql_connect()
{
	$db = mysqli_connect('localhost:3306', "root", "passer10", 'asb');
	if (!isset($db))
	{
		print("Error connecting to database\n");
		$_SESSION['dblogin'] = NULL;
		$_SESSION['dbpasswd'] = NULL;
		return (FALSE);
	}
	return ($db);
}
?>