<?php
function login_valid($accounts)
{
	foreach ($accounts as $tab)
	{
		if (($tab['login'] == $_POST['login']) and ($tab['passwd'] == hash("whirlpool", $_POST['oldpw'])))
			return (1);
	}
	echo "ERROR\n";
	return (0);
}

$private = "../private/passwd";

if (($_POST['login'] == "" or $_POST['oldpw'] == "" or $_POST['newpw'] == "") or (isset($_POST['login']) and $_POST['submit'] != "OK"))
	echo "ERROR\n";
else
{
	$passwd = file_get_contents($private);
	$accounts = unserialize($passwd);

	if (!login_valid($accounts))
		return (1);
	foreach ($accounts as &$tab)
	{
		if ($tab['login'] == $_POST['login'])
			$tab['passwd'] = hash("whirlpool", $_POST['newpw']);
	}
	file_put_contents($private, serialize($accounts));
	echo "OK\n";
	header("Location: index.html");
}
?>