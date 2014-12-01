/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 04:35:17 by sraccah           #+#    #+#             */
/*   Updated: 2014/02/24 22:29:13 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void		ft_print_error(char *error)
{
	write(2, "\033[0;31;1m", 9);
	write(2, error, ft_strlen((const char *)error));
	write(2, "\033[0m", 4);
	write(2, "\n", 1);
}

void		ft_is_not_found(char *cmd)
{
	write(2, "\033[0;31;1m", 9);
	write(2, "Ssh: command not found: ", 24);
	write(2, cmd, ft_strlen((const char *)cmd));
	write(2, "\033[0m", 4);
	write(2, "\n", 1);
}
