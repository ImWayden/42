<?php

require_once '../doc/Doc.class.php';

class Database
{
	private $_db = "asb";
	private	$_login = "root";
	private	$_password = "passer10"    ;
	public static $verbose = FALSE;
	
	use Doc;
	
	private function connect_mysql()
	{
		$connect = mysqli_connect("localhost:3306", $_login, $_password);
		return ($connect);
	}
	

	private function close_db($connect)
	{
		mysqli_close($connect);
	}

	public function getIdfromdb($SESSION)
	{
		$db = $this->connect_mysql();
		$query = "SELECT `id` FROM `asb`.`user` WHERE `login`==".$SESSION['login']." `passwd` ==".$SESSION['passwd'];
		$result = mysqli_query($db, $query);
		$req = mysqli_fetch_assoc($result);
	}

	public function getfromdb($query)
	{
		$content = array();
		if ($db = $this->connect_mysql())
		{
			if ($res = mysqli_query($db, $query))
			{
				while ($req = mysqli_fetch_assoc($res))
					$content[] = $req;
			}
		}
		$this->close_db($db);
		return ($content);
	}

	public function todb($query)
	{
		$db = $this->connect_mysql();
		echo $query."\n";
		mysqli_query($db, $query);
	}
}
?>