<?php
class Tyrion extends Lannister
{
    public $isSis = false;

    public function sleepWith($someone)
    {
        if (!isset($someone->isSis))
            print 'Let\'s do this'.PHP_EOL;
        else
            print 'Not even if I\'m drunk !'.PHP_EOL;
    }
}
?>