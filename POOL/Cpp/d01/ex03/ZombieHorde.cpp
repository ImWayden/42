/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 12:41:16 by msarr             #+#    #+#             */
/*   Updated: 2015/06/17 12:41:16 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N)
{
    std::cout << "ZombieHorde constuctor" << std::endl;
    this->createZombie(N);
}

ZombieHorde::~ZombieHorde()
{
    delete[] this->horde;
    std::cout << "ZombieHorde destructor" << std::endl;
}

void ZombieHorde::announce()
{
    int i = -1;

    while (++i < this->numberOfZombie)
        this->horde[i].announce();
}

void ZombieHorde::createZombie(int N)
{
    Zombie *horde = new Zombie[N];
    this->horde = horde;
    this->numberOfZombie = N;
    int i = -1;
    int random;
    std::string arrayRand[7];
    std::srand(time(NULL));

    arrayRand[0] = "John";
    arrayRand[1] = "Frank";
    arrayRand[2] = "Anthony";
    arrayRand[3] = "Gertrude";
    arrayRand[4] = "Salut";
    arrayRand[5] = "42";
    arrayRand[6] = "84";

    while (++i < N)
    {
        random = std::rand();
        this->horde[i].setName(arrayRand[random % 6]);
        this->horde[i].setType("TypeRandom");
    }
    this->announce();
}