#!/usr/bin/php
<?PHP

if ($argc >= 2)
{
	$array = preg_split("([ ]+)", trim($argv[1]));
	foreach ($array as $key => $elmt)
	{
		if (!$key)
			$tmp = $elmt;
		else
			echo $elmt." ";
	}
	echo $tmp."\n";
}
?>