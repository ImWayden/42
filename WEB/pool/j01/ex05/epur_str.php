#!/usr/bin/php
<?php

$i = 0;
$tab = explode(" ", $argv[1]);
foreach ($tab as $value)
{
	if ($value)
    {
        if ($i == count($tab) - 1)
		  echo "$value";
        else
            echo "$value ";
    }
	$i++;
}
echo "\n";

?>