/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/12 13:36:47 by msarr             #+#    #+#             */
/*   Updated: 2014/07/12 13:36:49 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			is_in_line(char k, char **av, int i)
{
	int		j;

	j = 0;
	while (j < 9)
	{
		if (av[i][j] == k)
			return (1);
		j++;
	}
	return (0);
}

int			is_in_collumn(char k, char **av, int j)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		if (av[i][j] == k)
			return (1);
		i++;
	}
	return (0);
}

int			is_in_block(char k, char **av, int i, int j)
{
	int		cpi;
	int		cpj;

	cpi = i - (i % 3);
	cpj = j - (j % 3);
	i = cpi;
	while (i < cpi + 3)
	{
		j = cpj;
		while (j < cpj + 3)
		{
			if (av[i][j] == k)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int			ft_sudoku(char **av, int i, int j)
{
	char	k;

	k = '1';
	if (i > 8)
		return (1);
	if (av[i][j] >= '1' && av[i][j] <= '9' && j < 8)
		return (ft_sudoku(av, i, j + 1));
	if (av[i][j] >= '1' && av[i][j] <= '9' && j == 8)
		return (ft_sudoku(av, i + 1, 0));
	while (k <= '9')
	{
		if (!is_in_line(k, av, i) && !is_in_collumn(k, av, j)
			&& !is_in_block(k, av, i, j))
		{
			av[i][j] = k;
			if ((j < 8 && ft_sudoku(av, i, j + 1))
				|| (j == 8 && ft_sudoku(av, i + 1, 0)))
				return (1);
			av[i][j] = '.';
		}
		k++;
	}
	return (0);
}
