/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   satantua.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/04 11:53:05 by msarr             #+#    #+#             */
/*   Updated: 2014/07/04 11:53:08 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void			ft_putchar(char c);

int				biggest_line(int size)
{
	int			i;
	int			j;
	int			line;
	int			c;

	i = 1;
	j = 3;
	c = 4;
	while (size)
	{
		line = j;
		while (line--)
			i += 2;
		if (size == 1)
			return (i);
		i += c - (c % 2);
		c++;
		j++;
		size--;
	}
	return (0);
}

int				stairs(int i, int b)
{
	int			c;
	int			j;

	j = i + 2;
	if (i)
	{
		c = b / 2 - i / 2;
		while (c--)
			ft_putchar(' ');
		ft_putchar('/');
		while (i)
		{
			ft_putchar('*');
			i--;
		}
		ft_putchar('\\');
		ft_putchar('\n');
	}
	return (j);
}

void			last(int i, int k, int size, int line)
{
	if (i > k && i <= k + size && line < size)
	{
		if (i == (k + size / 2) && line == size / 2)
			ft_putchar('$');
		else
			ft_putchar('|');
	}
	else
		ft_putchar('*');
}

int				last_stairs(int i, int b, int size, int line)
{
	int			j;
	int			c;
	int			k;

	while (line--)
	{
		j = i + 2;
		if (i)
		{
			c = b / 2 - i / 2;
			while (c--)
				ft_putchar(' ');
			ft_putchar('/');
			k = (i / 2) - (size / 2);
			while (i)
			{
				last(i, k, size, line);
				i--;
			}
			ft_putchar('\\');
			ft_putchar('\n');
		}
		i = j;
	}
	return (0);
}

void			sastantua(int size)
{
	int			line;
	int			size1;
	int			i;
	int			j;
	int			b;
	int			c;

	j = 3;
	i = 1;
	c = 4;
	size1 = size;
	b = biggest_line(size);
	while (size > 0)
	{
		line = j;
		if (size == 1)
			size = last_stairs(i, b, size1, line);
		while (line-- && size > 0)
			i = stairs(i, b);
		i += c - (c % 2);
		c++;
		j++;
		size--;
	}
}
