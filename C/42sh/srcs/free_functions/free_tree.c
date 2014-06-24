/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 13:41:35 by msarr             #+#    #+#             */
/*   Updated: 2014/06/16 16:19:08 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_42sh.h"

bool		alloc_tree(t_tree **new, t_tree **tree)
{
	if (!(*new = init_tree()))
	{
		free_tree(tree);
		return (FALSE);
	}
	return (TRUE);
}


void		free_tree(t_tree **tree)
{
	if (*tree)
	{
		free_tree(&(*tree)->next);
		free_tree(&(*tree)->right);
		free_tree(&(*tree)->left);;
    }
}
