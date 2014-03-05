/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/03/04 16:55:14 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

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

t_lem				*parse()
{
	t_lem			*pars;
	int				i;
	char			*str = NULL;

	i = 0;
	pars = (t_lem *)malloc(sizeof(t_lem));
	while (getnextline(0, &str))
	{
		ft_putendl(str);
		if (!i)
		{
			pars->j = ft_atoi(str);
			i = 3;
		}
		else if (!ft_strcmp(str, "##start"))
			i = 1;
		else if (!ft_strcmp(str, "##end"))
			i = 2;
		else if (i && *str != '#')
		{
			if (i == 1)
				pars->start = (ft_strsplit(str, ' ')[0]);
			if (i == 2)
				pars->end = (ft_strsplit(str, ' '))[0];
			if (i == 1 || i == 2)
				i = 3;
			if (ft_is(str, '-'))
			{
				pars->tab[hashcode((ft_strsplit(str, '-'))[0])]
				= ft_addlemlist(pars->tab[hashcode((ft_strsplit(str, '-'))[0])]
				, (ft_strsplit(str, '-'))[1]);
				pars->tab[hashcode((ft_strsplit(str, '-'))[1])]
				= ft_addlemlist(pars->tab[hashcode((ft_strsplit(str, '-'))[1])]
				, (ft_strsplit(str, '-'))[0]);
			}
			else
			{
				pars->tab[hashcode((ft_strsplit(str, ' '))[0])] = ft_lemlistnew(NULL);
				pars->list = ft_addlemlist(pars->list, (ft_strsplit(str, ' '))[0]);
			}
			free(str);
		}
	}
	return (pars);
}

void		dist(t_lem *lem, char *end, int i)
{
	t_lemlist	*list = NULL;
	t_lemlist	*tmp = NULL;

	list = lem->tab[hashcode(end)];
	ft_putendl("OK");
	tmp = list; 
	while(tmp)
	{
		if (tmp->dist == 0)
			tmp->dist = i;
		if (!ft_strcmp(list->str, "1"))
			exit(1);
		tmp = tmp->next;
	}
	while (list)
	{
		i++;
		if (list->str)
			dist(lem, list->str, i);
		list = list->next;
	}
}

int main()
{
	t_lem		*lem;

	lem = parse();
	ft_putnbr(lem->j);
	ft_putendl((lem->tab[hashcode("1")])->next->str);
	ft_putendl(lem->start);
	ft_putendl(lem->end);
	return 0;
}