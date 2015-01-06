<?
function ft_split($value)
{
	$array = preg_split("([ ]+)", trim($value));
	sort($array);
	return $array;
}
?>
