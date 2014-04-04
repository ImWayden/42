#!/usr/bin/php
<?php

while (42)
{
	echo "Entrez un nombre: ";
	if(!($nombre = fgets(STDIN)))
		exit ("^D\n");
	$trimmed = trim($nombre);
	if (is_numeric($trimmed))
	{
		if (($trimmed % 2) == 0)
			echo "Le chiffre ".$trimmed." est Pair\n";
		else
			echo "Le chiffre ".$trimmed." est Impair\n";
	}
	else
		echo "'".$trimmed."' n'est pas un chiffre\n";
}

?>