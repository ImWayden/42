<?php
class Lannister
{
    public $isSis = true;

    public function sleepWith($someone)
    {
        if (!isset($someone->isSis))
            print 'Let\'s do this'.PHP_EOL;
        else if (!$someone->isSis)
            print 'Not even if I\'m drunk !'.PHP_EOL;
        else
            print 'With pleasure, but only in a tower in Winterfell, then.'.PHP_EOL;
    }
}
?>