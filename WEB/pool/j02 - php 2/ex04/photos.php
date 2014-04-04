#!/usr/bin/php
<?php
if ($argc > 1)
{
	$page = file_get_contents($argv[1]);
	preg_match_all("#<img .*src=\"?((?:[^\s]*/)*([^'\"?\s]*)).*>#i", $page, $img);
	preg_match("#[a-z]+://([^/]*)(?:.*/)?#", $argv[1], $domain);
	$dir_name = $domain[1];
	if (!file_exists($dir_name))
	   mkdir($dir_name);
	$i = count($img[1]);
	while($i-- > 0)
	{
		if (preg_match("#://#", $img[1][$i]))
			$source = fopen($img[1][$i], 'r');
		else
		{
			if (substr($domain[0], -1) !== '/')
			   $domain[0] .= '/';
			$source = fopen($domain[0].$img[1][$i], 'r');
		}
		if ($source !== FALSE)
		{
			if ($dest = fopen($dir_name.'/'.$img[2][$i], 'w+'));
			{
				stream_copy_to_stream($source, $dest);
				fclose($dest);
			}
			fclose($source);
		}
	}
}
?>