#!/usr/bin/php
<?PHP

$test = $argv;
$test[0] = "change";
foreach($test as $key => $elmt)
{
	//if ($key != "0")
		echo $elmt."\n";
}

?>