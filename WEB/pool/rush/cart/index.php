<div class="all">

<?php
include("../mysqli/sqli_connect.php");
include("../shop/get_item.php");

session_start();

if (isset($_SESSION['login']) && isset($_SESSION["admin"]))
{
	if ($_SESSION["admin"] === "0")
		require_once("../includes/header_login.php");
	else
		require_once("../includes/header_admin.php");
}
else
	require_once("../includes/header_logout.php");

require_once("../includes/footer.php");
$db = sql_connect();
$items = get_items($db);
$in = NULL;
$cart = unserialize($_SESSION["cart"]);

if ($cart)
{
	foreach ($cart as $key => $val)
	{
		if ($val != 0 && $key != "price")
			foreach ($items as $item)
				if ($item[0] === $key)
					$in[] = $item;
	}
	$i = 0;
}
else
{

	?><h5 class="empty_cart">Vous n'avez pas d'article dans votre panier</h5><?php
	exit;
}
?>

	<div class="cart">
		Montant TTC : <?PHP print($cart["price"]) ?> €
		<a alt="Passer Commande" title="Passer Commande" href="./checkout_cart.php"><img class="cart_img" src="../includes/img/euros.png"/></a>
		<a alt="Supprimer Panier" title="Supprimer Panier" href="./empty_cart.php"><img class="cart_img" src="../includes/img/poubelle.png"/></a>
	</div>

	<table>
		<tr>
			<td>
				<?PHP
					if (!isset($in[$i]))
					{
						exit;
					}
				?>
				Name: <?PHP print($in[$i][0]) ?> <br/>
				Price: <?PHP print($in[$i][1]) ?> &euro; <br/>
				Stock restant: <?PHP print($in[$i][2]) ?><br/>
				Dans le panier: <?PHP print($val) ?><br/>
				<img class="plane_pic" src="<?= $in[$i][3] ?>"/>
				<a alt="Supprimer Article" title="Supprimer Article" href="../cart/remove_item.php?item=<?= $in[$i][0] ?>"><img src="../includes/img/moins.png"></a>
				<?PHP $i++?>
			</td>
			<td>
				<?PHP
					if (!isset($in[$i]))
						exit;
				?>
				Name: <?PHP print($in[$i][0]) ?> <br/>
				Price: <?PHP print($in[$i][1]) ?> &euro; <br/>
				Stock restant: <?PHP print($in[$i][2]) ?> <br/>
				Dans le panier: <?PHP print($val) ?><br/>
				<img class="plane_pic" src="<?= $in[$i][3] ?>"/>
				<a alt="Supprimer Article" title="Supprimer Article" href="../cart/remove_item.php?item=<?= $in[$i][0] ?>"><img src="../includes/img/moins.png"></a>
				<?PHP $i++?>
			</td>
			<td>
				<?PHP
					if (!isset($in[$i]))
						exit;
				?>
				Name: <?PHP print($in[$i][0]) ?> <br/>
				Price: <?PHP print($in[$i][1]) ?> &euro; <br/>
				Stock restant: <?PHP print($in[$i][2]) ?>  <br/>
				Dans le panier: <?PHP print($val) ?><br/>
				<img class="plane_pic" src="<?= $in[$i][3] ?>"/>
				<a alt="Supprimer Article" title="Supprimer Article" href="../cart/remove_item.php?item=<?= $in[$i][0] ?>"><img src="../includes/img/moins.png"></a>
				<?PHP $i++?>
			</td>
		</tr>
		<tr>
			<td>
				<?PHP
					if (!isset($in[$i]))
						exit;
				?>
				Name: <?PHP print($in[$i][0]) ?> <br/>
				Price: <?PHP print($in[$i][1]) ?> &euro; <br/>
				Stock restant: <?PHP print($in[$i][2]) ?> <br/>
				Dans le panier: <?PHP print($val) ?><br/>
				<img class="plane_pic" src="<?= $in[$i][3] ?>"/>
				<a alt="Supprimer Article" title="Supprimer Article" href="../cart/remove_item.php?item=<?= $in[$i][0] ?>"><img src="../includes/img/moins.png"></a>
				<?PHP $i++?>
			</td>
			<td>
				<?PHP
					if (!isset($in[$i]))
						exit;
				?>
				Name: <?PHP print($in[$i][0]) ?> <br/>
				Price: <?PHP print($in[$i][1]) ?> &euro; <br/>
				Stock restant: <?PHP print($in[$i][2]) ?> <br/>
				Dans le panier: <?PHP print($val) ?><br/>
				<img class="plane_pic" src="<?= $in[$i][3] ?>"/>
				<a alt="Supprimer Article" title="Supprimer Article" href="../cart/remove_item.php?item=<?= $in[$i][0] ?>"><img src="../includes/img/moins.png"></a>
				<?PHP $i++?>
			</td>
			<td>
				<?PHP
					if (!isset($in[$i]))
						exit;
				?>
				Name: <?PHP print($in[$i][0]) ?> <br/>
				Price: <?PHP print($in[$i][1]) ?> &euro; <br/>
				Stock restant: <?PHP print($in[$i][2]) ?>  <br/>
				Dans le panier: <?PHP print($val) ?><br/>
				<img class="plane_pic" src="<?= $in[$i][3] ?>"/>
				<a alt="Supprimer Article" title="Supprimer Article" href="../cart/remove_item.php?item=<?= $in[$i][0] ?>"><img src="../includes/img/moins.png"></a>
				<?PHP $i++?>
			</td>
		</tr>
		<tr>
			<td>
				<?PHP
					if (!isset($in[$i]))
						exit;
				?>
				Name: <?PHP print($in[$i][0]) ?> <br/>
				Price: <?PHP print($in[$i][1]) ?> &euro; <br/>
				Stock restant: <?PHP print($in[$i][2]) ?> <br/>
				Dans le panier: <?PHP print($val) ?><br/>
				<img class="plane_pic" src="<?= $in[$i][3] ?>"/>
				<a alt="Supprimer Article" title="Supprimer Article" href="../cart/remove_item.php?item=<?= $in[$i][0] ?>"><img src="../includes/img/moins.png"></a>
				<?PHP $i++?>
			</td>
			<td>
				<?PHP
					if (!isset($in[$i]))
						exit;
				?>
				Name: <?PHP print($in[$i][0]) ?> <br/>
				Price: <?PHP print($in[$i][1]) ?> &euro; <br/>
				Stock restant: <?PHP print($in[$i][2]) ?> <br/>
				Dans le panier: <?PHP print($val) ?><br/>
				<img class="plane_pic" src="<?= $in[$i][3] ?>"/>
				<a alt="Supprimer Article" title="Supprimer Article" href="../cart/remove_item.php?item=<?= $in[$i][0] ?>"><img src="../includes/img/moins.png"></a>
				<?PHP $i++?>
			</td>
			<td>
				<?PHP
					if (!isset($in[$i]))
						exit;
				?>
				Name: <?PHP print($in[$i][0]) ?> <br/>
				Price: <?PHP print($in[$i][1]) ?> &euro; <br/>
				Stock restant: <?PHP print($in[$i][2]) ?>  <br/>
				Dans le panier: <?PHP print($val) ?><br/>
				<img class="plane_pic" src="<?= $in[$i][3] ?>"/>
				<a alt="Supprimer Article" title="Supprimer Article" href="../cart/remove_item.php?item=<?= $in[$i][0] ?>"><img src="../includes/img/moins.png"></a>
				<?PHP $i++?>
			</td>
		</tr>
		<tr>
			<td>
				<?PHP
					if (!isset($in[$i]))
						exit;
				?>
				Name: <?PHP print($in[$i][0]) ?> <br/>
				Price: <?PHP print($in[$i][1]) ?> &euro; <br/>
				Stock restant: <?PHP print($in[$i][2]) ?> <br/>
				Dans le panier: <?PHP print($val) ?><br/>
				<img class="plane_pic" src="<?= $in[$i][3] ?>"/>
				<a alt="Supprimer Article" title="Supprimer Article" href="../cart/remove_item.php?item=<?= $in[$i][0] ?>"><img src="../includes/img/moins.png"></a>
				<?PHP $i++?>
			</td>
			<td>
				<?PHP
					if (!isset($in[$i]))
						exit;
				?>
				Name: <?PHP print($in[$i][0]) ?> <br/>
				Price: <?PHP print($in[$i][1]) ?> &euro; <br/>
				Stock restant: <?PHP print($in[$i][2]) ?> <br/>
				Dans le panier: <?PHP print($val) ?><br/>
				<img class="plane_pic" src="<?= $in[$i][3] ?>"/>
				<a alt="Supprimer Article" title="Supprimer Article" href="../cart/remove_item.php?item=<?= $in[$i][0] ?>"><img src="../includes/img/moins.png"></a>
				<?PHP $i++?>
			</td>
			<td>
				<?PHP
					if (!isset($in[$i]))
						exit;
				?>
				Name: <?PHP print($in[$i][0]) ?> <br/>
				Price: <?PHP print($in[$i][1]) ?> &euro; <br/>
				Stock restant: <?PHP print($in[$i][2]) ?> <br/>
				Dans le panier: <?PHP print($val) ?><br/>
				<img class="plane_pic" src="<?= $in[$i][3] ?>"/>
				<a alt="Supprimer Article" title="Supprimer Article" href="../cart/remove_item.php?item=<?= $in[$i][0] ?>"><img src="../includes/img/moins.png"></a>
				<?PHP $i++?>
			</td>
		</tr>
	</table>
</div>
</html>