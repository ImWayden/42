/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 13:00:10 by msarr             #+#    #+#             */
/*   Updated: 2015/06/17 13:00:10 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>
#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain Constructor called" << std::endl;
}

Brain::~Brain(void)
{
    std::cout << "Brain Destructor called" << std::endl;
}

std::string Brain::identify()
{

    std::string str;
    std::ostringstream convert;
    convert << this;
    str = convert.str();
    return str;
}