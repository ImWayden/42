/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 19:27:07 by msarr             #+#    #+#             */
/*   Updated: 2014/12/01 01:04:46 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

static int		pos_exit()
{
	ft_putendl("vector or color needs 3 args");
	exit (0);
}

t_lex			*get_pos(t_vect *v, t_lex *lex)
{
	int			i;

	i = 0;
	while ((lex = lex->next))
	{
		if (!ft_strncmp(lex->str, "<X>", 3) || !ft_strncmp(lex->str, "<R>", 3))
			v->x = get_nbr(&lex->str[3]);
		else if (!ft_strncmp(lex->str, "<Y>", 3) || !ft_strncmp(lex->str, "<G>", 3))
			v->y = get_nbr(&lex->str[3]);
		else if (!ft_strncmp(lex->str, "<Z>", 3) || !ft_strncmp(lex->str, "<B>", 3))
			v->z = get_nbr(&lex->str[3]);
		else
			break;
		i++;
	}
	ft_putnbr(v->x);
	ft_putnbr(v->y);
	ft_putnbr(v->z);
	if (i != 3)
		pos_exit();
	ft_putchar('\n');
	return (lex);
}