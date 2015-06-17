/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 14:36:41 by msarr             #+#    #+#             */
/*   Updated: 2015/06/17 14:36:41 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>

class Weapon
{
	public:
    	Weapon(std::string type);
	    ~Weapon(void);
	    void setType(std::string);
    	std::string const &	getType(void);
    private:
    	std::string type;
};

#endif