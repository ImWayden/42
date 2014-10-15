<?php

namespace FW1\PlatformBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;

class DefaultController extends Controller
{
    public function indexAction($name)
    {
        return $this->render('FW1PlatformBundle:Default:index.html.twig', array('name' => $name));
    }
}
