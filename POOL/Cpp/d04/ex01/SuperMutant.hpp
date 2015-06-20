/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 13:08:27 by msarr             #+#    #+#             */
/*   Updated: 2015/06/20 13:08:29 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_H
#define SUPERMUTANT_H

#include "Enemy.hpp"

class SuperMutant : public Enemy
{
	public:
		SuperMutant();
		~SuperMutant();
		SuperMutant &operator=(SuperMutant const &rhs);
		void takeDamage(int amount);
};

#endif
