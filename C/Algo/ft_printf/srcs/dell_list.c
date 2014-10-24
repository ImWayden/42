/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dell_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/24 18:17:40 by msarr             #+#    #+#             */
/*   Updated: 2014/10/24 18:17:42 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		dell_list(t_lex **lex)
{
	t_lex		*tmp;

	tmp = *lex;
	*lex = (*lex)->next;
	tmp->prev->next = *lex;
	(*lex)->prev = tmp->prev;
	ft_memdel((void **)&tmp->name);
	if (tmp != *lex)
		ft_memdel((void **)&tmp);
	else
		ft_memdel((void **)lex);
}
