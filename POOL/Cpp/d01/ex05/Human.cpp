/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 13:04:15 by msarr             #+#    #+#             */
/*   Updated: 2015/06/17 13:04:15 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Human.hpp"
#include "Brain.hpp"

Human::Human(void) : brain(*(new Brain))
{
    std::cout << "Human Constructor called" << std::endl;
}

Human::~Human(void) {

    std::cout << "Human Destructor called" << std::endl;
}

std::string Human::identify() {
    return this->getBrain().identify();

}
Brain &Human::getBrain() {
    return (Brain &) this->brain;
}