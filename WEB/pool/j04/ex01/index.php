<?php
	session_start();
	if (isset($_GET["login"]))
		$_SESSION["login"] = $_GET["login"];
	if (isset($_GET["passwd"]))
		$_SESSION["passwd"] = $_GET["passwd"];
	if (isset($_SESSION["login"]))
		$login = $_SESSION["login"];
	else
		$login = "";
	if (isset($_SESSION["passwd"]))
		$passwd = $_SESSION["passwd"];
	else
		$passwd = "";
?>
<html>
	<body>
		<form method="index.php" ation="get">
			<p>
				<label> Login: </label><input type="text" name="login" value="<?=$login?>"/>
				<label> Password: </label><input type="text" name="passwd" value="<?=$passwd?>"/>
				<input type="submit" value="OK" />
			</p>
	</body>
</html>
