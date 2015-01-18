<?php
require_once 'Database.class.php';


class Gen
{
	static $id = 0;

	function __construct($SESSION)
	{
		if (!empty($SESSION['login']) && !empty($SESSION['passwd']))
		{
			$db = new Database;
			$login = $SESSION['login'];
			$passwd = hash("whirlpool", $SESSION['passwd']);
			$query = "SELECT `id`, `level` FROM `asb`.`user` WHERE `login`==".$SESSION['login']." `passwd` ==".$SESSION['passwd'];
			$id2 = $db->getfromdb($query);
			$sql = "INSERT INTO `asb`.`game` (`game_id`, `player1_id`, `faction1_id`) VALUES ('$id', '$id2[0]', $id[1])";
			$id++;
			$db->todb($sql);
		}
	}

	$g = new Gen(array( "login" => "msarr" ,"passwd" => "passer10"));
}
?>