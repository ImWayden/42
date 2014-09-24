/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 14:24:56 by sraccah           #+#    #+#             */
/*   Updated: 2014/04/15 15:59:05 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int			search_node(t_node *tree, char *data)
{
	while (tree)
	{
		if (data == tree->data)
			return (1);
		if (data > tree->data)
			tree = tree->right;
		else
			tree = tree->left;
	}
	return (0);
}
