/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 13:06:11 by msarr             #+#    #+#             */
/*   Updated: 2015/06/20 13:06:14 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AWEAPON_H
#define AWEAPON_H

#include <iostream>

class AWeapon
{
	public:
    	AWeapon(const std::string &name, int apcost, int damage);
    	virtual ~AWeapon();
    	std::string getName() const;
    	
        void setName(std::string );
        void setAPcost(int);
        void setDamage(int);
        int getDamage() const;
        int getAPCost() const;
    	virtual void attack() const = 0;
	private:
    	std::string name;
        int APcost;
    	int damage;

    	AWeapon();
};

#endif