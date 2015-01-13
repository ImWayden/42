<?php

require_once('Vertex.class.php');

Class Matrix
{
	const IDENTITY = 1;
	const SCALE = 2;
	const RX = 3;
	const RY = 4;
	const RZ = 5;
	const TRANSLATION = 6;
	const PROJECTION = 7;
	private $_matrix;
	public static $verbose = false;

	public function __construct(array $args)
	{
		if (isset($args['preset'], $args))
		{
			if ($args['preset'] == self::SCALE)
			{
				if (isset($args['scale']))
					$this->_init_scale($args['scale']);
				else
					exit();
			}
			else if ($args['preset'] == self::RX || $args['preset'] == self::RY || $args['preset'] == self::RZ)
			{
				if (isset($args['angle']))
				{
					if ($args['preset'] == self::RX)
						$this->_init_rx($args['angle']);
					if ($args['preset'] == self::RY)
						$this->_init_ry($args['angle']);
					if ($args['preset'] == self::RZ)
						$this->_init_rz($args['angle']);
				}
				else
					exit();
			}
			else if ($args['preset'] == self::TRANSLATION)
			{
				if (isset($args['vtc'], $args))
					$this->_init_translation($args['vtc']);
				else
					exit();
			}
			else if ($args['preset'] == self::PROJECTION)
			{
				if (array_key_exists('fov', $args) && array_key_exists('ratio', $args) && array_key_exists('near', $args) && array_key_exists('far', $args))
					$this->_init_projection($args['fov'], $args['ratio'], $args['near'], $args['far']);
				else
					exit();
			}
			else if ($args['preset'] == self::IDENTITY)
				$this->_init_identity();
		}
		else
			exit();
	}

	public function __destruct()
	{
		if (self::$verbose)
			print("Matrix instance destructed\n");
	}
	
	public function __toString()
	{
		$ret = sprintf("M | vtcX | vtcY | vtcZ | vtxO\n");
		$ret .= sprintf("-----------------------------\n");
		$ret .= sprintf("x | %3.2f | %3.2f | %3.2f | %3.2f\n", $this->_matrix[0][0], $this->_matrix[0][1], $this->_matrix[0][2], $this->_matrix[0][3]);
		$ret .= sprintf("y | %3.2f | %3.2f | %3.2f | %3.2f\n", $this->_matrix[1][0], $this->_matrix[1][1], $this->_matrix[1][2], $this->_matrix[1][3]);
		$ret .= sprintf("z | %3.2f | %3.2f | %3.2f | %3.2f\n", $this->_matrix[2][0], $this->_matrix[2][1], $this->_matrix[2][2], $this->_matrix[2][3]);
		$ret .= sprintf("w | %3.2f | %3.2f | %3.2f | %3.2f", $this->_matrix[3][0], $this->_matrix[3][1], $this->_matrix[3][2], $this->_matrix[3][3]);
		return ($ret);
	}

	public static function doc()
	{
		if (file_exists("Matrix.doc.txt"))
			return file_get_contents("Matrix.doc.txt");
	}

	private function _init_identity()
	{
		$this->_matrix = array(
			array(1, 0, 0, 0),
			array(0, 1, 0, 0),
			array(0, 0, 1, 0),
			array(0, 0, 0, 1));
		if (self::$verbose)
			print("Matrix IDENTITY instance constructed\n");
	}
	private function _init_translation(Vector $translation)
	{
		$this->_matrix = array(
			array(1, 0, 0, $translation->getX()),
			array(0, 1, 0, $translation->getY()),
			array(0, 0, 1, $translation->getZ()),
			array(0, 0, 0, 1));
		if (self::$verbose)
			print("Matrix TRANSLATION preset instance constructed\n");
	}

	private function _init_scale($scale)
	{
		$this->_matrix = array(
			array($scale, 0, 0, 0),
			array(0, $scale, 0, 0),
			array(0, 0, $scale, 0),
			array(0, 0, 0, 1));
		if (self::$verbose)
			print("Matrix SCALE preset instance constructed\n");
	}

	private function _init_rx($angle)
	{
		$this->_matrix = array(
			array(1, 0, 0, 0),
			array(0, cos($angle), -sin($angle), 0),
			array(0, sin($angle), cos($angle), 0),
			array(0, 0, 0, 1));
		if (self::$verbose)
			print("Matrix Ox ROTATION preset instance constructed\n");
	}

	private function _init_ry($angle)
	{
		$this->_matrix = array(
			array(cos($angle), 0, sin($angle), 0),
			array(0, 1, 0, 0),
			array(-sin($angle), 0, cos($angle), 0),
			array(0, 0, 0, 1));
		if (self::$verbose)
			print("Matrix Oy ROTATION preset instance constructed\n");
	}

	private function _init_rz($angle)
	{
		$this->_matrix = array(
			array(cos($angle), -sin($angle), 0, 0),
			array(sin($angle), cos($angle), 0, 0),
			array(0, 0, 1, 0),
			array(0, 0, 0, 1));
		if (self::$verbose)
			print("Matrix Oz ROTATION preset instance constructed\n");
	}

	private function _degToRad($angle)
	{
		return (($angle * pi()) / 180);
	}
	
	private function _init_projection($fov, $ratio, $near, $far)
	{
		$this->_matrix = array(
			array((1 / tan($this->_degToRad($fov * 0.5))) / $ratio, 0, 0, 0),
			array(0, 1 / tan($this->_degToRad($fov * 0.5)), 0, 0),
			array(0, 0, -$far * (1 / ($far - $near)), -1 - ($far * $near) * (1 / ($far - $near))),
			array(0, 0, -1, 0));
		if (self::$verbose)
			print("Matrix PROJECTION preset instance constructed\n");
	}

	public function mult(Matrix $rhs)
	{
		$res = clone $this;
		$i = -1;
		while (++$i < 4)
		{
			$j = -1;
			while (++$j < 4)
			{
				$k = -1;
				$sum = 0;
				while (++$k < 4)
					$sum += $this->_matrix[$i][$k] * $rhs->_matrix[$k][$j];
				$res->_matrix[$i][$j] = $sum;
			}
		}
		return ($res);
	}

	public function transformVertex(Vertex $vtx)
	{
		return new Vertex(array(
			'x' => ($this->_matrix[0][0] * $vtx->getX() + $this->_matrix[0][1] * $vtx->getY() + $this->_matrix[0][2] * $vtx->getZ() + $this->_matrix[0][3] * $vtx->getW()),
			'y' => ($this->_matrix[1][0] * $vtx->getX() + $this->_matrix[1][1] * $vtx->getY() + $this->_matrix[1][2] * $vtx->getZ() + $this->_matrix[1][3] * $vtx->getW()),
			'z' => ($this->_matrix[2][0] * $vtx->getX() + $this->_matrix[2][1] * $vtx->getY() + $this->_matrix[2][2] * $vtx->getZ() + $this->_matrix[2][3] * $vtx->getW()),
			'w' => ($this->_matrix[3][0] * $vtx->getX() + $this->_matrix[3][1] * $vtx->getY() + $this->_matrix[3][2] * $vtx->getZ() + $this->_matrix[3][3] * $vtx->getW()),
			'color' => $vtx->getColor()));
	}
}
?>