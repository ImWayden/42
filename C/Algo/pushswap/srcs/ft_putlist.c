/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:57:59 by msarr             #+#    #+#             */
/*   Updated: 2013/12/15 14:57:01 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int			get_flag(t_lex *lex)
{
	static int		i = -1;

	if (lex->flag)
		i = -1;
	i++;
	return (i);
}

void		ft_putlist(t_lex *list)
{
	t_lex	*tmp;

	tmp = list;
	while (tmp)
	{
		ft_putnbr(tmp->nbr);
		if ((tmp = tmp->next) == list)
			break ;
		else
			ft_putstr(" ");
	}
	ft_putendl(NULL);
}

void		ft_debug(t_lex *l_a, t_lex *l_b)
{
	ft_putendl(NULL);
	ft_putstr ("l_a : ");
	if (l_a && l_a->name == 'a')
		ft_putlist(l_a);
	else if (l_b && l_b->name == 'a')
		ft_putlist(l_b);
	else
		ft_putendl(NULL);
	ft_putstr ("l_b : ");
	if (l_a && l_a->name == 'b')
		ft_putlist(l_a);
	else if (l_b && l_b->name == 'b')
		ft_putlist(l_b);
	else
		ft_putendl(NULL);
}

void		dell_list(t_lex **lex)
{
	t_lex	*tmp;

	tmp = *lex;
	*lex = (*lex)->next;
	tmp->prev->next = *lex;
	(*lex)->prev = tmp->prev;
	if (tmp != *lex)
		ft_memdel((void **)&tmp);
	else
		ft_memdel((void **)lex);
}
