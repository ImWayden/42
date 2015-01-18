<?php

require_once 'doc/Doc.class.php';

/**
* 
*/

class Blf extends Weapon
{
	
	function shoot($pos, $dir, $players)
	{
		foreach ($players as $player)
		{
			$x = $player->getX();
			$y = $player->getX();
			if (($dir == 1 && self::isfront($pos, $player->pos))
				|| ($dir == 2 && self::isback($player->pos))
				|| ($dir == 3 && self::isleft($player->pos))
				|| ($dir == 4 && self::isright($player->pos)))
			{
				$i = $this->_charges;
				whie ($i > 0)
				{
					$player->takedmg($dice);
					i--;
				}
			}
		}
	}

	function hit($pos, $w, $pos2)
	{
		
	}
	
}

?>