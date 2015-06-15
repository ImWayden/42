/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/22 14:18:09 by msarr             #+#    #+#             */
/*   Updated: 2014/07/22 14:18:11 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "bsq.h"

void		ft_puttab(char **str, t_list *list, int c)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (i >= list->i && i < list->i + c && j >= list->j && j < list->j + c)
				ft_putchar('x');
			else
				ft_putchar(str[i][j]);
			j++;
		}
		ft_putchar ('\n');
		i++;
	}
}

int			main(int argc, char **argv)
{
	int		i;
	int		k;
	char	**str;
	t_list	*list;
	t_list	*rslt;

	if (argc > 1)
	{
		i = 1;
		while (argv[i])
		{
			list = NULL;
			if ((str = parser(argv[i], &list)))
			{
				k = ft_atoi(str[0]);
				while (!(rslt = bsq(list, 0, 0, k, str)))
					k--;
				ft_puttab(&str[1], rslt, k);
			}
			else
				ft_putendl("Map Error");
			i++;
		}
	}
	return (0);
}
