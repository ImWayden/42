/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrimm <dgrimm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 17:46:49 by dgrimm            #+#    #+#             */
/*   Updated: 2015/06/21 17:46:53 by dgrimm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"
#include "Window.class.hpp"
#include "Character.class.hpp"

int			main(void)
{
	srand(time(NULL));
	time(NULL);
	Game game;
	game.play();
	return (0);
}
