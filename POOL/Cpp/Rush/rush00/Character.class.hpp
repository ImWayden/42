#ifndef CHARACTER_H
# define CHARACTER_H

#include <iostream>
#include "Game.class.hpp"


class Character {

public:
	Character(std::string name , int hp, int x, int y);
	~Character( void );
	Character( void );

	int getHp( void ) const;
	int getX( void ) const;
	int getY( void ) const;
	int getToPrint(void) const;
	std::string getName( void ) const;

	void setX( int x );
	void setToPrint(int n);	
	void setY( int Y );

	void affBoss(void);
	void affChar(void) const;
	void lowX(void); 
	void upX(void);
	void rightX(void);
	void leftX(void);
	int	 coll(Character *missile, int max);
	void collBoss(Character *missile, int max);
	Character & operator=(Character const & rhs );

private:
	Character( Character const & src );
	std::string _name;
	int _hp;
	int _x;
	int _y;
	int _special;
	int _toPrint;
};

std::ostream & operator<<( std::ostream & o, Character const & i);

#endif
