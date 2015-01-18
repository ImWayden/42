<?php
require_once("doc/Doc.class.php");

class Player
{
	private $_id = 0;
	private $_name = "";
	private $_race = "";
	private $_id_game;
	private $_ships;
	use Doc;
	
	public function __construct($_SESSION, $gid)
	{
		$this->_name = $name;
		$this->_pwdCrypt = hash("whirlpool", $pwdCrypt);
		$this->_race = $race;
		$this->_ships = new Ship($name . " ship");
	}
	public function getName() {
		return $this->_name;
	}
	public function setName($name) {
		$this->_name = $name;
		return $this;
	}
	public function getRace() {
		return $this->_race;
	}
	public function setRace($race) {
		$this->_race = $race;
		return $this;
	}
	public function getIdPlayer() {
		return $this->_id_player;
	}
	public function getIdGame() {
		return $this->_id_game;
	}
	public function setIdGame($id_game) {
		$this->_id_game = $id_game;
		return $this;
	}
	public function getPwdcrypt() {
		return $this->_pwdCrypt;
	}
	public function setPwdcrypt($pwdCrypt) {
		$this->_pwdCrypt = $pwdCrypt;
		return $this;
	}
	public function getShips() {
		return $this->_ships;
	}
	public function setShips($_ships) {
		$this->_ships = $_ships;
		return $this;
	}	
}
?>