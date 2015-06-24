/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrimm <dgrimm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 17:45:57 by dgrimm            #+#    #+#             */
/*   Updated: 2015/06/21 17:46:00 by dgrimm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.class.hpp"

Character::Character( std::string name, int hp, int x, int y) : _name(name), _hp(hp), _x(x), _y(y) {

	return ;
}

Character::~Character( void ) {
	return ;
}
/*******************************   GET  ****************************************/

int			Character::getHp( void ) const {
	return this->_hp;
}

int			Character::getX( void ) const {
	return this->_x;
}

int			Character::getY( void ) const {
	return this->_y;
}

std::string	Character::getName( void ) const {
	return this->_name;
}

int			Character::getToPrint(void) const {
	return this->_toPrint;
}

/*************************************  SET    *************************************/

void	Character::setX( int x ) {
	_x= x;
}


void	Character::setY( int y ) {
	_y = y;
}

void	Character::setToPrint(int n) {
	_toPrint = n;
}


/************************************   Fonction  *******************************/


std::ostream & operator<<(std::ostream & o, Character const & i) {
	o << "afichage: " << i.getName() << " hp: " << i.getHp() << " x " << i.getX() << " y " << i.getY();
	return o;
}

/***/

void		Character::affChar(void) const {


	mvprintw(this->_y, this->_x , "     ");
	refresh();
	if (this->_x > 2 && this->_hp > 0)
	{
		attron(COLOR_PAIR(this->_special));
		if (this->_special == 1)
			mvprintw(this->_y, this->_x, "_~0");
		else if (this->_special == 2)
			mvprintw(this->_y, this->_x, "<@>");
		else
			mvprintw(this->_y, this->_x, "[-]");
		attroff(COLOR_PAIR(this->_special));
	}
	refresh();
}

void		Character::affBoss(void) {

	mvprintw(this->_y + 0, this->_x, "                            ");
	mvprintw(this->_y + 1, this->_x, "#**************************#");
	mvprintw(this->_y + 2, this->_x, "#                          #");
	mvprintw(this->_y + 3, this->_x, "#        :::      :::::::: #");
	mvprintw(this->_y + 4, this->_x, "#      :+:      :+:    :+: #");
	mvprintw(this->_y + 5, this->_x, "#    +:+ +:+         +:+   #");
	mvprintw(this->_y + 6, this->_x, "#  +#+  +:+       +#+      #");
	mvprintw(this->_y + 7, this->_x, "# +#+#+#+#+#+   +#+        #");
	mvprintw(this->_y + 8, this->_x, "#     #+#    #+#           #");
	mvprintw(this->_y + 9, this->_x, "#    ###   ########        #");
	mvprintw(this->_y + 10, this->_x, "#                          #");
	mvprintw(this->_y + 11, this->_x, "#**************************#");
	mvprintw(this->_y + 12, this->_x, "                            ");
} 

Character::Character(void) : _name("<->"), _hp(0), _x(0), _y(0), _toPrint(0) {
	int r;

	r = 1 + rand() % 3;
	this->_special = r;
	this->_hp = this->_special;
	return;
}

void		Character::lowX(void)
{
		this->_x -= 1;

}

void		Character::rightX(void)
{
	mvprintw(this->_y, this->_x , " ");
	this->_x += 1;
	mvprintw(this->_y, this->_x , "-");
	refresh();
}

void		Character::leftX(void)
{
	mvprintw(this->_y, this->_x , " ");
	this->_x -= 1;
	mvprintw(this->_y, this->_x , "-");
	refresh();
} 
void		Character::upX(void)
{
	    this->_x += 1;
}

int		Character::coll(Character *missile, int	max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		if (this->getToPrint() == 1)
		{
			if (missile[i].getY() == this->_y)
			{
				if (missile[i].getX() == this->_x + 1 || missile[i].getX() == this->_x)
				{
					this->_hp -= 1;
					mvprintw(this->_y, this->_x, "    ");
					if (this->_hp == 0)
						return (50);
					else
						return (15);
					missile[i].setX(-1);
				}
			}
		}
		i++;
	}
	return (0);
}

void		Character::collBoss(Character *missile, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		if ((missile[i].getY() >= (this->_y )) && (missile[i].getY() <= (this->_y + 11)))
		{
			if (missile[i].getX() >= (this->_x))
			{
				this->_hp -= 75;
				missile[i].setX(-1);
			}
		}
		i++;
	}
}
