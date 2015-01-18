<?php

require_once 'Database.class.php';


class Gen
{
	static $id = 0;

	function __construct($SESSION)
	{
		if (!empty($SESSION['login']) && !empty($SESSION['passwd']))
		{
			echo "tablea";
			$db = new Database;
			$login = $SESSION['login'];
			$passwd = hash("whirlpool", $SESSION['passwd']);
			$query = "SELECT `id`, `level` FROM `asb`.`user` WHERE `login`==".$SESSION['login']." `passwd` ==".$SESSION['passwd'];
			echo $query."\n";
			$id2 = $db->getIdfromdb($SESSION);
			echo $id2[0]."\n";
			$sql = "INSERT INTO `asb`.`game` (`game_id`, `player1_id`, `faction1_id`) VALUES ('".$id2."', '".$id2[0]', $id2[1])";
			$id++;
			$db->todb($sql);
		}
	}
}
$g = new Gen(array( "login" => "msarr", "passwd" => "passer10"));

?>