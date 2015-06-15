/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/12 13:22:43 by msarr             #+#    #+#             */
/*   Updated: 2014/07/12 13:22:47 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putstr(char *str);

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int			ft_error(int ac, char **av)
{
	int		i;
	int		j;

	if (ac == 9)
	{
		i = 0;
		while (i < ac)
		{
			if (ft_strlen(av[i]) != 9)
				return (1);
			j = 0;
			while (j < ac)
			{
				if ((av[i][j] >= '1' && av[i][j] <= '9') || av[i][j] == '.')
					j++;
				else
					return (1);
			}
			i++;
		}
		return (0);
	}
	return (1);
}
