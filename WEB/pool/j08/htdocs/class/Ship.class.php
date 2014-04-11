<?php

class Ship {

    public $name = "Stoufy Destroyer";
    public $size = 0; // ship size
    public $status = 0; // 0 = desactive ; 1 = active
    public $type = 0; // 0 = light ; 1 = medium ; 2 = heavy
    public $weapon = 0; // 0 = light ; 1 = medium ; 2 = heavy
    public $pv = 5; // 5 pv for lightest ship
    public $pp = 10;
    public $speed = 20; // 20 for lightest ship ; 15 = medium ; 10 = heavy
    public $inertia = 3; // 3 = light ; 4 = medium ; 5 = medium
    public $shield = 0; //Have to buy it with pp (1 for 1)

    function __construct() {
        if (self::$verbose)
        {
            echo "Construct 'Ship class' called"
        }
    }

    function __destruct() {
        if (self::$verbose)
        {
            echo "Destruct 'Ship class' called"
        }
    }
}
