/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 14:31:13 by msarr             #+#    #+#             */
/*   Updated: 2015/06/17 14:31:13 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_H
# define HUMAN_A_H

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:
	    void attack();
	    HumanA(std::string name, Weapon &weapon);
	    ~HumanA(void);
	private:
    	std::string name;
    	Weapon &weapon;
};

#endif