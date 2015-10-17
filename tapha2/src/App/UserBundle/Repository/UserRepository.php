<?php
//src/AppBundle/Repository/UserRepository

namespace App\UserBundle\Repository; 

use ED\BlogBundle\Interfaces\Repository\BlogUserRepositoryInterface;
use ED\BlogBundle\Model\Repository\UserRepository as BaseUserRepository;

class UserRepository extends BaseUserRepository implements BlogUserRepositoryInterface
{
}