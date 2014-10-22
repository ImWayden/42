<?php
// src/Blogger/BlogBundle/Controller/PageController.php

namespace Acme\ProjectBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;

class PageController extends Controller
{
    public function indexAction()
    {
        return $this->render('AcmeProjectBundle:Page:index.html.twig');
    }

    public function aboutAction()
    {
        return $this->render('AcmeProjectBundle:Page:about.html.twig');
    }
}