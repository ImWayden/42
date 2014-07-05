/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/05 12:27:14 by msarr             #+#    #+#             */
/*   Updated: 2014/07/05 12:27:15 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			ft_putchar(char c);

void			ft_put(int x, int y, int x1, int y1)
{
	if ((x1 == 1 && y1 == y))
		ft_putchar('/');
	else if (x1 == x && y1 == y)
		ft_putchar('\\');
	else if (x1 == 1 && y1 == 1)
		ft_putchar('\\');
	else if (x1 == x && y1 == 1)
		ft_putchar('/');
	else if ((x1 != 1 && x1 != x) && (y1 == 1 || y1 == y))
		ft_putchar('*');
	else if ((x1 != 1 && x1 != x) && (y1 != 1 || y1 != y))
		ft_putchar(' ');
	else
		ft_putchar('*');
}

void			colle(int x, int y)
{
	int			x1;
	int			y1;

	y1 = y;
	while (y1)
	{
		x1 = 1;
		while (x1 <= x)
		{
			ft_put(x, y, x1, y1);
			x1++;
		}
		ft_putchar('\n');
		y1--;
	}
}
