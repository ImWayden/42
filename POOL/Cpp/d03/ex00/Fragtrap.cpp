/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fragtrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 11:47:27 by msarr             #+#    #+#             */
/*   Updated: 2015/06/19 11:47:27 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "Default Constructor Called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src)
{
    std::cout << "Copy Constructor Called" << std::endl;
    *this = src;
}

FragTrap::FragTrap(const std::string str) : name(str)
{
    std::cout << "String Constructor Called" << std::endl;
    this->HitPoint = 100;
    this->MaxHitPoint = 100;
    this->EnergyPoint = 100;
    this->MaxEnergyPoint = 100;
    this->level = 1;
    this->meleeAttackDamage = 30;
    this->rangedAttackDamage = 20;
    this->ArmorAttackReduction = 5;
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor Called" << std::endl;
}

void FragTrap::rangedAttack(const std::string &target)
{
    std::cout << "FR4G-TP <" << this->getName() << "> attacks <" << target << "> at range, causing <" << this->getRangedAttackDamage() << "> points of damage" << std::endl;
}

void FragTrap::meleeAttack(const std::string &target)
{
    std::cout << "FR4G-TP <" << this->getName() << "> attacks <" << target << "> at melee, causing <" << this->getMeleeAttackDamage() << "> points of damage" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
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

void    FragTrap::vaulthunter_dot_exe(const std::string &target)
{
    if ((this->getEnergyPoint() - 25) > 0)
    {
        std::string randomAttack[5];
        randomAttack[0] = "Lazer";
        randomAttack[1] = "MachineGun";
        randomAttack[2] = "FireBall";
        randomAttack[3] = "Two Handed Axe";
        randomAttack[4] = "Sword";

        this->EnergyPoint -= 25;
        std::cout << "FR4G-TP <" << this->getName() << "> is attacking <" << target << "> with " << randomAttack[std::rand() % 5] << std::endl;
    }
    else
        std::cout << "FR4G-TP <" << this->getName() << "> Not enough Energy Points to attack" << std::endl;
  
}

void FragTrap::takeDamage(unsigned int amount)
{
    this->HitPoint -= (amount -= this->getArmorAttackReduction());
    this->HitPoint =  (this->getHitPoint() < 0) ? 0 : this->HitPoint;
    if (this->getHitPoint() <= 0)
        std::cout << "this unit is destroyed" << std::endl;
    else
        std::cout << "FR4G-TP <" << this->getName() << "> is hit by <" << amount + this->getArmorAttackReduction() << "> Hit points " << "(reduced to " << amount << ")" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
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

int FragTrap::getHitPoint() const
{
    return HitPoint;
}

int FragTrap::getMaxHitPoint() const
{
    return MaxHitPoint;
}

int FragTrap::getEnergyPoint() const
{
    return EnergyPoint;
}

int FragTrap::getMaxEnergyPoint() const
{
    return MaxEnergyPoint;
}

int FragTrap::getLevel() const
{
    return level;
}

std::string FragTrap::getName() const
{
    return name;
}

int FragTrap::getMeleeAttackDamage() const
{
    return meleeAttackDamage;
}

int FragTrap::getRangedAttackDamage() const
{
    return rangedAttackDamage;
}

int FragTrap::getArmorAttackReduction() const
{
    return ArmorAttackReduction;
}