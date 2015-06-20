/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 13:09:18 by msarr             #+#    #+#             */
/*   Updated: 2015/06/20 13:09:20 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
	public:
    Character(const std::string &name);
    ~Character();

    void recoverAP();
    void equip(AWeapon *);
    int getAP(void) const;
    void attack(Enemy *);
    AWeapon *getWeapon() const;
    std::string getName() const;


    Character &operator=(Character const &rhs);   

private:
    std::string name;
    int AP;
    AWeapon *weapon;
};

std::ostream &operator<<(std::ostream &o, const Character &i);

#endif
