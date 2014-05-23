#!/usr/bin/php
<?PHP

while (42)
{
	echo "Entrez un nombre: ";
	if (!($line = trim(fgets(STDIN))) || !strcmp("^D", $line))
	{
		echo "\n";
		return ;
	}
	if (is_numeric($line) == "TRUE")
	{
		echo "Le nombre '$line' est : ";
		if (($line % 2) == 0)
			echo "pair\n";
		else
			echo "impair\n";
	}
	else if ($line != "")
		echo "'$line' n'est pas un chiffre\n";
}

?>