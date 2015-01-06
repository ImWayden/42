#!/usr/bin/php
<?PHP
function op($value, $op)
{
	$result = preg_split("([$op]+)", trim($value));
	if (is_numeric($result[0]) && is_numeric($result[1]))
	{
		if (!strcmp($op, "+"))
			$res = trim($result[0]) + trim($result[1]);
		if (!strcmp($op, "-"))
			$res = trim($result[0]) - trim($result[1]);
		if (!strcmp($op, "*"))
			$res = trim($result[0]) * trim($result[1]);
		if (!strcmp($op, "/"))
			$res = trim($result[0]) / trim($result[1]);
		echo $res."\n";
	}
	else
		echo "Syntax Error\n";
}

if ($argc == 2)
{
	if (strstr(trim($argv[1]), '+'))
		op($argv[1], "+");
	else if (strstr(trim($argv[1]), "-"))
		op($argv[1], "-");
	else if (strstr(trim($argv[1]), "/"))
		op($argv[1], "/");
	else if (strstr(trim($argv[1]), '*'))
		op($argv[1], "*");
	else
	{
		echo "Syntax Error\n";
		return ;
	}
}
else
	echo "Incorrect Parameters\n"
?>