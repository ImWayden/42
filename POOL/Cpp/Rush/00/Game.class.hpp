/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 17:31:12 by msarr             #+#    #+#             */
/*   Updated: 2015/06/20 17:31:14 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CLASS_H
# define GAME_CLASS_H
#include "Window.class.hpp"

class 	Game
{
	public:
		Game();
		~Game();

		void	play();
		void	setY();


	private:
		//Charater	_tabChar[10];
		int			_score;
		int			_x;
		int			_y;
		Window		*_w;
		void		display();

	
};
#endif