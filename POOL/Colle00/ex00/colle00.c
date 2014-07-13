/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhabche <rkhabche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/05 15:33:47 by rkhabche          #+#    #+#             */
/*   Updated: 2014/07/06 16:43:08 by rkhabche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c);

void colle(char x, char y)
{
	char cptx;
	char cpty;

	cpty = 1;
	while (cpty <= y)
	{
		cptx = 1;
		while (cptx <= x)
		{
			if ((cptx == 1 && cpty == 1) || (cptx == x && cpty == y)
				|| (cptx == x && cpty == 1) || (cptx == 1 && cpty == y))
				ft_putchar('o');
			else if (cpty == y || cpty == 1)
				ft_putchar('-');
			else if (cptx == 1 || cptx == x)
				ft_putchar('|');
			else
				ft_putchar(' ');
			cptx++;
		}
		ft_putchar('\n');
		cpty++;
	}
}
