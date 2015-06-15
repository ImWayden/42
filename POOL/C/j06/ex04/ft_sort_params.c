/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/10 16:13:23 by msarr             #+#    #+#             */
/*   Updated: 2014/07/10 16:13:25 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void				ft_putchar(char c);

void				ft_putendl(char *str)
{
	while (str && *str)
	{
		ft_putchar(*str);
		str++;
	}
	ft_putchar('\n');
}

int					ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int					main (int argc, char **argv)
{
	int				i;
	int				j;
	char			*swap;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				swap = argv[i];
				argv[i] = argv[j];
				argv[j] = swap;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (++i < argc)
		ft_putendl(argv[i]);
	return (0);
}
