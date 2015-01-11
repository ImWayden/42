<?php
include("mysqli.php");

function sql_connect()
{
	$db = mysqli_connect('localhost', "root", "toor23", 'minishop');
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