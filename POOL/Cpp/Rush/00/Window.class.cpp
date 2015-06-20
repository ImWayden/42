/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:43:26 by msarr             #+#    #+#             */
/*   Updated: 2015/06/20 15:43:30 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.class.hpp"

Window::Window()
{
    std::cout << "Initialisation de la fenetre !" << std::endl;
    if (initscr())
    {
        start_color();
        init_pair(1, COLOR_CYAN, COLOR_BLACK);
        init_pair(2, COLOR_BLUE, COLOR_BLACK);
        init_pair(3, COLOR_RED, COLOR_BLACK);
        init_pair(4, COLOR_GREEN, COLOR_BLACK);
        noecho();
        cbreak();
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

Window::Window(Window &)
{
}

Window::~Window()
{
    this->exit();
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
