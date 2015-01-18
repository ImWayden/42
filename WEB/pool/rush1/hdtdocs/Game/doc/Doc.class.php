<?php
trait Doc
{
	public static function doc()
	{
		$filename = get_class($this).".doc.txt";
		$doc = "<- ".get_class($this)." ----------------------------------------------------------------------". PHP_EOL;
		if (file_exists($filename))
			$doc .= file_get_contents($filename)."\n";
		else
			$doc .= "No documentation for this class yet.\n";
		$doc .= "---------------------------------------------------------------------- ".get_class($this)." ->". PHP_EOL;
		return $doc;
	}
}
?>