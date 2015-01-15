<?php
abstract class Fighter
{
    public $job;
    abstract function fight($man);
    function __construct($str)
    {
        $this->job = $str;
    }
}
?>