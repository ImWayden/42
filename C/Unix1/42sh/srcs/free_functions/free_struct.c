/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 13:41:21 by msarr             #+#    #+#             */
/*   Updated: 2014/06/24 21:36:30 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		free_lex(t_lex **lex)
{
	t_lex	*tmp;

	while (*lex)
	{
		tmp = *lex;
		*lex = (*lex)->next;
		ft_memdel((void **)&(tmp->str));
		if (*lex == tmp)
			ft_memdel((void **)lex);
		else
			ft_memdel((void **)&tmp);
	}
}
