/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 13:32:32 by msarr             #+#    #+#             */
/*   Updated: 2015/06/19 13:32:35 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_TRAP_H
# define CLASS_TRAP_H

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(ClapTrap const &);
		ClapTrap(std::string const name);
		~ClapTrap(void);
		ClapTrap & operator=(ClapTrap const &rhs);
    	void rangedAttack(std::string const &target);
    	void meleeAttack(std::string const &target);
    	void takeDamage(unsigned int amount);
    	void beRepaired(unsigned int amount);
    	int getArmorAttackReduction() const;;
    	int getRangedAttackDamage() const;
    	int getMeleeAttackDamage() const;
    	std::string getName() const;
   		int getLevel() const;
    	int getMaxEnergyPoint() const;
    	int getEnergyPoint() const;
    	int getMaxHitPoint() const;
    	int getHitPoint() const;
	    void vaulthunter_dot_exe(const std::string &target);
	protected:
    	int HitPoint;
    	int MaxHitPoint;
    	int EnergyPoint;
    	int MaxEnergyPoint;
    	int level;
    	std::string name;
    	int meleeAttackDamage;
    	int rangedAttackDamage;
    	int ArmorAttackReduction;
	
};

#endif