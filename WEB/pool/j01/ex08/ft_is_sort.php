<?
function ft_is_sort($value)
{
	$key = 0;
	while($value[$key + 1])
	{
		echo $value[$key]."\n";
		if (strcmp($value[$key], $value[$key + 1]) > 0)
			return (FALSE);
		$key++;
	}
	return TRUE;
}
?>