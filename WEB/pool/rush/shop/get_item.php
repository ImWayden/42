<?php
function get_item($items, $i)
{
	if (isset($items[$i]))
	{
		print($items[$i][0]."\n");
		print($items[$i][1]."\n");
		print($items[$i][2]."\n");
		print($items[$i][3]."\n");
		print($items[$i][4]."\n");
		print($items[$i][5]."\n");
	}
}

function get_items($db)
{
	$query = "SELECT * FROM `product`";
	$row = mysqli_query($db, $query);
	while ($line = mysqli_fetch_array($row, MYSQLI_NUM))
		$items[] = $line;
	return ($items);
}
?>