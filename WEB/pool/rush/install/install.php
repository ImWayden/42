#!/usr/bin/php
<?php
include("./ft_demo.php");

echo "=> Identifiants de la BDD <=\n\n";

echo "Pseudo de la BDD:\n";
$login = trim(fgets(STDIN));
echo "Password de la BDD:\n";
$password = trim(fgets(STDIN));

$connect = mysqli_connect('localhost', $login, $password);
$sql="CREATE DATABASE IF NOT EXISTS minishop";
if (mysqli_query($connect, $sql))
	echo "BDD cree avec succes...\n\n";
else
	echo "Erreur en creant la BDD !\n\n";

echo "=> Identifiants du compte MiniShop <=\n\n";

echo "Pseudo du compte admin MiniShop:\n";
$admin_login = trim(fgets(STDIN));
echo "Password du compte admin MiniShop:\n";
$admin_password = hash("whirlpool", trim(fgets(STDIN)));

$connect = mysqli_connect('localhost', $login, $password, "minishop");
$sql="CREATE TABLE user(login CHAR(30),passwd CHAR(128),admin CHAR(1))";
if (mysqli_query($connect, $sql))
	echo "Table \"user\" cree avec succes...\n\n";
else
	echo "Erreur en creant la table \"user\" !\n\n";

$sql = "INSERT INTO `minishop`.`user` (`login`, `passwd`, `admin`) VALUES ('$admin_login', '$admin_password', '1')";
if (mysqli_query($connect, $sql))
	echo "Admin cree avec succes...\n\n";
else
	echo "Erreur en creant le compte admin !\n\n";

$sql="CREATE TABLE product(ID CHAR(30), price INT, stock INT, picture CHAR(255))";
if (mysqli_query($connect, $sql))
	echo "Table \"product\" cree avec succes...\n\n";
else
	echo "Erreur en creant la table \"product\" !\n\n";

$sql="CREATE TABLE category(ID CHAR(30), article_id INT)";
if (mysqli_query($connect, $sql))
	echo "Table \"category\" cree avec succes...\n\n";
else
	echo "Erreur en creant la table \"product\" !\n\n";

$demo = "banane";
while ($demo !== "Y" && $demo !== "N")
{
	echo "Voulez-vous une installation automatique des produits de demo dans la bdd ? (Y/N):\n";
	$demo = trim(fgets(STDIN));
}

if ($demo === "Y")
	ft_demo($connect);

echo "\n=> Vous pouvez vous connecter au MiniShop avec vos identifiants <=\n";

mysqli_close($connect);
?>