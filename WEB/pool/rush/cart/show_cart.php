<?php
function show_cart()
{
	if (!isset($_SESSION['cart']))
		echo "Empty";
	else
		echo "You have items in your cart";
}
?>