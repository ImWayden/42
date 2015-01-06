#!/usr/bin/php
<?PHP
foreach ($argv as $key => $elmt)
{
	if ($key == 1)
		$array = preg_split("([ ]+)", trim($elmt));
	else if ($key)
		$array = array_merge($array, preg_split("([ ]+)", trim($elmt)));
	
}
if ($array)
{
	sort($array, SORT_FLAG_CASE);
	foreach ($array as $key => $elmt)
		if (ereg("^[a-zA-Z]", $elmt[0]))
			echo $elmt."\n";
	foreach ($array as $key => $elmt)
		if (ereg("^[0-9]", $elmt[0]))
			echo $elmt."\n";
	foreach ($array as $key => $elmt)
		if (!ereg("^[0-9]", $elmt[0]) && !ereg("^[a-zA-Z]", $elmt[0]))
			echo $elmt."\n";
}
?>