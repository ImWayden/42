/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 13:41:07 by msarr             #+#    #+#             */
/*   Updated: 2014/06/10 14:50:20 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	env_delone(t_env **envc)
{
	if (*envc)
	{
		ft_memdel((void **)&(*envc)->name);
		ft_memdel((void **)&(*envc)->arg);
		ft_memdel((void **)envc);
	}
}

void	free_env(t_env **envc)
{
	if (*envc && (*envc)->next)
		free_env(&(*envc)->next);
	else if (*envc)
		env_delone(envc);
}
