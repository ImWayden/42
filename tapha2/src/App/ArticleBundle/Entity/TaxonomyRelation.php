<?php
//src/Acme/DemoBundle/Entity/Taxonomy.php

namespace App\ArticleBundle\Entity; 

use ED\BlogBundle\Interfaces\Model\TaxonomyRelationInterface;
use ED\BlogBundle\Model\Entity\TaxonomyRelation as BaseTaxonomyRelation;
use Doctrine\ORM\Mapping as ORM;

/**
 * @ORM\Table(name="acme_demo_taxonomy_relation")
 * @ORM\Entity()
 */
class TaxonomyRelation extends BaseTaxonomyRelation implements TaxonomyRelationInterface
{
}