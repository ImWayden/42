<?php
function auth($login, $passwd)
{
	$private = $_SERVER['DOCUMENT_ROOT']."/private/passwd";
	$content = file_get_contents($private);
	$accounts = unserialize($content);
	foreach ($accounts as $tab)
	{
		if (($tab['login'] == $login) && ($tab['passwd'] == hash("whirlpool", $passwd)))
			return TRUE;
	}
	return FALSE;
}
?>