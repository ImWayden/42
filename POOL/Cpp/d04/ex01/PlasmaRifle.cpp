/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 13:06:36 by msarr             #+#    #+#             */
/*   Updated: 2015/06/20 13:06:38 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::~PlasmaRifle()
{
}

void PlasmaRifle::attack() const
{
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}

PlasmaRifle &PlasmaRifle::operator=(PlasmaRifle const &rhs)
{
    this->setName(rhs.getName());
    this->setDamage(rhs.getDamage());
    this->setAPcost(rhs.getAPCost());
    return *this;
}
