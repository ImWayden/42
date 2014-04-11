<?php

require_once 'Color.class.php';

class Vertex
{
	private $_x;
	private $_y;
	private $_z;
  private $_w = 1.0;
  private $_color;

	public static $verbose = FALSE;

	public function __construct(array $kwargs)
	{
		$this->setX($kwargs['x']);
    $this->setY($kwargs['y']);
    $this->setZ($kwargs['z']);

    
    if (array_key_exists('w', $kwargs))   $this->setW($kwargs['w']);
		if (array_key_exists('color', $kwargs)) $this->_color = $kwargs['color'];
    else $this->_color = new Color(array('rgb' => 0xffffff));

		if (self::$verbose) echo $this->printVertex().", ".$this->_color->printColor()." )"." constructed\n";
	}
	public function __toString()
	{
    if (self::$verbose) return $this->printVertex().", ".$this->_color->printColor()." )";
		return ($this->printVertex()." )");
	}
	public function __destruct()
	{
		if (self::$verbose) echo $this->printVertex().", ".$this->_color->printColor()." )"."destructed\n";
	}
	public function printVertex(){ return "Vertex( x: ".$this->getX().", y: ".$this->getY().", z:".$this->getZ().", w:".$this->getW(); }

	public static function doc() {echo file_get_contents('Vertex.doc.txt')."\n";}

	public function getX()	  { return floatval($this->_x); 	}
  public function getY()      { return floatval($this->_y);  }
  public function getZ()      { return floatval($this->_z);  }
  public function getW()      { return floatval($this->_w);  }
  public function getColor()  { return $this->_color->getColor();  }

	public function setX($value)           { $this->_x = floatval($value); }
  public function setY($value)             { $this->_y = floatval($value); }
  public function setZ($value)             { $this->_z = floatval($value); }
  public function setW($value)             { $this->_w = floatval($value); }
  public function setColor(Color $value)   { $this->_color = $value; }
}