/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 13:41:21 by msarr             #+#    #+#             */
/*   Updated: 2014/06/15 03:35:04 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"

void		free_lex(t_lex **lex)
{
	t_lex		*tmp;

	if (*lex && (*lex)->next)
		free_lex(&(*lex)->next)
	if (*lex)
	{
		ft_memdel((void **)&(lex->str));
		ft_memdel((void **)lex);
	}
}

void		lex_delfirst(t_lex **lex)
{
	t_lex	*tmp;

	if (lex && *lex)
	{
		*lex = lex->next;
		ft_memdel((void **)&(lex->prev->str));
		ft_memdel((void **)lex->prev);
	}
}

