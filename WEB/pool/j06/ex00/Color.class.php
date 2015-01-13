<?php

class Color
{
	public $red;
	public $green;
	public $blue;
	public static $verbose = False;

	public function __construct(array $color)
	{
		if (isset($color['rgb']))
			$this->setcolorfromrgb($color);
		else
			$this->setcolor($color);
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
		return sprintf("Color( red: %3.3s, green: %3.3s, blue: %3.3s )", $this->red, $this->green, $this->blue);
	}

	private function setcolorfromrgb(array $color)
	{
		$this->red = intval(($color['rgb'] >> 16) % 256);
		$this->green = intval(($color['rgb'] >> 8) % 256);
		$this->blue = intval($color['rgb'] % 256);
	}

	private function setcolor(array $color)
	{
		$this->red = (isset($color['red'])) ? intval($color['red']) : 0;
		$this->green = (isset($color['green'])) ? intval($color['green']) : 0;
		$this->blue = isset($color['blue']) ? intval($color['blue']) : 0;
	}

	public function add(Color $rhs)
	{
		return new Color(array(
			'red' => $this->red + $rhs->red,
			'green' => $this->green + $rhs->green,
			'blue' => $this->blue + $rhs->blue));
	}

	public function sub(Color $rhs)
	{
		return new Color(array(
			'red' => $this->red - $rhs->red,
			'green' => $this->green - $rhs->green,
			'blue' => $this->blue - $rhs->blue));
		return $color;
	}

	public function mult($f)
	{
		return new Color(array(
			'red' => $this->red * $f,
			'green' => $this->green * $f,
			'blue' => $this->blue * $f));
	}

	public static function doc()
	{
		if (file_exists("Color.doc.txt"))
			return file_get_contents("Color.doc.txt");
	}
}