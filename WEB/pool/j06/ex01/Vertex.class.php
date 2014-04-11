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

	public function getX()	    { return number_format($this->_x, 2); 	}
  public function getY()      { return number_format($this->_y, 2);  }
  public function getZ()      { return number_format($this->_z, 2);  }
  public function getW()      { return number_format($this->_w, 2);  }
  public function getColor()  { return $this->_color->getColor();  }

	public function setX($value)             { $this->_x = number_format($value, 2); }
  public function setY($value)             { $this->_y = number_format($value, 2); }
  public function setZ($value)             { $this->_z = number_format($value, 2); }
  public function setW($value)             { $this->_w = number_format($value, 2); }
  public function setColor(Color $value)   { $this->_color = $value; }
}