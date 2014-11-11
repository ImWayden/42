/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 17:02:47 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/08 17:02:49 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "rt.h"

void	ft_errorconf(int count, char *s1, char *s2, char *s3)
{
	write(2, "Line : ", ft_strlen("Line : "));
	ft_putnbr(count);
	write(2, "\n", ft_strlen("\n"));
	write(2, s1, ft_strlen(s1));
	write(2, s2, ft_strlen(s2));
	write(2, s3, ft_strlen(s3));
	exit(0);
}

void	check_nbr(char *str, int *check, int i)
{
	int		err;

	err = 0;
	if (str[i] != '<')
		err = 1;
	if (str[i + 1] == '-')
		i++;
	while (str[++i] && str[i] != '>')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
			err = 1;
	}
	if (str[i] != '>')
		err = 1;
	if (err == 0)
		*check = 1;
}

char	*check_error(char *str, int count, char **token)
{
	int		i;
	int		check;

	i = -1;
	check = 0;
	while (token[++i])
	{
		if (ft_strcmp(token[i], str) == 0)
			check = 1;
	}
	if (ft_strncmp("<X>", str, 3) == 0 || ft_strncmp("<Y>", str, 3) == 0 ||
		ft_strncmp("<Z>", str, 3) == 0 || ft_strncmp("<R>", str, 3) == 0 ||
		ft_strncmp("<G>", str, 3) == 0 || ft_strncmp("<B>", str, 3) == 0)
		check_nbr(str, &check, 3);
	else
		check_nbr(str, &check, 0);
	if (check == 0)
		ft_errorconf(count, "Invalid instruction : \"", str, "\".\n");
	return (str);
}
