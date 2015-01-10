<?php
if (isset($_POST['submit']) && $_POST['submit'] == "OK" && isset($_POST['newpw']) && $_POST['newpw'] != "")
{
	$count = 0;
	$tab = unserialize(file_get_contents('../private/passwd'));
	foreach ($tab as $str)
	{
		foreach ($str as $log => $pass)
		{
			if ($log == $_POST['login'] && $pass == hash('whirlpool', $_POST['oldpw']))
			{
				$tab1[] = array($_POST['login'] => hash('whirlpool', $_POST['newpw']));
				$count++;
			}
			else
				$tab1[] = array($log => $pass);
		}
	}
	file_put_contents('../private/passwd', serialize($tab1));
	if ($count == 1)
		echo "OK\n";
	else
		echo "ERROR\n";
}
else
	echo "ERROR\n";
?>