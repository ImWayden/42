/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:24:33 by msarr             #+#    #+#             */
/*   Updated: 2015/06/16 16:24:36 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>

void Pony::speak(void) {
    std::cout << "Hello i'm a Poney, my color is " << this->color << " and my name is " << this->name << std::endl;
}

Pony::Pony(void) {
    std::cout << "A pony is born" << std::endl;

}

Pony::~Pony(void) {
    std::cout << "A pony die" << std::endl;

}

void Pony::setColor(std::string color) {
    this->color = color;

}

void Pony::setName(std::string name) {
    this->name = name;
}
