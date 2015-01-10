<?php
function auth($login, $passwd)
{
	$tab = unserialize(file_get_contents('../private/passwd'));
	foreach ($tab as $str)
	{
		foreach ($str as $log => $pass)
		{
			if ($log == $login && $pass == hash('whirlpool', $passwd))
				return TRUE;
		}
	}
	return FALSE;
}
?>