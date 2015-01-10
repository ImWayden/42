<?php
function account_exists($accounts)
{
	foreach ($accounts as $tab)
	{
		if ($tab['login'] == $_POST['login'])
		{
			echo "ERROR\n";
			return 1;
		}
	}
	return (0);
}

$pvfile = "../private/passwd";

if ($_POST['passwd'] == "" || $_POST['login'] == "")
	echo "ERROR\n";
elseif ($_POST['submit'] != "OK")
	echo "ERROR\n";
else
{
	if (file_exists("../private") === FALSE)
	mkdir("../private");
	$read = file_get_contents($pvfile);
	if ($read === FALSE)
		$accounts = array ();
	else
		$accounts = unserialize($read);
	if (!account_exists($accounts))
	{
		$accounts[] = array("login" => $_POST['login'], "passwd" => hash("whirlpool", $_POST['passwd']));
		$ser = serialize($accounts);
		file_put_contents($pvfile, $ser);
		echo "OK\n";
		header("Location: index.html");
	}
}
?>