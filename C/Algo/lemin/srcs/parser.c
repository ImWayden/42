/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/12/02 02:28:36 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int			is_comment(char *str)
{
	if (str && str[0] == '#' && str[1] != '#')
		return (1);
	return (0);
}

static int		get(t_lem **lem)
{
	int 		i;
	char		*str;

	str = NULL;
	get_next_line(0, &str);
	ft_putendl(str);
	i = ft_atoi(str);
	if (i)
	{
		*lem = (t_lem *)malloc(sizeof(t_lem));
		(*lem)->nbr = i;
		(*lem)->start = NULL;
		ft_bzero((*lem)->tab, 1000);
		return (1);
	}
	return (0);
}

int					hash(char *str)
{
	int				code;
	int				len;
	int				i;

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

t_lem				*parse(void)
{
	t_lem		*lem;
	char		*str;

	lem = NULL;
	str = NULL;
	get(&lem);
	while (get_next_line(0, &str))
	{
		ft_putendl(str);
		if (!ft_strcmp(str, "##start"))
			get_door(lem, 1);
		else if (!ft_strcmp(str, "##end"))
			get_door(lem, 2);
		else if (is_comment(str))
			continue ;
		else if (ft_strchr(str, ' '))
			get_room(str, lem, 0);
		else if (ft_strchr(str, '-'))
			add_link(str, lem);
		else
			return (NULL);
	}
	return (lem);
}
