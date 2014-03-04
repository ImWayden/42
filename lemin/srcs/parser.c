/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/03/04 02:14:47 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin!.h"

int			hashcode(char *str)
{
	int		code;
	int		len;
	int		i;

	len = ft_strlen(str);
	code = 7;
	i = 0;
	while (i < len)
	{
		code = str[i] + 31 * code;
		i++;
	}
	return (code % 1000);
}

char				**parse()
{
	s_lemlist		*tab[1000];
	int				i;
	char			*str = NULL;

	i = 0;
	while (getnextline(0, &str))
	{
		ft_putstr(str);
		if (!i)
			j = ft_itoa(str);
		else if (!ft_strcmp(str, "##start"))
			i = 1;
		else if (ft_strcmp(str, "##start"))
			i = 2;
		else if (i)
		{
			tab[hashcode(ft_strplit(str, ' '))]
		}
	}
}