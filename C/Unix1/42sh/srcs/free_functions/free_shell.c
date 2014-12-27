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

#include "42sh.h"
#include "grammar.h"

void			free_shell(t_shell **shell)
{
	if (shell && *shell)
	{
		ft_memdel((void **)&(*shell)->prompt);
		ft_deltab(&((*shell)->envc));
		ft_deltab(&(*shell)->path);
		free_env(&(*shell)->env);
		free_tree(&(*shell)->tree);
		ft_memdel((void **)shell);
	}
}
