/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/04 13:22:51 by msarr             #+#    #+#             */
/*   Updated: 2014/07/04 13:22:53 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			ft_swap(int *a, int *b)
{
	int			tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int				ft_strlen(char *str)
{
	int			i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char			*ft_strrev(char *str)
{
	int			i;
	int			j;

	j = ft_strlen(str) - 1;
	i = 0;
	while (j >  i)
	{
		ft_swap(&(str[i]), &(str[j]))
		i++;
		j--;
	}
}
