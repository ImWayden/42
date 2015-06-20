/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 13:07:52 by msarr             #+#    #+#             */
/*   Updated: 2015/06/20 13:07:54 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const &type) : hp(hp), type(type)
{
}

Enemy::~Enemy()
{
}

void Enemy::takeDamage(int amount)
{
    if (amount > 0)
        this->hp -= amount;
}

void Enemy::setHP(int amount)
{
    this->hp = amount;
}

int Enemy::getHP() const
{
    return this->hp;
}

std::string Enemy::getType() const
{
    return this->type;
}

Enemy &Enemy::operator=(Enemy const &rhs)
{
    this->hp = rhs.getHP();
    this->type = rhs.getType();
    return *this;
}