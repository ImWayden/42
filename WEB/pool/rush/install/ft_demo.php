<?php
include("../items/ft_add_item.php");

function ft_demo($db)
{
	$item = array("name" => "Raspberry Pi A", "price" => 25, "stock" => 4, "picture" => "http://images.bit-tech.net/content_images/2012/04/raspberry-pi-review/raspberrypi-main-1280x1024.jpg");
	ft_add_item($db, $item);
	$item = array("name" => "Ecran Pc PHILIPS 273E3LHSB", "price" => 200, "stock" => 2, "picture" => "http://img11.hostingpics.net/pics/256595logo42court.png");
	ft_add_item($db, $item);
	$item = array("name" => "MSI NVIDIA GTX780 TI", "price" => 480, "stock" => 1, "picture" => "http://images.grosbill.com/imagesproduitnew/images800jpg/630530.jpg");
	ft_add_item($db, $item);
	$item = array("name" => "MSI NVIDIA GTX750 TI", "price" => 149, "stock" => 3, "picture" => "http://images.grosbill.com/imagesproduitnew/images800jpg/630530.jpg");
	ft_add_item($db, $item);
	$item = array("name" => "INTEL Core i7-4790K", "price" => 325, "stock" => 2, "picture" => "http://images.grosbill.com/imagesproduitnew/images800jpg/621102.jpg");
	ft_add_item($db, $item);
	$item = array("name" => "Carte Mere MSI X99S XPOWER", "price" => 359, "stock" => 1, "picture" => "http://images.grosbill.com/imagesproduitnew/images800jpg/626229.jpg");
	ft_add_item($db, $item);
	$item = array("name" => "Raspberry Pi B", "price" => 39, "stock" => 3, "picture" => "http://images.bit-tech.net/content_images/2012/04/raspberry-pi-review/raspberrypi-main-1280x1024.jpg");
	ft_add_item($db, $item);
	$item = array("name" => "Raspberry Pi B+", "price" => 50, "stock" => 2, "picture" => "http://images.bit-tech.net/content_images/2012/04/raspberry-pi-review/raspberrypi-main-1280x1024.jpg");
	ft_add_item($db, $item);
}
?>