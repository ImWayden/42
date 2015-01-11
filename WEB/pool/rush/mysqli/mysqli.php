<?php
function access_sql()
{
?>
<html>
	<head>
		<title>
			Login SQL
		</title>
	</head>
	<body>
		<form method="POST" name="login" action="connect_mysqli.php">
		Login: <input type="text" name="login"><br />
		Password: <input type="password" name="passwd"><br />
		<input type="submit" name="submit" value="OK"><br />
		</form>
	</body>
</html>
<?php
};
?>