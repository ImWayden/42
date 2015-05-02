/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleartree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 14:29:18 by sraccah           #+#    #+#             */
/*   Updated: 2015/03/25 14:55:55 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void			ft_clear_tree(t_node **tree)
{
	t_node		*tmptree;

	tmptree = *tree;
	if (!tree)
		return ;
	if (tmptree->left)
		ft_clear_tree(&tmptree->left);
	free(tmptree);
	if (tmptree->right)
		ft_clear_tree(&tmptree->right);
	*tree = NULL;
}
