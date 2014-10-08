/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 13:39:31 by msarr             #+#    #+#             */
/*   Updated: 2014/10/08 18:22:46 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

int			aff_env(t_shell *shell)
{
	t_env	*env;

	env = shell->env;
	while (env)
	{
		ft_putstr(env->name);
		ft_putstr("=");
		ft_putendl(env->arg);
		env = env->next;
	}
	return (1);
}
