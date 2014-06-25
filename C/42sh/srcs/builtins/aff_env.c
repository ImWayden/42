/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 13:39:31 by msarr             #+#    #+#             */
/*   Updated: 2014/06/08 15:43:55 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_42sh.h"

int			aff_env(t_shell *shell, t_tree *tree)
{
	t_env	*env;

	env = shell->env;
	while (env)
	{
		write(tree->fd[1], env->name, ft_strlen(env->name));
		write(tree->fd[1], "=", 1);
		write(tree->fd[1], env->arg, ft_strlen(env->name));
		write(tree->fd[1], "\n", 1);
		env = env->next;
	}
	return (EXIT_SUCCESS);
}
