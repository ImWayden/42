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

class FragTrap {
	public:
    	FragTrap(FragTrap const &);
    	FragTrap(std::string const name);
    	FragTrap();
    	~FragTrap(void);
    	FragTrap &operator=(FragTrap const &rhs);
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
	private:
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