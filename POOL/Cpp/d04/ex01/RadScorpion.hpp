/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 13:08:55 by msarr             #+#    #+#             */
/*   Updated: 2015/06/20 13:08:57 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAD_SCORPION_H
#define RAD_SCORPION_H

#include "Enemy.hpp"

class RadScorpion : public Enemy
{
	public:
    	RadScorpion();
    	~RadScorpion();

    	RadScorpion &operator=(RadScorpion const &rhs);
};

#endif


