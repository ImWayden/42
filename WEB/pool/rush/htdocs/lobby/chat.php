<?php
session_start();

date_default_timezone_set("UTC");

$private = "../private/chat";

if (isset($_SESSION['logged_on_user']) == FALSE)
	header('Location: ../sign_in/sign_in.php');
else
{
	$fd = fopen($private, "r");
	flock($fd);
	$read = file_get_contents($private);
	$chat = unserialize($read);
	foreach ($chat as $tab)
	{
		echo "[".date("H:i", $tab['time'])."] <b>".$tab['login']."</b>: ".$tab['msg']."<br />\n";
	}
	fclose($fd);
}
?>