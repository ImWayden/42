/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrimm <dgrimm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 17:46:32 by dgrimm            #+#    #+#             */
/*   Updated: 2015/06/21 17:46:35 by dgrimm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.class.hpp"

Window::Window( void )
{
    std::cout << "Initialisation de la fenetre !" << std::endl;
    if (initscr())
    {
        start_color();
		init_color(COLOR_YELLOW, 500, 400, 100);
        init_pair(1, COLOR_CYAN, COLOR_BLACK);
        init_pair(2, COLOR_BLUE, COLOR_BLACK);
        init_pair(3, COLOR_RED, COLOR_BLACK);
        init_pair(4, COLOR_GREEN, COLOR_BLACK);
        init_pair(5, COLOR_YELLOW, COLOR_BLACK);
        noecho();
        cbreak();
		timeout(50);
        keypad(stdscr, TRUE);
        bkgd(COLOR_PAIR(1));
        refresh();
        this->setSize();
        this->_win = newwin(this->_h , this->_w, 0, 0);
        box(this->_win, ACS_VLINE, ACS_HLINE);
        wrefresh(this->_win);
    }
    else
    {
        std::cout << "Game_2048: Initialisation failed." << std::endl;
        std::exit(0);
    }
}

Window::~Window()
{
    this->exit();
    std::cout << "Ncurses perfectly close" << std::endl;
}

void    Window::setSize()
{
    struct winsize  win;

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &win) != -1)
    {
        this->_w = win.ws_col;
        this->_h = win.ws_row;
    }
    else
    {
        std::cout << "Game_2048: Initialisation failed." << std::endl;
        std::exit(0);
    }
}

 WINDOW *    Window::getWin()
 {
    return (this->_win);
 }

int         Window::getWidh()
{
    return (this->_w);
}

int         Window::getHigh()
{
    return (this->_h);
}

void    Window::reSize()
{
    this->setSize();
    wresize(this->_win, this->_h, this->_w);
}

void    Window::exit()
{
    delwin(this->_win);
    endwin();
}
