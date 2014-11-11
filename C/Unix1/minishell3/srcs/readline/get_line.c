/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 14:52:29 by msarr             #+#    #+#             */
/*   Updated: 2014/10/13 23:04:12 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getline.h"

char						*get_line(void)
{
	struct termios			term;
	int						i;
	char					*str;

	str = ft_strnew(255);
	while (ft_strlen(str) < 255)
	{
		if (ft_init(&term))
		{
			if (ft_config(&term))
				break ;
			ft_term(&str);
			if (ft_defconfig(&term))
				exit (0);
			return (str);
		}
		get_next_line(1, &sstr);
	}
	return (str);
}
