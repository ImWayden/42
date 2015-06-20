/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 13:05:47 by msarr             #+#    #+#             */
/*   Updated: 2015/06/20 13:05:50 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage) : name(name), APcost(apcost), damage(damage)
{

}

AWeapon::~AWeapon()
{
}

std::string AWeapon::getName() const
{
    return this->name;
}

int AWeapon::getDamage() const
{
    return this->damage;
}

int AWeapon::getAPCost() const
{
    return this->APcost;
}

void AWeapon::setName(std::string str)
{
	this->name = str;
}

void AWeapon::setDamage(int damage)
{
	this->damage = damage;
}

void AWeapon::setAPcost(int ap)
{
	this->APcost = ap;
}
