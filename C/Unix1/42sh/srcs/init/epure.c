/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epure.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 07:34:25 by msarr             #+#    #+#             */
/*   Updated: 2014/12/27 07:34:27 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

t_lex		*check_alias(t_shell *shell, char *str)
{
	t_alias	*alias;

	alias = shell->alias;
	while (alias)
	{
		if (!ft_strcmp(alias->name), lex->str)
		{}
	}
}

t_lex		*epure(t_shell *shell, t_lex *lex)
{
	lex = check_alias(shell, lex);
}
