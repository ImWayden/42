#!/usr/bin/php
<?PHP
while (42)
{
	echo "Entrez un nombre: ";
	if (($line = fgets(STDIN)) == NULL || !strcmp("^D", $line))
	{
		echo "^D\n";
		return ;
	}
	$line = trim($line);
	if (is_numeric($line) == "TRUE")
	{
		echo "Le chiffre '$line' est : ";
		if (($line % 2) == 0)
			echo "pair\n";
		else
			echo "impair\n";
	}
	else
		echo "'$line' n'est pas un chiffre\n";
}

?>