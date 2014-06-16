/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 13:41:21 by msarr             #+#    #+#             */
/*   Updated: 2014/06/16 16:30:32 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"

void		free_lex(t_lex **lex)
{
	if (*lex && (*lex)->next)
		free_lex(&(*lex)->next);
	if (*lex)
	{
		ft_memdel((void **)&(*lex)->str);
		ft_memdel((void **)lex);
	}
}

void		lex_delfirst(t_lex **lex)
{
	if (lex && *lex)
	{
		ft_memdel((void **)&(*lex)->str);
		ft_memdel((void **)lex);
	}
}

