<?php

namespace App\ArticleBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;

class DefaultController extends Controller
{
    public function indexAction($name)
    {
        return $this->render('AppArticleBundle:Default:index.html.twig', array('name' => $name));
    }
}
