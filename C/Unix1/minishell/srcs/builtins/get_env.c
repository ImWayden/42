/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 13:39:46 by msarr             #+#    #+#             */
/*   Updated: 2014/10/08 18:12:30 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

char		*get_env(t_env *env, char *str)
{
	while (env)
	{
		if (!ft_strcmp(env->name, str))
			return (ft_strdup(env->arg));
		env = env->next;
	}
	return (NULL);
}
