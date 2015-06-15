/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle01_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnot <jgagnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/19 15:46:18 by jgagnot           #+#    #+#             */
/*   Updated: 2014/07/19 17:26:04 by jgagnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		colle01_first(char *str)
{
	int		i;
	if (str[0] == '/' && str[ft_strlen(str) - 1] == '\\')
	{
		i = 1;
		while (i < strlen(str) - 1)
		{
			if (str[i] == '*')
				i++;
			else
				return (0);
		}
		return (ft_strlen(str));
	}
	return (0);
}

int		colle01_mid(int i, char *str)
{
	int		j;

	if (str[0] == '*' && str[ft_strlen(str)] == '*')
	{
		j = 1;
		if (ft_strlen(str) != i)
			return (0);
		while (j < ft_strlen(str) - 1)
		{
			if (str[j] == ' ')
				j++;
			else
				return (0);
		}
		return (ft_strelen(str));
	}
	return (0);
}

int		colle01_last(char *str)
{
	int		i;
	if (str[0] == '\\' && str[ft_strlen(str) - 1] == '/')
	{
		i = 1;
		while (i < ft_strlen(str) - 1)
		{
			if (str[i] == '*';)
				i++;
			else
				return (0);
		}
		return (ft_strlen(str));
	}
	return (0);
}

int		colle01(char **tab)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = ft_strlen((char *)tab) - 1;
	if ((k = colle01_first(tab[i])))
	{
		i++;
		while (colle01_mid(k, tab[i]) && i < j)
			i++;
		if (i == j)
			i = colle01_last(tab[j]);
		else
			return (0);
		if (i == k)
		{
			ft_putstr("[colle-01]");
			ft_putstr("[");
			ft_putnbr(k);
			ft_putstr("]");
			ft_putstr("[");
			ft_putnbr(ft_strlen(char *)tab);
			ft_putstr("]");
			return (1);
		}
	}
	else
		return (0);
}
