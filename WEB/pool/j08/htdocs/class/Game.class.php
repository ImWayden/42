<?php

class Game {

   public $player1 = "Zymo"; // nom du joueur 1
   public $player2 = "Mozy"; // nom du joueur 2
   public $turn = 0; // 0 = tour du j1 ; 1 = tour du j2 (rand ?)
   public $dice = 0; // Rand() [0-6]

   function __construct() {
      if (self::$verbose)
      {
         echo "Construct 'Game class' called"
      }
   }

   function __destruct() {
      if (self::$verbose)
      {
         echo "Destruct 'Game class' called"
      }
   }
}
