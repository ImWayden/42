<?php
session_start();

if (isset($_SESSION['login']) == FALSE)
{
	echo "Sign_in to see the chat !\n";
	return (1);
}
?>
<html>
	<head>
		<script langage="javascript">top.frames['chat'].location = 'chat.php';</script>
	</head>
	<body>
		<form method="post">
			<input type="text" name="msg" style="width: 100%; height: 60%;" />
			<input type="submit" name="submit" style="float: right;" value="Envoyer" />
		</form>
	</body>
</html>
<?php
date_default_timezone_set("UTC");

$private = "../private/chat";

if (isset($_POST['msg']))
{
	$fd = fopen($private, "c+");
	flock($fd);
	$read = file_get_contents($private);
	if ($read === FALSE)
		$chat = array ();
	else
		$chat = unserialize($read);
	$chat[] = array("login" => $_SESSION['logged_on_user'], "time" => date("U"), "msg" => $_POST['msg']);
	$ser = serialize($chat);
	file_put_contents($private, $ser);
	fclose($fd);
}
?>