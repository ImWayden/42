<?php

require_once('Color.class.php');

Class Vertex
{
	private $_x;
	private $_y;
	private $_z;
	private $_w;
	private $_color;
	public static $verbose = False;

	public function __construct(array $vert)
	{
		if (isset($vert['x']) && isset($vert['y']) && isset($vert['z']))
		{
			$this->_x = $vert['x'];
			$this->_y = $vert['y'];
			$this->_z = $vert['z'];
			if (isset($vert['w']))
				$this->_w = $kwargs['w'];
			else
				$this->_w = 1.0;
			if (isset($vert['color']))
				$this->_color = clone $vert['color'];
			else
				$this->_color = new Color(array('rgb' => 0xffffff));
			if (self::$verbose)
				echo $this->__toString()." constructed.\n";
		}
	}

	public function __destruct()
	{
		if (self::$verbose)
			echo $this->__toString()." destructed.\n";
	}

	public function __toString()
	{
		if (self::$verbose)
			return sprintf("Vertex( x: %3.2f, y: %3.2f, z:%3.2f, w:%3.2f, %s )", $this->_x, $this->_y, $this->_z, $this->_w, $this->_color);
		else
			return sprintf("Vertex( x: %3.2f, y: %3.2f, z:%3.2f, w:%3.2f )", $this->_x, $this->_y, $this->_z, $this->_w);
	}

	public static function doc()
	{
		if (file_exists("Vertex.doc.txt"))
			return file_get_contents("Vertex.doc.txt");
	}

	public function getX() { return $this->_x; }
	public function getY() { return $this->_y; }
	public function getZ() { return $this->_z; }
	public function getW() { return $this->_w; }
	public function getColor() { return $this->_color; }
	public function setX($x) { $this->_x = $x; }
	public function setY($y) { $this->_y = $y; }
	public function setZ($z) { $this->_z = $z; }
	public function setW($w) { $this->_w = $w; }
	public function setColor(Color $color) { $this->_color = $color; }
}
