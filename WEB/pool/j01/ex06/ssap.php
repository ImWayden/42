#!/usr/bin/php
<?php

$i = 0;
$tab = $argv;
unset($tab[0]);
foreach ($tab as $value)
     $str = $str." ".$value;
$tab = explode(" ", $str);
sort($tab);
foreach ($tab as $value)
{
    if ($value)
        echo "$value\n";
}
?>