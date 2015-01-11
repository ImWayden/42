<?php
function cart_price()
{
	if (isset($_SESSION['cart']))
		$cart = unserialize($_SESSION['cart']);
	else
	{
		echo "Total price is 0";
		return ;
	}
	echo $cart['price'];
}
?>