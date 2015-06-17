/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 14:34:46 by msarr             #+#    #+#             */
/*   Updated: 2015/06/17 14:34:46 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->type = type;
//    std::cout << "weapon constructor" << std::endl;
    return;
}

Weapon::~Weapon(void)
{
//    std::cout << "weapon destructor" << std::endl;
    return;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}

const std::string &Weapon::getType()
{
    std::string const & type = this->type;
    return type;
}