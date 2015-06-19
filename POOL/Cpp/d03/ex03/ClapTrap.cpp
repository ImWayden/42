/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 13:31:31 by msarr             #+#    #+#             */
/*   Updated: 2015/06/19 13:32:10 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default ClapTrap Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
    std::cout << "Copy ClapTrap Constructor Called" << std::endl;
    *this = src;
}

ClapTrap::ClapTrap(const std::string str) : name(str)
{
    std::cout << "String ClapTrap Constructor Called" << std::endl;
    this->HitPoint = 100;
    this->MaxEnergyPoint = 100;
    this->EnergyPoint = 50;
    this->MaxEnergyPoint = 100;
    this->level = 1;
    this->meleeAttackDamage = 20;
    this->rangedAttackDamage = 15;
    this->ArmorAttackReduction = 3;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor ClapTrap Called" << std::endl;
}

void ClapTrap::rangedAttack(const std::string &target)
{
    std::cout << "FR4G-TP <" << this->getName() << "> attacks <" << target << "> at range, causing <" << this->getRangedAttackDamage() << "> points of damage" << std::endl;
}

void ClapTrap::meleeAttack(const std::string &target)
{
    std::cout << "FR4G-TP <" << this->getName() << "> attacks <" << target << "> at melee, causing <" << this->getMeleeAttackDamage() << "> points of damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->getHitPoint() >= this->getMaxHitPoint())
        std::cout << "The unit is already at Max Hit Point" << std::endl;
    else
    {
        if (this->getHitPoint() == 0)
            std::cout << "FR4G-TP <" << this->getName() << "> has been resurected" << std::endl;
        else
        {
            std::cout << "FR4G-TP <" << this->getName() << "> is heal by " << amount << "> Hit points" << std::endl;
            this->HitPoint += amount;
            this->HitPoint =  (this->getHitPoint() > this->getMaxHitPoint()) ? this->getMaxHitPoint() : this->HitPoint;
        }
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->HitPoint -= (amount -= this->getArmorAttackReduction());
    this->HitPoint =  (this->getHitPoint() < 0) ? 0 : this->HitPoint;
    if (this->getHitPoint() <= 0)
        std::cout << "this unit is destroyed" << std::endl;
    else
        std::cout << "FR4G-TP <" << this->getName() << "> is hit by <" << amount + this->getArmorAttackReduction() << "> Hit points " << "(reduced to " << amount << ")" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
    this->HitPoint = rhs.getHitPoint();
    this->EnergyPoint = rhs.getEnergyPoint();
    this->level = rhs.getLevel();
    this->name = rhs.getName();
    this->meleeAttackDamage = rhs.getMeleeAttackDamage();
    this->rangedAttackDamage = rhs.getRangedAttackDamage();
    this->ArmorAttackReduction = rhs.getArmorAttackReduction();
    return *this;
}

int ClapTrap::getHitPoint() const
{
    return HitPoint;
}

int ClapTrap::getMaxHitPoint() const
{
    return MaxHitPoint;
}

int ClapTrap::getEnergyPoint() const
{
    return EnergyPoint;
}

int ClapTrap::getMaxEnergyPoint() const
{
    return MaxEnergyPoint;
}

int ClapTrap::getLevel() const
{
    return level;
}

std::string ClapTrap::getName() const
{
    return name;
}

int ClapTrap::getMeleeAttackDamage() const
{
    return meleeAttackDamage;
}

int ClapTrap::getRangedAttackDamage() const
{
    return rangedAttackDamage;
}

int ClapTrap::getArmorAttackReduction() const
{
    return ArmorAttackReduction;
}
