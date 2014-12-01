/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 00:45:55 by msarr             #+#    #+#             */
/*   Updated: 2014/12/01 00:58:17 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rt.h"

static int		light_exit()
{
	ft_putendl("light needs 3 args");
	exit (0);
}

t_lex			*get_light(t_light *light, t_lex *lex)
{
	int			i;

	i = 0;
	while (lex)
	{
		i++;
		if (!ft_strcmp(lex->str, "<POS>") && (lex = get_pos(&light->pos, lex)))
			continue ;
		else if (!ft_strcmp(lex->str, "<COL>") && (lex = get_pos(&light->color, lex)))
			continue ;
		else if (!ft_strcmp(lex->str, "<I>") && (lex = lex->next))
			light->i = get_nbr(lex->str);
		else
			break ;
		lex = lex->next;
	}
	if (i < 3)
		light_exit();
	return (lex);
}