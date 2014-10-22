<?php

/* ::base.html.twig */
class __TwigTemplate_ee0b096754c1630e6fd775baa333252fb52bc957f5ac7530fcfc6ac53e73fb59 extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        $this->parent = false;

        $this->blocks = array(
            'title' => array($this, 'block_title'),
            'stylesheets' => array($this, 'block_stylesheets'),
            'navigation' => array($this, 'block_navigation'),
            'blog_title' => array($this, 'block_blog_title'),
            'blog_tagline' => array($this, 'block_blog_tagline'),
            'body' => array($this, 'block_body'),
            'sidebar' => array($this, 'block_sidebar'),
            'footer' => array($this, 'block_footer'),
            'javascripts' => array($this, 'block_javascripts'),
        );
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        // line 1
        echo "<!-- app/Resources/views/base.html.twig -->
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv=\"Content-Type\" content=\"text/html\"; charset=\"utf-8\" />
        <title>";
        // line 6
        $this->displayBlock('title', $context, $blocks);
        echo " - symblog</title>
        <!--[if lt IE 9]>
            <script src=\"http://html5shim.googlecode.com/svn/trunk/html5.js\"></script>
        <![endif]-->
        ";
        // line 10
        $this->displayBlock('stylesheets', $context, $blocks);
        // line 15
        echo "        <link rel=\"shortcut icon\" href=\"";
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("favicon.ico"), "html", null, true);
        echo "\" />
    </head>
    <body>

        <section id=\"wrapper\">
            <header id=\"header\">
                <div class=\"top\">
                    ";
        // line 22
        $this->displayBlock('navigation', $context, $blocks);
        // line 33
        echo "                </div>

                <hgroup>
                    <h2>";
        // line 36
        $this->displayBlock('blog_title', $context, $blocks);
        echo "</h2>
                    <h3>";
        // line 37
        $this->displayBlock('blog_tagline', $context, $blocks);
        echo "</h3>
                </hgroup>
            </header>

            <section class=\"main-col\">
                ";
        // line 42
        $this->displayBlock('body', $context, $blocks);
        // line 43
        echo "            </section>
            <aside class=\"sidebar\">
                ";
        // line 45
        $this->displayBlock('sidebar', $context, $blocks);
        // line 46
        echo "            </aside>

            <div id=\"footer\">
                ";
        // line 49
        $this->displayBlock('footer', $context, $blocks);
        // line 52
        echo "            </div>
        </section>

        ";
        // line 55
        $this->displayBlock('javascripts', $context, $blocks);
        // line 56
        echo "    </body>
</html>
";
    }

    // line 6
    public function block_title($context, array $blocks = array())
    {
        echo "42project";
    }

    // line 10
    public function block_stylesheets($context, array $blocks = array())
    {
        // line 11
        echo "            <link href='http://fonts.googleapis.com/css?family=Irish+Grover' rel='stylesheet' type='text/css'>
            <link href='http://fonts.googleapis.com/css?family=La+Belle+Aurore' rel='stylesheet' type='text/css'>
            <link href=\"";
        // line 13
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("css/screen.css"), "html", null, true);
        echo "\" type=\"text/css\" rel=\"stylesheet\" />
        ";
    }

    // line 22
    public function block_navigation($context, array $blocks = array())
    {
        // line 23
        echo "                        <nav>
                            <ul class=\"navigation\">
                                <li><a href=\"";
        // line 25
        echo $this->env->getExtension('routing')->getPath("AcmeProjectBundle_homepage");
        echo "\">Home</a></li>
                                <li><a href=\"";
        // line 26
        echo $this->env->getExtension('routing')->getPath("fos_user_security_login");
        echo "\">Login</a></li>
                                <li><a href=\"#\">Register</a></li>
                                <li><a href=\"";
        // line 28
        echo $this->env->getExtension('routing')->getPath("AcmeProjectBundle_about");
        echo "\">About</a></li>
                                <li><a href=\"#\">Contact</a></li>
                            </ul>
                        </nav>
                    ";
    }

    // line 36
    public function block_blog_title($context, array $blocks = array())
    {
        echo "<a href=\"#\">42project</a>";
    }

    // line 37
    public function block_blog_tagline($context, array $blocks = array())
    {
        echo "<a href=\"#\">creating 42project in Symfony2</a>";
    }

    // line 42
    public function block_body($context, array $blocks = array())
    {
    }

    // line 45
    public function block_sidebar($context, array $blocks = array())
    {
    }

    // line 49
    public function block_footer($context, array $blocks = array())
    {
        // line 50
        echo "                    42project - created by msarr
                ";
    }

    // line 55
    public function block_javascripts($context, array $blocks = array())
    {
    }

    public function getTemplateName()
    {
        return "::base.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  176 => 55,  171 => 50,  168 => 49,  163 => 45,  158 => 42,  152 => 37,  146 => 36,  137 => 28,  132 => 26,  128 => 25,  124 => 23,  121 => 22,  115 => 13,  111 => 11,  108 => 10,  102 => 6,  96 => 56,  94 => 55,  89 => 52,  87 => 49,  82 => 46,  80 => 45,  76 => 43,  74 => 42,  66 => 37,  62 => 36,  57 => 33,  55 => 22,  44 => 15,  42 => 10,  35 => 6,  28 => 1,);
    }
}
