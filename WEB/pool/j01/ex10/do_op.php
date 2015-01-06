#!/usr/bin/php
<?PHP

if ($argc == 4)
{
	if (!strcmp(trim($argv[2]), "+"))
		$result = trim($argv[1]) + trim($argv[3]);
	if (!strcmp(trim($argv[2]), "-"))
		$result = trim($argv[1]) - trim($argv[3]);
	if (!strcmp(trim($argv[2]), "/"))
		$result = trim($argv[1]) / trim($argv[3]);
	if (!strcmp(trim($argv[2]), "*"))
		$result = trim($argv[1]) * trim($argv[3]);
	echo $result."\n";
}
else
	echo "Incorrect Parameters\n"
?>