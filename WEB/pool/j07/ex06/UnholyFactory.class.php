<?php

class UnholyFactory
{
    public $men = array();

    function absorb($man)
    {
        foreach (class_parents($man) as $m)
        {
            if ($m == "Fighter")
            {
                foreach ($this->men as $f)
                    if (get_class($f) == get_class($man))
                    {
                        print '(Factory already absorbed a fighter of type '.get_class($man).')'.PHP_EOL;
                        return ;
                    }
                $this->men[] = $man;
                print '(Factory absorbed a fighter of type '.get_class($man).')'.PHP_EOL;
                return ;
            }
        }
        print '(Factory can\'t absorb this, it\'s not a fighter)'.PHP_EOL;
    }

    function fight($t)
    {
        foreach ($this->men as $man)
            $man->fight($t);
    }

    function fabricate($s)
    {
        foreach ($this->men as $man)
        {
            if (!strcasecmp($man->job,$s))
            {
                print '(Factory fabricates a fighter of type '.$s.')'.PHP_EOL;
                return $man;
                return ;
            }
        }
        print '(Factory hasn\'t absorbed any fighter of type '.$s.')'.PHP_EOL;
    }
}
?>