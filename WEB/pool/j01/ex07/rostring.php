#!/usr/bin/php
<?php

if (!$argv[1])
	return (false);
else
{
	$i = 0;
	$tab = explode(" ", $argv[1]);
	$kept = $tab[0];
	unset($tab[0]);
	foreach ($tab as $case => $value)
        print (trim($value)." ");
    echo "$kept\n";
}

?>