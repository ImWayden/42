/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 10:46:11 by msarr             #+#    #+#             */
/*   Updated: 2015/06/20 10:46:13 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SORCERER_H
# define SORCERER_H

#include <iostream>
#include "Victim.hpp"

class Sorcerer
{
	public:	
		Sorcerer(Sorcerer const &);
		Sorcerer(std::string s, std::string t);
		~Sorcerer();
		Sorcerer  &operator=(Sorcerer const &);

		std::string getName() const;
		std::string getTitle() const;
		void polymorph(Victim const &); 
		
	private:
		Sorcerer();

		std::string	name;
		std::string	title;
	
};

std::ostream &operator<<(std::ostream &o, Sorcerer const &s);


#endif