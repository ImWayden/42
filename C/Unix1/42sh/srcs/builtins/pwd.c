/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/12 18:29:40 by msarr             #+#    #+#             */
/*   Updated: 2014/10/12 18:29:43 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int			ft_pwd(t_shell *shell)
{
	char	*str;

	if ((str = get_env(shell->env, "PWD")))
	{
		ft_putendl(str);
		ft_memdel((void **)&str);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
