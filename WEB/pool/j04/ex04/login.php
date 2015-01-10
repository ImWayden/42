<?php
	include "auth.php";
	if (isset($_GET['login']) && isset($_GET['passwd']))
	{
		session_start();
		if (auth($_GET['login'], $_GET['passwd']) == TRUE)
		{
			$_SESSION['loggued_on_user'] = $_GET['login'];
			echo "OK\n";
		}
		else
		{
			$_SESSION['loggued_on_user'] = "";
			echo "ERROR\n";
		}
	}
?>