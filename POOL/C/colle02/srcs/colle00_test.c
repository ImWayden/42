/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle00_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/19 14:53:12 by msarr             #+#    #+#             */
/*   Updated: 2014/07/19 14:53:13 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int					colle00_first(char *str)
{
	int				i;
	int				j;

	j = ft_strlen(str);
	if (str[0] == 'o')
	{
		i = 1;
		while (i < j - 1)
		{
			if (str[i] == '-')
				i++;
			else
				return (0);
		}
		if (j != 1 && str[j - 1] != 'o')
			return (0);
		return(j);
	}
	return (0);
}

int					colle00_middle(int i, char *str)
{
	int				j;
	int				k;

	k = ft_strlen(str);
	if (str[0] == '|' )
	{
		j = 1;
		if (k != i)
			return (0);
		while (j < k - 1)
		{
			if (str[j] == ' ')
				j++;
			else
				return (0);
		}
		if(k != 1 && str[k - 1] != '|')
			return (0);
		return(1);
	}
	return (0);
}

int					colle00(char **tab)
{
	int				i;
	int				k;

	if ((k = colle00_first(tab[0])))
	{
		i = 1;
		while (tab[i] && tab[i + 1])
		{
			if (colle00_middle(k, tab[i]))
				i++;
			else
				return (0);
		}
		if (i != 1 && !colle00_first(tab[i]))
			return (0);
		if (i == k)
		{
			ft_putstr("[colle-00] [");
			ft_putnbr(k);
			ft_putstr("] [");
			ft_putnbr(i);
			ft_putstr("]");
			return (1);
		}
	}
	else
		return (0);
}
