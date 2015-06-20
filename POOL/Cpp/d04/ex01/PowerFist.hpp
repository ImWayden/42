/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 13:07:12 by msarr             #+#    #+#             */
/*   Updated: 2015/06/20 13:07:14 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWER_FIST_H
#define POWER_FIST_H

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
	public:
    	PowerFist();
    	~PowerFist();
    	PowerFist &operator=(PowerFist const &rhs);
    	void attack() const;
};

#endif
