<?php

require_once '../doc/Doc.class.php';

class Database
{
	private $_db = NULL;
	private	$_login;
	private	$_password;
	private	$_database;
	public static $verbose = FALSE;
	use Doc;
	
	static public function __construct()
	{
		if (!empty($_SESSION['log']) && !empty($_SESSION['pwd'])  && !empty($_SESSION['db']))
		{
			
		}
	}
	
	static public function connect_mysql()
	{
		if ($mysql_connect = mysqli_connect('phpmyadmin.local.42.fr', $this->_login, $this->_password))
		{
			return ($mysql_connect);
		}
	}
	
	static public function	connect_db()
	{
		$mysqlConnect = $this->connect_mysql();
		if (mysqli_select_db($mysqlConnect, $this->_database))
		{
			$this->_db = $mysqlConnect;
			return ($mysqlConnect);
		}
		else
		{
			echo "Error: bad login/password<br><a href='install.php'>Page de connexion</a>";
			return (NULL);
		}
	}
	public function close_db()
	{
		mysqli_close($this->_db);
	}

}
?>