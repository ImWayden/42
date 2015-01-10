<?php
session_start();

date_default_timezone_set("UTC");

$private = "../private/chat";

if (isset($_SESSION['loggued_on_user']) === FALSE)
	header('Location: index.html');
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