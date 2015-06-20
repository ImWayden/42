/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 13:07:21 by msarr             #+#    #+#             */
/*   Updated: 2015/06/20 13:07:23 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{
}

PowerFist::~PowerFist()
{
}

void PowerFist::attack() const
{
    std::cout << "* pschhh... SBAM! *" << std::endl;
}

PowerFist &PowerFist::operator=(PowerFist const &rhs)
{
    this->setName(rhs.getName());
    this->setDamage(rhs.getDamage());
    this->setAPcost(rhs.getAPCost());
    return *this;
}
