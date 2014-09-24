<?
function ft_split($value)
{
	sort($array = preg_split("([ ]+)", trim($value)));
	return $array;
}
?>
