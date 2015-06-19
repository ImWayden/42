/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 22:16:44 by msarr             #+#    #+#             */
/*   Updated: 2015/06/19 22:16:46 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(NinjaTrap const &src) : ClapTrap() {
    std::cout << "Copy Ninja Constructor Called" << std::endl;
    *this = src;
}

NinjaTrap::NinjaTrap() : ClapTrap() {
    std::cout << "Default Ninja Constructor Called" << std::endl;
}

NinjaTrap::NinjaTrap(const std::string str) : ClapTrap(str) {
    std::cout << "String Ninja Constructor Called" << std::endl;
    this->HitPoint = 60;
    this->EnergyPoint = 120;
    this->MaxHitPoint = 60;
    this->MaxEnergyPoint = 120;
    this->level = 1;
    this->meleeAttackDamage = 60;
    this->rangedAttackDamage = 5;
    this->ArmorAttackReduction = 0;
}

NinjaTrap::~NinjaTrap() {
    std::cout << "Ninja Destructor Called" << std::endl;
}

void NinjaTrap::ninjaShoebox(const ClapTrap &clap)
{
    std::cout << "Hello, i'm a Clap (clap clap clap) !" << clap.getName() << std::endl;
}

void NinjaTrap::ninjaShoebox(const ScavTrap &ninja)
{
    std::cout << "Hello, i'm a Scav !" << ninja.getName()<< std::endl;
}

void NinjaTrap::ninjaShoebox(const FragTrap &frag)
{
    std::cout << "Hello, i'm a Frag !" << frag.getName() << std::endl; 
}

void NinjaTrap::ninjaShoebox(const NinjaTrap &scav)
{
    std::cout << "Niiiiiiiiinjaaaa !" << scav.getName() << std::endl;
    
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &rhs)
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