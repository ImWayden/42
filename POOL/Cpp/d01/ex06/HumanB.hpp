/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 14:32:19 by msarr             #+#    #+#             */
/*   Updated: 2015/06/17 14:32:19 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_H
# define HUMAN_B_H

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
	    HumanB(std::string name);
	    ~HumanB(void);
	    void attack();
	    void setWeapon(Weapon &weapon);
	private:
    	std::string name;
    	Weapon *weapon;
};

#endif