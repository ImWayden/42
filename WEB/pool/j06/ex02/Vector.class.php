<?php

require_once('Vertex.class.php');

Class Vector
{
	private $_x;
	private $_y;
	private $_z;
	private $_w;
	public static $verbose = false;

	public function __construct(array $vect)
	{
		if (isset($vect['x']) && isset($vect['y']) && isset($vect['z']))
		{
			$this->_x = $vect['x'];
			$this->_y = $vect['y'];
			$this->_z = $vect['z'];
		}
		else
		{
			$dest = $vect['dest'];
			if (isset($vect['orig']))
				$orig = $vect['orig'];
			else
				$orig = new Vertex(array('x' => 0, 'y' => 0, 'z' => 0, 'w' => 1));
			$this->_x = $dest->getX() - $orig->getX();
			$this->_y = $dest->getY() - $orig->getY();
			$this->_z = $dest->getZ() - $orig->getZ();
		}
		$this->_w = 1.0;
		if (self::$verbose)
			echo $this->__toString()." constructed.\n";
	}

	public function __destruct()
	{
		if (self::$verbose)
			echo $this->__toString()." destructed.\n";
	}

	public function __toString()
	{
		return sprintf("Vector( x:%3.2f, y:%3.2f, z:%3.2f, w:%3.2f )", $this->_x, $this->_y, $this->_z, $this->_w);
	}

	public static function doc()
	{
		if (file_exists("Vector.doc.txt"))
			return file_get_contents("Vector.doc.txt");
		
	}

	public function add(Vector $rhs)
	{
		return new Vector(array('x' => $this->_x + $rhs->getX(),  'y' => $this->_y + $rhs->getY(),  'z' => $this->_z + $rhs->getZ()));
	}

	public function sub(Vector $rhs)
	{
		return new Vector(array('x' => $this->_x - $rhs->getX(), 'y' => $this->_y - $rhs->getY(), 'z' => $this->_z - $rhs->getZ()));
	}

	public function opposite()
	{
		return new Vector(array('x' => -$this->_x, 'y' => -$this->_y, 'z' => -$this->_z));
	}

	public function scalarProduct($k)
	{
		return new Vector(array('x' => $this->_x * $k,  'y' => $this->_y * $k,  'z' => $this->_z * $k));
	}
	public function dotProduct(Vector $rhs)
	{
		return ($this->_x * $rhs->getX() + $this->_y * $rhs->getY() + $this->_z * $rhs->getZ());
	}

	public function crossProduct(Vector $rhs)
	{
		return new Vector(array('x' => ($this->_y * $rhs->getZ() - $this->_z * $rhs->getY()),
								'y' => ($this->_z * $rhs->getX() - $this->_x * $rhs->getZ()),
								'z' => ($this->_x * $rhs->getY() - $this->_y * $rhs->getX())));
	}

	public function magnitude()
	{
		return (sqrt($this->_length()));
	}

	private function _length()
	{
		return ($this->_x * $this->_x + $this->_y * $this->_y + $this->_z * $this->_z);
	}
	
	public function cos(Vector $rhs)
	{
		return (($this->_x * $rhs->getX() + $this->_y * $rhs->getY() + $this->_z * $rhs->getZ()) / sqrt($this->_length() * $rhs->_length()));
	}

	public function normalize()
	{
		$l = $this->magnitude();
		if ($l)
			return $this->scalarProduct(1/$l);
		else
			return clone ($this);
	}
	

	public function getX() { return $this->_x; }
	public function getY() { return $this->_y; }
	public function getZ() { return $this->_z; }
	public function getW() { return $this->_w; }
}
