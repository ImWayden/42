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

int			main(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	**str;
	t_list	*list;

	if (argc > 1)
	{
		i = 1;
		while (argv[i])
		{
			ft_putendl(argv[i]);
			list = NULL;
			if ((str = parser(argv[i], &list)))
			{
				j = 0;
				while (str[j])
				{
					ft_putendl(str[j]);
					j++;
				}
				k = 0;
				ft_putnbr(ft_atoi(str[0]) * ft_atoi(str[0]));
				ft_putendl("");
				k = 0;
				while ((j = bsq(list, 0, ft_atoi(str[0]) - k, ft_atoi(str[0]), ft_atoi(str[1]))) < 0)
					k++;
				ft_putchar('\'');
				ft_putnbr(j);
				ft_putchar('\'');
				k = ft_atoi(str[0]) - k;
				i = 1;
				l = 0;
				while (str[i])
				{
					l = 0;
					while (str[i][l])
					{
						if (i >= j / 9 && i < j / 9 + k && l >= j % 9 && l < j % 9 + k)
							ft_putchar('x');
						else
							ft_putchar(str[i][l]);
						l++;
					}
					ft_putchar ('\n');
					i++;
				}
			}
			else
				ft_putendl("parser 0");
			i++;
		}
	}
	return (0);
}
