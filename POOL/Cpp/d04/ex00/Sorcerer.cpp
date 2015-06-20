/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 10:46:20 by msarr             #+#    #+#             */
/*   Updated: 2015/06/20 10:46:23 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"


Sorcerer::Sorcerer(std::string n, std::string t) : name(n), title(t)
{
	std::cout << this->name << ", " << this->title << ", is born !" << std::endl;
	return ;
}

Sorcerer::Sorcerer(Sorcerer const & rhs)
{
	*this = rhs;
	std::cout << this->name << ", " << this->title << ", is born !" << std::endl;
	return ;
}

Sorcerer::~Sorcerer()
{
	std::cout << this->name << ", " << this->title << ", is dead. Consequence will never be the same !" << std::endl;
	return ;
}

void	Sorcerer::polymorph(Victim const &src)
{
    src.getPolymorphed();
} 

Sorcerer &	Sorcerer::operator=(Sorcerer const &rhs)
{
	this->name = rhs.name;
	this->title = rhs.title;
	return (*this);
}

std::string	Sorcerer::getName() const
{
	return (this->name);
}

std::string	Sorcerer::getTitle() const
{
	return (this->title);
}

std::ostream &operator<<(std::ostream &o, Sorcerer const & s)
{
	o << "I am " << s.getName() << ", " << s.getTitle() << ", and I like ponies!" << std::endl;;
	return (o);
}