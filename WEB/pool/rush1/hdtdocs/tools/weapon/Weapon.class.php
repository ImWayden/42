<?php

require_once 'doc/Doc.class.php';

abstract class Weapon
{
	private			$_id = ;
	private			$_name = NULL;
	private			$_charges = 0;
	private			$_pc = 0;
	private			$_pi = 0;
	private			$_pl = 0;
	
	use Doc;

	function setCharges($pp){ $this->_charges += $pp;}
	function getCharges($pp){ return $this->_charges;}

	function __construct($name)
	{
		if ($name)
		{
			$db = new Database();
			$w = $db->getWeapon($name);
			$this->setId($w['id']);
			$this->setName($w['name']);
			$this->setCharges($w['scope_c']);
			$this->setPp($w['']);
			$this->setPc($w['id']);
			$this->setPi($w['id']);
			$this->setPl($w['id']);
		}
	}
	abstract function shoot();
	abstract function lineview();
}
?>