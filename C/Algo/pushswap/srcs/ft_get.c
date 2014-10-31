/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 15:53:49 by msarr             #+#    #+#             */
/*   Updated: 2013/12/24 15:53:54 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static t_lex	*ft_listnew(int nbr)
{
	t_lex		*list;

	if ((list = (t_lex *)malloc(sizeof(t_lex))))
	{
		list->nbr = nbr;
		list->next = list;
		list->prev = list;
	}
	return (list);
}

static t_lex	*ft_addlist(t_lex *list, int nbr)
{
	t_lex		*tmp;

	tmp = ft_listnew(nbr);
	if (!list)
		return (tmp);
	else
	{
		tmp->prev = list->prev;
		list->prev->next = tmp;
		tmp->next = list;
		list->prev = tmp;
	}
	return (list);
}
static int		ft_isnumeric(char *str)
{
	int			i;

	i = 0;
	if (str && (str[0] == '-' || str[0] == '+'))
		i++;
	while (str && str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

t_lex			*ft_get(char **argv)
{
	t_lex		*list;
	int			i;

	i = 0;
	list = NULL;
	while (argv[i])
	{
		if (ft_isnumeric(argv[i]))
			list = ft_addlist(list, ft_atoi(argv[i]));
		else
		{
			ft_putendl("ERROR");
			return (NULL);
		}
		i++;
	}
	return (list);
}
