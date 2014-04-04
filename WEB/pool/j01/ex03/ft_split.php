<?php
#!/usr/bin/php
function ft_split($str)
{
	$tab = explode(" ", $str);
	foreach ($tab as $case => $val)
	{
		if (!$tab[$case])
			unset ($tab[$case]);
	}
	sort($tab);
	return ($tab);
}

?>