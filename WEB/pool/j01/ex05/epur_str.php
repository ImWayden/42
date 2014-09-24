#!/usr/bin/php
<?PHP

if ($argc == 2)
{
	$array = preg_split("([ ]+)", trim($argv[1]));
	$key = 0;
	while ($array[$key] != NULL)
	{
		echo $array[$key];
		$key++;
		if ($array[$key])
			echo " ";
	}
}
?>

