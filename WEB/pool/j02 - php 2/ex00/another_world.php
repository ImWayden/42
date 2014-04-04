#!/usr/bin/php
<?php
if ($argc >= 2)
{
	print(preg_replace("/[ \t]+/", ' ', $argv[1]));
	print("\n");
}
?>