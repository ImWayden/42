/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 17:21:57 by atouzeau          #+#    #+#             */
/*   Updated: 2014/06/08 17:28:15 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include  <errno.h>
#include "rt.h"

int		xread(int fd, void *buf, int count)
{
	int			ret;
	int			errno;

	ret = read(fd, buf, count);
	if (ret == -1)
	{
		if (errno == EISDIR)
			ft_putstr("It's a directory.\n");
		else
		{
			ft_putstr("Error while reading ");
			ft_putnbr(count);
			ft_putstr(" bytes from fd ");
			ft_putnbr(fd);
			ft_putstr(".\n");
		}
		exit(EXIT_FAILURE);
	}
	return (ret);
}

char	*push(char *str, char *str_out)
{
	int			i;
	int			a;

	i = 0;
	a = 0;
	while (str[i] && str[i] != '\n')
		i++;
	while (str[i] == '\n')
		i++;
	while (str[i])
		str[a++] = str[i++];
	str[a] = '\0';
	return (str_out);
}

char	*init(char *buf, int *a)
{
	int			i;
	char		*str_out;

	i = 0;
	if (!(str_out = malloc(sizeof(*buf) * (ft_strlen(buf) + 1))))
		exit(0);
	str_out[0] = '\0';
	while (buf[(*a)] && buf[(*a)] != '\n')
		str_out[i++] = buf[(*a)++];
	str_out[i] = '\0';
	if (!str_out && !str_out[0])
	{
		free(str_out);
		return (NULL);
	}
	return (str_out);
}

char	*copy(char *buf, char *str, int *a)
{
	int			i;
	char		*str_out;

	i = 0;
	if (!(str_out = malloc(sizeof(*str) * ft_strlen(buf) + ft_strlen(str) + 1)))
		exit(0);
	while (str[i])
	{
		str_out[i] = str[i];
		i = i + 1;
	}
	while (buf[(*a)] && buf[(*a)] != '\n')
		str_out[i++] = buf[(*a)++];
	str_out[i] = '\0';
	free(str);
	return (str_out);
}

char	*get_next_line(const int fd)
{
	int			a;
	int			size;
	char		*str_out;
	static char	buf[READ + 1];

	a = 0;
	if (!(str_out = init(buf, &a)))
		return (NULL);
	if (buf[a] == '\n')
		return (push(buf, str_out));
	while ((size = xread(fd, buf, READ)) > 0)
	{
		a = 0;
		buf[size] = '\0';
		if (!(str_out = copy(buf, str_out, &a)))
			return (NULL);
		if (buf[a] == '\n')
			return (push(buf, str_out));
	}
	if (size <= 0)
		return (NULL);
	buf[size] = '\0';
	if (!size && !str_out[0])
		return (NULL);
	return (str_out);
}
