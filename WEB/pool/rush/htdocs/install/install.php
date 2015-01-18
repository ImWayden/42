#!/usr/bin/php
<?php
echo "=> Identifiants de la BDD <=\n\n";

echo "Pseudo de la BDD:\n";
$login = trim(fgets(STDIN));
echo "Password de la BDD:\n";
$password = trim(fgets(STDIN));

$connect = mysqli_connect('localhost:3306', $login, $password);
$sql="CREATE DATABASE IF NOT EXISTS asb";
if (mysqli_query($connect, $sql))
	echo "BDD cree avec succes...\n\n";
else
	echo "Erreur en creant la BDD !\n\n";

echo "=> Identifiants du compte admin en jeu <=\n\n";

echo "Pseudo du compte admin:\n";
$admin_login = trim(fgets(STDIN));
echo "Password du compte admin:\n";
$admin_password = hash("whirlpool", trim(fgets(STDIN)));

$connect = mysqli_connect('localhost:3306', $login, $password, "asb");

$sql="CREATE TABLE user(login CHAR(30), passwd CHAR(128), admin CHAR(1), score INT, level INT)";
if (mysqli_query($connect, $sql))
	echo "Table \"user\" cree avec succes...\n";
else
	echo "Erreur en creant la table \"user\" !\n";

$sql = "INSERT INTO `asb`.`user` (`login`, `passwd`, `admin`, `score`, `level`) VALUES ('$admin_login', '$admin_password', '1', 1000, 100)";
if (mysqli_query($connect, $sql))
	echo "Admin cree avec succes...\n\n";
else
	echo "Erreur en creant le compte admin !\n\n";

$sql="CREATE TABLE faction(faction_id INT, name CHAR(30), ship_id INT)";
if (mysqli_query($connect, $sql))
	echo "Table \"faction\" cree avec succes...\n";
else
	echo "Erreur en creant la table \"faction\" !\n";

$sql="CREATE TABLE ship(ship_id INT, name CHAR(30), weapon_id INT, size INT, sprit_url CHAR(255), speed INT, shield INT, active BOOLEAN)";
if (mysqli_query($connect, $sql))
	echo "Table \"ship\" cree avec succes...\n";
else
	echo "Erreur en creant la table \"ship\" !\n";

$sql="CREATE TABLE weapon(weapon_id INT, name CHAR(30), scope INT, zone INT, charge INT, special INT)";
if (mysqli_query($connect, $sql))
	echo "Table \"weapon\" cree avec succes...\n";
else
	echo "Erreur en creant la table \"weapon\" !\n";

echo "\n=> Vous pouvez vous connecter au jeu avec vos identifiants <=\n";

$sql="CREATE TABLE game(game_id INT, name CHAR(30), player1_id INT, player2_id INT, player3_id INT, player4_id INT, faction1_id INT, faction2_id INT, faction3_id INT, faction4_id INT)";
if (mysqli_query($connect, $sql))
	echo "Table \"game\" cree avec succes...\n";
else
	echo "Erreur en creant la table \"game\" !\n";

mysqli_close($connect);
?>
