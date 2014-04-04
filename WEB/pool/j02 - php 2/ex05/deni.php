#!/usr/bin/php
<?php

if ($argc != 3 || !file_exists($argv[1]))
   return ;
$f = file($argv[1]);
$ct = explode(';', substr($f[0], 0 , -1));
$categories = array();
$i = 0;
foreach($ct as $c)
{
	if ($c === $argv[2])
	   $index = $i;
	$categories[$i++] = $c;
	$$c = array();
}
if (!$index)
   return ;
unset($f[0]);
foreach($f as $line)
{
	$param = explode(';', substr($line, 0, -1));
	$key = $param[$index];
	foreach($param as $i => $p)
		${$categories[$i]}[$key] = $param[$i];
}
while (1)
{
	echo "Entrez votre commande: ";
	if ($line = fgets(STDIN))
	   eval($line);
	else
		break;
}
echo "\n";
?>