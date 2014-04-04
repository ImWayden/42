#!/usr/bin/php
<?php
if ($argc >= 2 && $buf = file_get_contents($argv[1]))
{
	function cat($match)
	{
		return ('<a'.(title($match[1])).(trans(title($match[2]))).'/a>');
	}
	function toupper($res)
	{
		return (($res[1]).(strtoupper($res[2])).($res[3]));
	}
	function title($s)
	{
		$s = preg_replace_callback("/(title=\")(.*)(\")/U", toupper, $s);
		return ($s);
	}
	function trans($match)
	{
		return (preg_replace_callback("/(>)([^<]*)(<)/", toupper, $match)); 
	}
	$buf = preg_replace_callback("#<a([^>]*)(>.*<)/a>#", "cat", $buf);
	echo $buf;
}
?>