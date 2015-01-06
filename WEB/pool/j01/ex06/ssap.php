#!/usr/bin/php
<?PHP
print_r($argv);
foreach ($argv as $key => $elmt)
{
	if ($key == 1)
		$array = preg_split("/[ ]+/", trim($elmt));
	else if ($key > 1)
		$array = array_merge($array, preg_split("/[ ]+/", trim($elmt)));
}
if ($array)
{
	sort($array);
	foreach ($array as $key => $elmt)
		echo $elmt."\n";
}
?>