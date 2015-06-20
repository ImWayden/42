/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 13:06:45 by msarr             #+#    #+#             */
/*   Updated: 2015/06/20 13:06:47 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMA_RIFLE_H
#define PLASMA_RIFLE_H

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
	public:
    	PlasmaRifle();
    	~PlasmaRifle();
    	PlasmaRifle &operator=(PlasmaRifle const &rhs);
    	void attack() const;

};

#endif
