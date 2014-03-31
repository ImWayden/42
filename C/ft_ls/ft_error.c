/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:55:27 by msarr             #+#    #+#             */
/*   Updated: 2013/12/15 15:06:46 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsft.h"

void	ft_acceserror(char *str , char **argv, int argc)
{
	ft_putstr(str);
	ft_putstr(" : cannot access ");
	perror(argv[argc - 1]);
}
