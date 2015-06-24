/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrimm <dgrimm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 17:46:07 by dgrimm            #+#    #+#             */
/*   Updated: 2015/06/21 17:46:10 by dgrimm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"
#include "Character.class.hpp"
#include "Background.class.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <fstream>


Game::Game() : _score(0), _x(1), _hp(5) {
	this->_w = new Window;
	this->setY();
	this->_score = 0;
	this->_x = 0;
	this->_time = time(NULL);
}

Game::~Game()
{
	if ( this->_win == 0 ) 
		std::cout << "THANKS BUT U LOOSE !" << std::endl;
	else
		std::cout << "WELL DONE YOU ARE IN MY BOOK !" << std::endl;
	endwin();
	
	std::string x;
	std::cout << "Please enter your name " << std::endl;
	std::cin >> x;
	std::string ret = "score";
	std::ofstream recup;
	recup.open("score", std::ofstream::out | std::ofstream::app);
	recup << x << " Your score is " << this->_score << "  your time : " << time(NULL) - this->_time<< std::endl;
	recup.close();
}

void	Game::setY()
{
	this->_y = this->_w->getHigh() / 2;
}

int		Game::getHP(void) const {
	return this->_hp;
}

int		Game::getScore(void) const {
	return this->_hp;
}

int	Game::pause( void ) const {
	int key;

	key = getch();
	if (key == '0')
		return 1;
	return -1;

}

Character		&Character::operator=(Character const &src)
{
	this->_hp  = src.getHp();
	return *this;
}

void	Game::play()
{
	int	key;
	int new_x;
	int new_y;
	int i;
	int r;
	Character	horde[30];
	int size;
	int j;
	int tmp;
	std::ostringstream scor;
	std::string ScorT;
	static int test_clear = 0;

	size = 30;

	getmaxyx(stdscr, new_y, new_x);
	Background backG(new_x, new_y);
	Character	boss("BOSS", 10000, (new_x - 30), ((new_y / 2 ) - 10));
	Character	*missile = new Character[new_x - 3];
	Character	*missile2 = new Character[new_x - 3];
	this->_win = 0;
	this->_posy = new_y /2;
	curs_set(0);
	this->_posy = _y / 2;
	this->_posx = 2;
	i = 0;
	while ( i < new_x - 3)
	{
		missile[i].setX(-1);
		i++;
	}
	while ( i < new_x - 3)
	{
		missile2[i].setX(-1);
		i++;
	}
	i = 0;
	tmp = horde[i].getX();
	while ( i <= size - 1)
	{
		r = rand() % new_y - 2;
		if (r < 1)
			r = 2;
		horde[i].setY(r);
		horde[i].setX(new_x - 10);
		horde[i].setToPrint(0);
		i++;
	}
		horde[0].setToPrint(1);
		j = 0;
		tmp = 1;
	while (1)
	{
		getmaxyx(stdscr, new_y, new_x);
		if ( this->_x != new_x || this->_y != new_y ) {
			if (new_x < 20 || new_y < 30 )
				return ;
			erase();
			border(':', ':', '_', '_', '+', '+', '+', '+');
			border(':', ':', '_', '_', '+', '+', '+', '+');
			this->_x = new_x;
			this->_y = new_y;
			this->_posy = _y / 2;
			this->_posx = 2;
			mvprintw( this->_posy, this->_posx, ">" );
		}	
		mvprintw( this->_posy, this->_posx, ">" );
		backG.move();
		i = 0;
		j++;
		while(i < new_x - 3)
		{
			if (missile[i].getX() != -1)
			{
				if (missile[i].getX() > new_x)
					missile[i].setX(-1);
				else
					missile[i].rightX();
			}
			if (missile2[i].getX() != -1)
			{
				if (missile2[i].getX() < 0)
					missile2[i].setX(-1);
				else
					missile2[i].leftX();
			}
			i++;
		}
		i = 0;
		scor << "Your Score is: ";
		scor << this->_score;
		scor << " life a maining: ";
		scor << this->_hp;
		scor << " time: ";
		scor << (float)(time(NULL) - this->_time);
		scor << " second ";
		ScorT = scor.str();
		mvprintw(0, 0, ScorT.c_str());
		scor.str("");
		if (this->_score < 400)
			while (i < 30)
			{
				this->_score += horde[i].coll(missile,  new_x - 3);
				if ((horde[i].getX() == this->_posx && horde[i].getY() == this->_posy && horde[i].getHp() > 0))
				{
					this->_hp--;
					if (this->_hp <= 0)
					{
						endwin();
						delete [] missile;
						delete this->_w;
						return;
					}
				}
				if ( horde[i].getX() <= 1 || horde[i].getHp() == 0 )
				{
					if (horde[i].getX() <= 1)
						this->_score -= 10;
					r = rand() % new_y - 2;
					if (r == 0)
						r = new_y - 1;
					horde[i].setY(r);
					horde[i].setX(new_x - 10);
				}
				if (horde[i].getToPrint() == 1)
				{
					horde[i].coll(missile, new_x - 3);
					horde[i].affChar();
					horde[i].lowX();
				}
				if (horde[i].getToPrint() == 0 && j == 20)
				{
					horde[i].setToPrint(1);
					j = 0;
				}
				i++;
			}
		else if (test_clear == 0) {
			clear();
			test_clear++;
			clear();
		}
		else {
			int jjj = 0;
			while (jjj < new_x -3)
			{
				if (missile2[jjj].getX() == this->_posx && missile2[jjj].getY() == this->_posy)
				{
					endwin();
					delete [] missile2;
					delete this->_w;
					return;
				}
				jjj++;
			}
			boss.affBoss();
			boss.collBoss(missile, new_x-3);
			if (boss.getHp() < 0)
			{
				this->_win = 1;
				endwin();
				delete [] missile2;
				delete this->_w;
				return;
			}
			if (boss.getY() >= new_y - 14)
				tmp = -1;
			else if (boss.getY() < 2)
				tmp = 1;
			boss.setY(boss.getY() + tmp);

		}
		getmaxyx(stdscr, new_y, new_x);
		if ( this->_x != new_x || this->_y != new_y ) {
			erase();
			border(':', ':', '_', '_', '+', '+', '+', '+');
			border(':', ':', '_', '_', '+', '+', '+', '+');
			this->_x = new_x;
			this->_y = new_y;
			this->_posy = _y / 2;
			this->_posx = 2;
			mvprintw( this->_posy, this->_posx, ">" );
		}	
		mvprintw( this->_posy, this->_posx, ">" );
		key = getch();
		if ( key == KEY_UP )
		{
			if ( this->_posy > 1 ) {
				this->_posy = this->_posy - 1;
			}
				mvprintw(this->_posy + 1, this->_posx, " ");
				mvprintw(this->_posy, this->_posx, ">");
		}
		else if ( key == KEY_LEFT )
			;
		else if ( key == '0' )
			while (pause() != 1)
				;
		else if ( key == ' ' )
		{
			write (1, "\a", 1);
			int jj = 0;
			while (jj < new_x - 3)
			{
				
				if (missile[jj].getX() == -1 && missile[jj].getX() == -1)
				{
					missile[jj].setX(this->_posx + 1);
					missile[jj].setY(this->_posy);
					if (this->_score >= 400) {
						missile2[jj].setX(boss.getX() - 1);
						missile2[jj].setY(boss.getY() + 5);
					}			
					break;
			
				}
				jj++;
				border(':', ':', '_', '_', '+', '+', '+', '+');
			}
		}
		else if ( key == KEY_DOWN )
		{
			if ( this->_posy < _y - 2 )
			{
				this->_posy = this->_posy + 1;
				mvprintw(this->_posy - 1, this->_posx, " ");
				mvprintw(this->_posy, this->_posx, ">");
	 		}
		}
		else if ( key == 27 ) {
			delete [] missile;
			delete this->_w;
			std::exit(0);
		}

	}
}
