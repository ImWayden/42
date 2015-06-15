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

void		ft_puttab(t_bsq *bsq, t_bsq_list *list, int c)
{
	int		i;
	int		j;
	t_bsq_list	*tmp;

	i = 0;
	tmp = bsq->list;
	while (i < bsq->l_max)
	{
		j = 0;
		while (j < bsq->c_max)
		{
			if (i >= list->i && i < list->i + c && j >= list->j && j < list->j + c)
				ft_putchar(bsq->str[2]);
			else if (tmp && (i == tmp->i && j == tmp->j))
			{
				ft_putchar(bsq->str[1]);
				tmp = tmp->next;
			}
			else
				ft_putchar(bsq->str[0]);
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
	t_bsq	*bsq;
	t_bsq_list	*rslt;

	if (argc > 1)
	{
		i = 1;
		while (argv[i])
		{
			bsq = NULL;
			if ((bsq = parser(argv[i])))
			{
				bsq->list->prev->next = NULL;
				k = (bsq->l_max > bsq->c_max) ? bsq->c_max : bsq->l_max;
				while (!(rslt = ft_bsq(0, 0, k, bsq)))
					k--;
				ft_puttab(bsq, rslt, k);
			}
			else
				ft_putendl("Map Error");
			i++;
		}
	}
	return (0);
}
