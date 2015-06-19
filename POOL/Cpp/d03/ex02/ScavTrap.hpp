/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 12:49:18 by msarr             #+#    #+#             */
/*   Updated: 2015/06/19 12:49:18 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_H
#define SCAV_TRAP_H

#include <iostream>
#include <cstdlib>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
	    ScavTrap(ScavTrap const &);
	    ScavTrap();
	    ScavTrap(std::string const name);
	    ~ScavTrap(void);
	    ScavTrap &operator=(ScavTrap const &rhs);
    	void challengeNewcomer(std::string const &target) const;
};

#endif