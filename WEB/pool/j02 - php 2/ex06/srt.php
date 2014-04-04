#!/usr/bin/php
<?php
if ($argc < 2 || !file_exists($argv[1]))
   return ;
$fd = fopen($argv[1], 'r');
$table = array();
while ($i = fgets($fd))
{
	preg_match("/([0-9]{2}):([0-9]{2}):([0-9]{2}),([0-9]{3}).*/", fgets($fd), $m);
	$table[trim($i)] = array(
			   'order' => $m[4] + 1000 * ($m[3] + 60 * ($m[2] + 60 * $m[1])),
			   'time' => $m[0],
			   'message' => fgets($fd)
			   );
}
fclose($fd);

function order($a, $b)
{
	return ($a['order'] - $b['order']);
}
usort($table, order);
foreach($table as $index => $el)
{
	echo ($index + 1)."\n";
	echo $el['time']."\n";
	echo $el['message'];
	if (count($table) > $index +1)
	   echo "\n";
}
?>