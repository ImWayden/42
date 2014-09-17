/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pnobs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 19:24:41 by sraccah           #+#    #+#             */
/*   Updated: 2014/04/14 19:35:30 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./includes/libft.h"

void			ft_print_pnobs(char *error)
{
	write(1, PURPLE, 7);
	write(1, error, ft_strlen((const char *)error));
	write(1, "\033[0m", 4);
}
