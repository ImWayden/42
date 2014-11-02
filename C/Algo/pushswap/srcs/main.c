/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 17:02:19 by msarr             #+#    #+#             */
/*   Updated: 2013/12/24 17:02:21 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int main(int argc, char **argv)
{
	t_lex	*lista;
	int		flag;

	flag = 0;
	if (argc > 1)
	{
		if ((lista = ft_get(&argv[1], flag)))
		{
			ft_sortlist(&lista);
			dell_list(&lista);
		}
	}
	return (0);
}
