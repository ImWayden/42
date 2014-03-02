/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_colours.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 16:52:57 by sraccah           #+#    #+#             */
/*   Updated: 2014/02/05 04:49:37 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void			ft_print_green(char *error)
{
	write(1, GREEN, 7);
	write(1, error, ft_strlen((const char *)error));
	write(1, "\033[0m", 4);
	write(1, "\n", 1);
}

void			ft_print_red(char *error)
{
	write(1, RED, 7);
	write(1, error, ft_strlen((const char *)error));
	write(1, "\033[0m", 4);
	write(1, "\n", 1);
}

void			ft_print_yellow(char *error)
{
	write(1, YELLOW, 7);
	write(1, error, ft_strlen((const char *)error));
	write(1, "\033[0m", 4);
	write(1, "\n", 1);
}

void			ft_print_bleue(char *error)
{
	write(1, CYAN, 7);
	write(1, error, ft_strlen((const char *)error));
	write(1, "\033[0m", 4);
	write(1, "\n", 1);
}

void			ft_print_purple(char *error)
{
	write(1, PURPLE, 7);
	write(1, error, ft_strlen((const char *)error));
	write(1, "\033[0m", 4);
	write(1, "\n", 1);
}
