<?php
session_start();
$_SESSION['login'] = NULL;
$_SESSION['admin'] = "0";
unset($_SESSION);
header ("Location: /index.php");
?>