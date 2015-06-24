/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Background.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrimm <dgrimm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 17:45:42 by dgrimm            #+#    #+#             */
/*   Updated: 2015/06/21 17:45:48 by dgrimm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Background.class.hpp"

Background::Background(int x_max, int y_max)
{
	this->tabx = new int[50];
	this->taby = new int[50];
	int i;
	i = 0;
	while (i < 50)
	{
		this->tabx[i] = rand() % x_max;
		this->taby[i] = rand() % y_max;
		i++;
	}
	this->xmax = x_max;
};

Background::~Background( void ){
};

void    Background::move( void )
{

	int i;
	i = 0;
	std::string str = "5";
	attron(COLOR_PAIR(5));
	while (i < 50)
	{
		mvprintw(this->taby[i], this->tabx[i], " ");
		this->tabx[i] = this->tabx[i] - 2;
		if (this->tabx[i] <= 0)
			this->tabx[i] = xmax;
		mvprintw(this->taby[i], this->tabx[i], "*");
		i++;
	}
	attroff(COLOR_PAIR(5));
}
