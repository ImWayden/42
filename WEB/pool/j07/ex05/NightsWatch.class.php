<?php

class NightsWatch
{
    public $men = array();

    function recruit($man)
    {
        if (class_implements($man))
            $this->men[] = $man;
    }
    
    function fight()
    {
        foreach ($this->men as $man)
            $man->fight();
    }
}
?>