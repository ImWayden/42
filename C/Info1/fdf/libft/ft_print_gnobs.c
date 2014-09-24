/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_gnobs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 19:24:10 by sraccah           #+#    #+#             */
/*   Updated: 2014/04/14 19:35:18 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./includes/libft.h"

void			ft_print_gnobs(char *error)
{
	write(1, GREEN, 7);
	write(1, error, ft_strlen((const char *)error));
	write(1, "\033[0m", 4);
}
