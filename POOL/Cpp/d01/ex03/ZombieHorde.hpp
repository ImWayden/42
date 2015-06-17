/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 12:44:56 by msarr             #+#    #+#             */
/*   Updated: 2015/06/17 12:44:56 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HORDE_H
# define ZOMBIE_HORDE_H

#include <cstdlib>
#include <iostream>
#include "Zombie.hpp"


class ZombieHorde
{
	public:
	    ZombieHorde(int N);
	    ~ZombieHorde(void);
	    void announce();
	    Zombie *horde;
	private:
    	void createZombie(int N);
	    int numberOfZombie;
};

#endif