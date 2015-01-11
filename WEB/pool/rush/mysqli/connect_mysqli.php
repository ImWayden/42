<?php
$_SESSION['dblogin'] = $_POST['login'];
$_SESSION['dbpwd'] = $_POST['passwd'];
header("Location: index.php");
?>