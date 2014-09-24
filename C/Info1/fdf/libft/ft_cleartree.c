/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleartree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 14:29:18 by sraccah           #+#    #+#             */
/*   Updated: 2014/04/15 16:00:00 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void			clear_tree(t_node **tree)
{
	t_node		*tmptree;

	tmptree = *tree;
	if (!tree)
		return ;
	if (tmptree->left)
		clear_tree(&tmptree->left);
	free(tmptree);
	if (tmptree->right)
		clear_tree(&tmptree->right);
	*tree = NULL;
}
