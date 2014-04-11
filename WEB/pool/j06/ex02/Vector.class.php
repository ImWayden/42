<?php

require_once 'Color.class.php';
require_once 'Vertex.class.php';

class Vector
{
	private $_x;
	private $_y;
	private $_z;
  	private $_w = 0.0;
  	private $_dest;
  	private $_orig;

	public static $verbose = FALSE;

	public function __construct(array $kwargs)
	{
		$this->setDest($kwargs['dest']);

	    if (array_key_exists('orig', $kwargs))   $this->setOrig($kwargs['orig']);
	    else $this->_orig = new Vertex(array('x' => 0, 'y' => 0, 'z' => 0, 'w' => 1));

	    $this->_x = sqrt($this->_orig->getX() * $this->_dest->getX());
	    $this->_y = sqrt($this->_orig->getY() * $this->_dest->getY());
	    $this->_z = sqrt($this->_orig->getZ() * $this->_dest->getZ());
	    $this->_w = sqrt($this->_orig->getW() * $this->_dest->getW());

		if (self::$verbose) echo $this->printVector();
	}
	public function __toString()
	{
    if (self::$verbose) return $this->printVector();
		return ($this->printVector()." )");
	}
	public function __destruct()
	{
		if (self::$verbose) echo $this->printVertex();
	}
	public function printVertex(){ return "Vertex( x: ".$this->getX().", y: ".$this->getY().", z:".$this->getZ().", w:".$this->getW(); }

	public static function doc() {echo file_get_contents('Vertex.doc.txt')."\n";}

	public function getX()	    { return floatval($this->_x);  }
	public function getY()      { return floatval($this->_y);  }
	public function getZ()      { return floatval($this->_z);  }
	public function getW()      { return floatval($this->_w);  }

	public function getOrig()	    { return $this->_orig;  }
	public function getDest()	    { return $this->_dest;  }

	public function setOrig(Vertex $new)	{ $this->_orig = $new; }
	public function setDest(Vertex $new)	{ $this->_dest = $new; }

	public function magnitude()
	{
		return (sqrt($this->_orig->getX() * $this->_dest->getX()
				   + $this->_orig->getY() * $this->_dest->getY()
				   + $this->_orig->getZ() * $this->_dest->getZ()));
	}
	public function normalize()
	{
		$origin = new Vertex(array('x' => 0, 'y' => 0, 'z' => 0, 'w' => 1));
		$destin = new Vertex(array('x' => $this->_orig->getX() / $this->magnitude(),
								   'y' => $this->_orig->getY() / $this->magnitude(),
								   'z' => $this->_orig->getZ() / $this->magnitude()));
		return (new Vector(array('orig' => $origin, 'dest' => $destin)));
	}
	public function add(Vector $rhs)
	{
		$origin = new Vertex(array('x' => $this->_orig->getX() + $rhs->_orig->getX(),
								 	'y' => $this->_orig->getY() + $rhs->_orig->getY(),
								 	'z' => $this->_orig->getZ() + $rhs->_orig->getZ()));

		$destin = new Vertex(array('x' => $this->_dest->getX() + $rhs->getX(),
								 	'y' => $this->_dest->getY() + $rhs->getY(),
								 	'z' => $this->_dest->getZ() + $rhs->getZ()));

		return (new Vector(array('orig' => $origin, 'dest' => $destin)));
	}
	public function sub(Vector $rhs)
	{
		$origin = new Vertex(array('x' => $this->_orig->getX() - $rhs->_orig->getX(),
								 	'y' => $this->_orig->getY() - $rhs->_orig->getY(),
								 	'z' => $this->_orig->getZ() - $rhs->_orig->getZ()));

		$destin = new Vertex(array('x' => $this->_dest->getX() - $rhs->getX(),
								 	'y' => $this->_dest->getY() - $rhs->getY(),
								 	'z' => $this->_dest->getZ() - $rhs->getZ()));

		return (new Vector(array('orig' => $origin, 'dest' => $destin)));
	}
	public function opposite()
	{
		return (new Vector(array('orig' => $this->getDest(),
								  'dest' => $this->getOrig())));
	}
	public function dotProduct (Vector $rhs){
		$ret = ($this->_x * $rhs->_x) + ($this->_y * $rhs->_y) + ($this->_z * $rhs->_z);
		return $ret;
	}
	public function scalarProduct ($k){

	}
	public function cos(Vector $rhs){
		return ($this->_x * $rhs->_x + $this->_y + $rhs->_y) /
		sqrt((pow($this->_x, 2) + pow($this->_y, 2) + pow($this->_z, 2)) * 
		(pow($rhs->x, 2) + pow($rhs->y, 2) + pow($rhs->z, 2) ));
	}
	public function crossProduct(Vector $rhs){

	}
	public function printVector()
	{
		return ("printVector\n");
	}
/*	public function setX($value)             { $this->_x = floatval($value, 2); }
  public function setY($value)             { $this->_y = floatval($value, 2); }
  public function setZ($value)             { $this->_z = floatval($value, 2); }
  public function setW($value)             { $this->_w = floatval($value, 2); }
  public function setColor(Color $value)   { $this->_color = $value; } */
}