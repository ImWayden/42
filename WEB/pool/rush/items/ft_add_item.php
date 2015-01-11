<?php
function ft_add_item($db, $tab)
{
	$name = $tab["name"];
	$price = $tab["price"];
	$stock = $tab["stock"];
	$picture = $tab["picture"];
	$query = "INSERT INTO `minishop`.`product` (`ID`, `price`, `stock`, `picture`) VALUES ('$name', '$price', '$stock', '$picture')";
	mysqli_query($db, $query);
}
?>