#!/usr/bin/php
<?PHP
$test = $argv;
foreach($test as $key => $elmt)
{
	if ($key != "0")
		echo $elmt."\n";
}

?>