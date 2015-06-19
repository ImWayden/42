/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 14:20:19 by msarr             #+#    #+#             */
/*   Updated: 2015/06/19 14:20:21 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int        main(void)
{
    {
        FragTrap test = FragTrap("R2D2");

        std::cout << "FragTrap START ENERGY LEVEL : " << test.getEnergyPoint() << std::endl;
        test.vaulthunter_dot_exe("Grievous");
        test.takeDamage(25);
        test.vaulthunter_dot_exe("Grievous");
        test.takeDamage(25);
        std::cout << "FragTrap ENERGY LEVEL : " << test.getEnergyPoint() << std::endl;
        std::cout << "FragTrap HIT POINT : " << test.getHitPoint() << std::endl;
        test.beRepaired(12);
        std::cout << "FragTrap HIT POINT : " << test.getHitPoint() << std::endl;
    }
    {
        ScavTrap test = ScavTrap("Mozzie");

        std::cout << "FragTrap START ENERGY LEVEL : " << test.getEnergyPoint() << std::endl;
        test.challengeNewcomer("Grievous");
        test.takeDamage(25);
        test.challengeNewcomer("Grievous");
        test.takeDamage(25);
        std::cout << "FragTrap ENERGY LEVEL : " << test.getEnergyPoint() << std::endl;
        std::cout << "FragTrap HIT POINT : " << test.getHitPoint() << std::endl;
        test.beRepaired(12);
        std::cout << "FragTrap HIT POINT : " << test.getHitPoint() << std::endl;
    }

    return (0);
}
