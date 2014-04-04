#!/usr/bin/php
<?php
if ($argc >= 2)
{
	$day = "(?:[Ll]undi)|(?:[Mm]ardi)|(?:[Mm]ercredi)|(?:[Jj]eudi)|(?:[Vv]endredi)|(?:[Ss]amedi)|(?:[Dd]imanche)";
	$num_day = "[0-9]{1,2}";
	$month = "(?:[Jj]anvier)|(?:[Ff]evrier)|(?:[Mm]ars)|(?:[Aa]vril)|(?:[Mm]ai)|(?:[Jj]uin)|(?:[Jj]uillet)|(?:[Aa]out)|(?:[Ss]eptembre)|(?:[Oo]ctobre)|(?:[Nn]ovembre)|(?:[Dd]ecembre)";
	$annee = "[0-9]{4}";
	$hms = "[0-9]{2}:[0-9]{2}:[0-9]{2}";
	$match = array();
	if (preg_match("/($day) ($num_day) ($month) ($annee) ($hms)/", $argv[1], $match))
	{
	   $month_convert = array('', 'Janvier', 'Fevrier', 'Mars', 'Avril', 'Mai', 'Juin', 'Juillet', 'Aout', 'Septembre', 'Octobre', 'Novembre', 'Decembre');
	   date_default_timezone_set("Europe/Madrid");
	   print(strtotime("$match[4]-".(array_search(ucfirst($match[3]), $month_convert))."-$match[2] $match[5]")."\n");
	}
	else
		echo "Wrong Format\n";
}
?>