
#ifndef BACKGROUND_CLASS_HPP
# define BACKGROUND_CLASS_HPP
#include <iostream>
#include <curses.h>

class Background
{
public:
    Background(int    x_max, int y_max);
    ~Background( void );
    void    move( void );
    void    ini( void );

private:
    unsigned int	    pos_x;
    int                *tabx;
    int                *taby;
    int                xmax;
	Background( void );
	Background  & operator=( Background const & rhs );
    Background( Background const & src );
};
#endif
