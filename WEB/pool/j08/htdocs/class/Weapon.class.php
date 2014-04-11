<?php

class Weapon {

    public $ammo = 0; // Buy it with pp (1 for 1)
    public $range_s = 1; // [1-10] rand ?
    public $range_m = 11; // [11-20] rand ?
    public $range_h = 21; // [21-30] rand ?
    public $effect = 0; // What we want

    public static $verbose = FALSE;

    function __construct() {
        if (self::$verbose)
        {
            echo "Construct 'Weapon class' called"
        }
    }

    function __destruct() {
        if (self::$verbose)
        {
            echo "Destruct 'Weapon class' called"
        }
    }

}
