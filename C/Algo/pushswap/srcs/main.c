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
	t_lex	*listb = NULL;

	if (argc > 1)
	{
		if ((lista = ft_get(&argv[1])))
		{
			while (lista)
			{
				ft_p(&lista, &listb, 'b');
				ft_putchar('\n');
				ft_putlist(lista);
				ft_putlist(listb);
				sleep(1);
			}
		}
	}
	return 0;
}