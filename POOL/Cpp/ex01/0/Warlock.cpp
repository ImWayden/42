/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 13:35:11 by msarr             #+#    #+#             */
/*   Updated: 2015/06/26 13:35:13 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) : name(name), title(title)
{
	std::cout << name << ": This looks lke another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << name << ": Ahh, I see it clearly. This is the plane SUCK.." << std::endl;
}

std::string	Warlock::getTitle() const
{
	return (title);
}

std::string	Warlock::getName() const
{
	return (name);
}

void	Warlock::introduce(void) const
{
	std::cout << name << ": I am <" << name << ">" "<" << title << "> !" << std::endl;
}

void	Warlock::setTitle(std::string title)
{
	this->title = title;
}