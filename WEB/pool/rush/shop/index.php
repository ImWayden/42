<div class="all">

<?php
include("../mysqli/sqli_connect.php");
include("./get_item.php");

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
$i = 0;
?>

	<table>
		<tr>
			<td>
				<?PHP
					if (!isset($items[$i]))
						exit;
				?>
				Name: <?PHP print($items[$i][0]) ?> <br/>
				Price: <?PHP print($items[$i][1]) ?> &euro; <br/>
				Stock: <?PHP print($items[$i][2]) ?><br/>
				<img class="plane_pic" src="<?= $items[$i][3] ?>"/>
				<a alt="Ajouter Article" title="Ajouter Article"  href="../cart/add_to_cart.php?item=<?= $items[$i][0] ?>"><img src="../includes/img/plus.png"></a>
				<?PHP $i++?>
			</td>
			<td>
				<?PHP
					if (!isset($items[$i]))
						exit;
				?>
				Name: <?PHP print($items[$i][0]) ?> <br/>
				Price: <?PHP print($items[$i][1]) ?> &euro; <br/>
				Stock: <?PHP print($items[$i][2]) ?> <br/>
				<img class="plane_pic" src="<?= $items[$i][3] ?>"/>
				<a alt="Ajouter Article" title="Ajouter Article"  href="../cart/add_to_cart.php?item=<?= $items[$i][0] ?>"><img src="../includes/img/plus.png"></a>
				<?PHP $i++?>
			</td>
			<td>
				<?PHP
					if (!isset($items[$i]))
						exit;
				?>
				Name: <?PHP print($items[$i][0]) ?> <br/>
				Price: <?PHP print($items[$i][1]) ?> &euro; <br/>
				Stock: <?PHP print($items[$i][2]) ?>  <br/>
				<img class="plane_pic" src="<?= $items[$i][3] ?>"/>
				<a alt="Ajouter Article" title="Ajouter Article"  href="../cart/add_to_cart.php?item=<?= $items[$i][0] ?>"><img src="../includes/img/plus.png"></a>
				<?PHP $i++?>
			</td>
		</tr>
		<tr>
			<td>
				<?PHP
					if (!isset($items[$i]))
						exit;
				?>
				Name: <?PHP print($items[$i][0]) ?> <br/>
				Price: <?PHP print($items[$i][1]) ?> &euro; <br/>
				Stock: <?PHP print($items[$i][2]) ?> <br/>
				<img class="plane_pic" src="<?= $items[$i][3] ?>"/>
				<a alt="Ajouter Article" title="Ajouter Article"  href="../cart/add_to_cart.php?item=<?= $items[$i][0] ?>"><img src="../includes/img/plus.png"></a>
				<?PHP $i++?>
			</td>
			<td>
				<?PHP
					if (!isset($items[$i]))
						exit;
				?>
				Name: <?PHP print($items[$i][0]) ?> <br/>
				Price: <?PHP print($items[$i][1]) ?> &euro; <br/>
				Stock: <?PHP print($items[$i][2]) ?> <br/>
				<img class="plane_pic" src="<?= $items[$i][3] ?>"/>
				<a alt="Ajouter Article" title="Ajouter Article"  href="../cart/add_to_cart.php?item=<?= $items[$i][0] ?>"><img src="../includes/img/plus.png"></a>
				<?PHP $i++?>
			</td>
			<td>
				<?PHP
					if (!isset($items[$i]))
						exit;
				?>
				Name: <?PHP print($items[$i][0]) ?> <br/>
				Price: <?PHP print($items[$i][1]) ?> &euro; <br/>
				Stock: <?PHP print($items[$i][2]) ?>  <br/>
				<img class="plane_pic" src="<?= $items[$i][3] ?>"/>
				<a alt="Ajouter Article" title="Ajouter Article"  href="../cart/add_to_cart.php?item=<?= $items[$i][0] ?>"><img src="../includes/img/plus.png"></a>
				<?PHP $i++?>
			</td>
		</tr>
		<tr>
			<td>
				<?PHP
					if (!isset($items[$i]))
						exit;
				?>
				Name: <?PHP print($items[$i][0]) ?> <br/>
				Price: <?PHP print($items[$i][1]) ?> &euro; <br/>
				Stock: <?PHP print($items[$i][2]) ?> <br/>
				<img class="plane_pic" src="<?= $items[$i][3] ?>"/>
				<a alt="Ajouter Article" title="Ajouter Article"  href="../cart/add_to_cart.php?item=<?= $items[$i][0] ?>"><img src="../includes/img/plus.png"></a>
				<?PHP $i++?>
			</td>
			<td>
				<?PHP
					if (!isset($items[$i]))
						exit;
				?>
				Name: <?PHP print($items[$i][0]) ?> <br/>
				Price: <?PHP print($items[$i][1]) ?> &euro; <br/>
				Stock: <?PHP print($items[$i][2]) ?> <br/>
				<img class="plane_pic" src="<?= $items[$i][3] ?>"/>
				<a alt="Ajouter Article" title="Ajouter Article"  href="../cart/add_to_cart.php?item=<?= $items[$i][0] ?>"><img src="../includes/img/plus.png"></a>
				<?PHP $i++?>
			</td>
			<td>
				<?PHP
					if (!isset($items[$i]))
						exit;
				?>
				Name: <?PHP print($items[$i][0]) ?> <br/>
				Price: <?PHP print($items[$i][1]) ?> &euro; <br/>
				Stock: <?PHP print($items[$i][2]) ?>  <br/>
				<img class="plane_pic" src="<?= $items[$i][3] ?>"/>
				<a alt="Ajouter Article" title="Ajouter Article"  href="../cart/add_to_cart.php?item=<?= $items[$i][0] ?>"><img src="../includes/img/plus.png"></a>
				<?PHP $i++?>
			</td>
		</tr>
		<tr>
			<td>
				<?PHP
					if (!isset($items[$i]))
						exit;
				?>
				Name: <?PHP print($items[$i][0]) ?> <br/>
				Price: <?PHP print($items[$i][1]) ?> &euro; <br/>
				Stock: <?PHP print($items[$i][2]) ?> <br/>
				<img class="plane_pic" src="<?= $items[$i][3] ?>"/>
				<a alt="Ajouter Article" title="Ajouter Article"  href="../cart/add_to_cart.php?item=<?= $items[$i][0] ?>"><img src="../includes/img/plus.png"></a>
				<?PHP $i++?>
			</td>
			<td>
				<?PHP
					if (!isset($items[$i]))
						exit;
				?>
				Name: <?PHP print($items[$i][0]) ?> <br/>
				Price: <?PHP print($items[$i][1]) ?> &euro; <br/>
				Stock: <?PHP print($items[$i][2]) ?> <br/>
				<img class="plane_pic" src="<?= $items[$i][3] ?>"/>
				<a alt="Ajouter Article" title="Ajouter Article"  href="../cart/add_to_cart.php?item=<?= $items[$i][0] ?>"><img src="../includes/img/plus.png"></a>
				<?PHP $i++?>
			</td>
			<td>
				<?PHP
					if (!isset($items[$i]))
						exit;
				?>
				Name: <?PHP print($items[$i][0]) ?> <br/>
				Price: <?PHP print($items[$i][1]) ?> &euro; <br/>
				Stock: <?PHP print($items[$i][2]) ?> <br/>
				<img class="plane_pic" src="<?= $items[$i][3] ?>"/>
				<a alt="Ajouter Article" title="Ajouter Article" href="../cart/add_to_cart.php?item=<?= $items[$i][0] ?>"><img src="../includes/img/plus.png"></a>
				<?PHP $i++?>
			</td>
		</tr>
	</table>
</div>
</html>