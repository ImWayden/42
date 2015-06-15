/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle02_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvolonda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/19 17:01:06 by jvolonda          #+#    #+#             */
/*   Updated: 2014/07/19 17:16:46 by jvolonda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					colle02_first(char *str)
{
	int				i;


	if (str[0] == 'A' && str[ft_strlen(str) -1] == 'A')
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

int					colle02_middle(int i, char *str)
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

int					colle02_last(char *str)
{
	int				j;


	if (str[0] == 'C' && str[ft_strlen(str) -1] == 'C')
	{
		j = 1;
		while (j < ft_strlen(str) - 1)
		{
			if (str[j] == 'B')
				j++;
			else
				return (0);
		}
		return(ft_strlen(str));
	}
	return (0);
}

int					colle02(char **tab)
{
	int				i;
	int				j;
	int				k;

	i = 0;
	j =  ft_strlen((char *)tab) - 1;
	if ((k = colle02_first(tab[i])))
	{
		i++;
		while (colle02_middle(k, tab[i]) &&  i < j)
			i++;
		if (i == j)
			i = colle02_first(tab[j]);
		else
			return (0);
		if (i == k)
		{
			ft_putstr("[colle-02]");
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
