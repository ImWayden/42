<?php
include ("../mysqli/sqli_connect.php");
$db = sql_connect();
$name = $_POST['name'];
$query = "DELETE FROM `product` WHERE `ID` = '$name'";
mysqli_query($db, $query);
mysqli_close($db);
header("Location: ../admin/admin_succes.php");
?>