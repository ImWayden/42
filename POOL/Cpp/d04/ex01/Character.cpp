/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 13:09:25 by msarr             #+#    #+#             */
/*   Updated: 2015/06/20 13:09:27 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string &name) : name(name), AP(40)
{
    this->weapon = NULL;
}

Character::~Character()
{
}

std::string Character::getName() const
{
    return this->name;
}

void Character::recoverAP()
{
   this->AP += 10;
   this->AP = (this->AP > 40) ? 40 : this->AP;
}

void Character::attack(Enemy *enemy)
{
    std::cout << this->getName() << " attacks " << enemy->getType() << " with a " << this->getWeapon()->getName() << std::endl;
    if (this->getWeapon() && this->getAP())
    {
        this->getWeapon()->attack();
        enemy->takeDamage(this->getWeapon()->getDamage());
        this->AP -= this->getWeapon()->getAPCost();
    }
    if (enemy->getHP() <= 0)
        delete enemy;
}

AWeapon *Character::getWeapon() const
{
    return this->weapon;
}

int Character::getAP(void) const
{
    return this->AP;
}

void Character::equip(AWeapon *weapon)
{
    this->weapon = weapon;
}


std::ostream &operator<<(std::ostream &o, const Character &rhs)
{
    if (rhs.getWeapon())
       o << rhs.getName() << " has " << rhs.getAP() << " AP and wields a " << rhs.getWeapon()->getName() << std::endl;
    else
        o << rhs.getName() << " has " << rhs.getAP() << " AP and is unarmed" << std::endl;
    return o;
}

Character &Character::operator=(Character const &rhs)
{
    this->name = rhs.getName();
    this->AP = rhs.getAP();
    this->weapon = rhs.getWeapon();
    return *this;
}
