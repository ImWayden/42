/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 08:30:44 by msarr             #+#    #+#             */
/*   Updated: 2014/06/13 19:25:35 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_42sh.h"

t_node			*new_node(void)
{
	t_tree	*node;

	node = NULL;
	if ((node = (t_node *)malloc(sizeof(*node))))
	{
		node->type = -1;
  		node->right = NULL;
  		node->left = NULL;
  		node->lex = NULL;
  	}
  	return (tree);
}
