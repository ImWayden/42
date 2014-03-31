/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_colours2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 02:36:37 by sraccah           #+#    #+#             */
/*   Updated: 2014/02/05 04:49:43 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void			ft_print_rnobs(char *error)
{
	write(1, RED, 7);
	write(1, error, ft_strlen((const char *)error));
	write(1, "\033[0m", 4);
}

void			ft_print_bnobs(char *error)
{
	write(1, CYAN, 7);
	write(1, error, ft_strlen((const char *)error));
	write(1, "\033[0m", 4);
}

void			ft_print_pnobs(char *error)
{
	write(1, PURPLE, 7);
	write(1, error, ft_strlen((const char *)error));
	write(1, "\033[0m", 4);
}

void			ft_print_ynobs(char *error)
{
	write(1, YELLOW, 7);
	write(1, error, ft_strlen((const char *)error));
	write(1, "\033[0m", 4);
}

void			ft_print_gnobs(char *error)
{
	write(1, GREEN, 7);
	write(1, error, ft_strlen((const char *)error));
	write(1, "\033[0m", 4);
}
