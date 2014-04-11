<?php

class Color
{
	private $_red   = 0;
	private $_green = 0;
	private $_blue	 = 0;

	public static $verbose = TRUE;

	public function __construct(array $kwargs)
	{
		if (array_key_exists('red', $kwargs))	$this->setRed($kwargs['red']);
		if (array_key_exists('green', $kwargs))	$this->setGreen($kwargs['green']);
		if (array_key_exists('blue', $kwargs))	$this->setBlue($kwargs['blue']);

		if (array_key_exists('rgb', $kwargs))
		{
			$red   = ($kwargs['rgb'] >> 16) & 0xff;
			$green = ($kwargs['rgb'] >> 8)  & 0xff;
			$blue  = ($kwargs['rgb'] >> 0)  & 0xff;

			$this->setRed($red);
			$this->setGreen($green);
			$this->setBlue($blue);
		}
		if (self::$verbose) echo $this->printColor()." constructed. \n";

	}
	public function __toString()
	{
		return ($this->printColor());
	}
	public function __destruct()
	{
		if (self::$verbose) echo $this->printColor()." destructed. \n";
	}
	public function printColor(){ return "Color( red: ".$this->getRed().", green: ".$this->getGreen().", blue: ".$this->getBlue()." )"; }

	public static function doc() {echo file_get_contents('Color.doc.txt')."\n";}

	public function getRed()     { return $this->_red; 	}
	public function getGreen()   { return $this->_green; }
	public function getBlue()    { return $this->_blue; 	}

  	public function setRed($value)
  	{ 
  		if ($value > 255) 	$value = 255;
  		if ($value < 0)		$value = 0;

  		$this->_red = round($value); 
  	}
  	public function setGreen($value)
  	{ 
  		if ($value > 255) 	$value = 255;
  		if ($value < 0)		$value = 0;

  		$this->_green = round($value); 
  	}
  	public function setBlue($value)
  	{ 
  		if ($value > 255) 	$value = 255;
  		if ($value < 0)		$value = 0;

  		$this->_blue = round($value); 
  	}
  	public function add(Color $color)
  	{
  		return new Color(array( 'red' => $this->getRed() + $color->getRed(),
  								            'green' => $this->getGreen() + $color->getGreen(),
  								            'blue' => $this->getBlue() + $color->getBlue()));
  	}
  	public function sub(Color $color)
  	{
  		return new Color(array( 'red' => $this->getRed() - $color->getRed(),
  								            'green' => $this->getGreen() - $color->getGreen(),
  								            'blue' => $this->getBlue() - $color->getBlue()));
  	}
  	public function mult($coef)
  	{
  		return new Color(array( 'red' => $this->getRed() * $coef,
  								            'green' => $this->getGreen() * $coef,
  								            'blue' => $this->getBlue() * $coef));
  	}
}