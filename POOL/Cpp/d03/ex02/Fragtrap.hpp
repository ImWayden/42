/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fragtrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 11:52:11 by msarr             #+#    #+#             */
/*   Updated: 2015/06/19 11:52:11 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_H
#define FRAG_TRAP_H

#include <iostream>
#include <cstdlib>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
        FragTrap(void);
    	FragTrap(FragTrap const &);
    	FragTrap(std::string const name);
    	~FragTrap(void);
        void vaulthunter_dot_exe(const std::string &target);
        FragTrap & operator=(FragTrap const &rhs);
};

#endif