/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle03_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvolonda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/19 17:00:54 by jvolonda          #+#    #+#             */
/*   Updated: 2014/07/19 17:16:44 by jvolonda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					colle03_first(char *str)
{
	int				i;

	
	if (str[0] == 'A' && str[ft_strlen(str) -1] == 'C')
	{
		i = 1;
		while (i < ft_strlen(str) - 1)
		{
			if (str[i] == 'B')
				i++;
			else
				return (0);
		}
		return(ft_strlen(str));
	}
	return (0);
}

int					colle03_middle(int i, char *str)
{
	int				j;


	if (str[0] == 'B' && str[ft_strlen(str) -1] == 'B')
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
		return(ft_strlen(str));
	}
	return (0);
}

int					colle03(char **tab)
{
	int				i;
	int				j;
	int				k;

	i = 0;
	j =  ft_strlen((char *)tab) - 1;
	if ((k = colle03_first(tab[i])))
	{
		i++;
		while (colle03_middle(k, tab[i]) &&  i < j)
			i++;
		if (i == j)
			i = colle03_first(tab[j]);
		else
			return (0);
		if (i == k)
		{
			ft_putstr("[colle-03]");
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
