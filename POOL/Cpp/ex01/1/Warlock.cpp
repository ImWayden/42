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

Warlock::Warlock(std::string name) : name(name)
{
	std::cout << name << ": This looks lke another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << name << ": Ahh, I see it clearly. This is the plane SUCK.." << std::endl;
}


std::string	Warlock::getName() const
{
	return (name);
}

void	Warlock::addTitle(std::string const & title)
{
	titles.push_back(title);
}

void	Warlock::removeTitle(std::string const & title)
{
	titles.remove(title);
}

void	Warlock::addQuote(std::string const & quote)
{
	this->quotes.push_back(quote);
}

void	Warlock::removeQuote(std::string const & quote)
{
	std::vector<std::string>::const_iterator it;

	if ((it = std::find(quotes.begin(), quotes.end(), quote)) != quotes.end())
	{
		std::cout << "<" << name << "> :  erasing : " << "<" << *it << ">" << std::endl;
		quotes.erase(it);
	}
}

void	Warlock::talk(void)
{
	if (quotes.size())
	{
		unsigned int it = std::rand() % quotes.size();
		std::cout << "<" << name << "> : " << "<" << quotes[it] << ">" << std::endl;
	} 
}

void	Warlock::introduce(void) const
{
	std::cout << name << ": I am <" << name << ">";
	std::list<std::string>::const_iterator it = titles.begin();
	while (it != titles.end())
	{
		std::cout << "<" << *it << ">, ";
		it++;
	}
//	for (it = titles.begin(); it != titles.end(); ++it;)
//		std::cout << "<" << *it << ">, ";
	std::cout << " ! And the mayor of a little village on the coast. Very scenic during springtime, you should visit sometime !" << std::endl;
}
