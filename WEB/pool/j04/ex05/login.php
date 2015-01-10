<?php
include ("auth.php");

function init_chat()
{
	echo '<iframe name="chat" src="chat.php" width="100%" height="550px"></iframe>'."\n";
	echo '<iframe name="speak" src="speak.php" width="100%" height="50px"></iframe>'."\n";
}

session_start();

if (isset($_SESSION['loggued_on_user']) and $_SESSION['loggued_on_user'] != "")
	init_chat();
elseif (auth($_POST['login'], $_POST['passwd']) === TRUE)
{
	$_SESSION['loggued_on_user'] = $_POST['login'];
	init_chat();
}
else
{
	$_SESSION['loggued_on_user'] = "";
	echo "ERROR\n";
}
?>