/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 11:25:43 by msarr             #+#    #+#             */
/*   Updated: 2013/12/17 11:25:46 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = (char *) malloc(sizeof(char) * (i + j + 1));
	if (str)
		str[i + j] = '\0';
	else
		return (NULL);
	while (j--)
		str[i + j] = s2[j];
	while (i--)
		str[i] = s1[i];
	return (str);
}


int main(int argc, char  **argv)
{
	pid_t		father;
	char 		**str;
	int			tube[2];
	int			fd;
	char		buff;

	pipe(tube);
	father = fork();
	if (father > 0)
	{
		wait(NULL);
		argv[3] = ft_strjoin(ft_strjoin(argv[3]," "), argv[1]);
		str  = ft_strsplit(argv[3], ' ');
		close(tube[1]);
		fd = open(argv[4], O_CREAT | O_APPEND| O_TRUNC | O_WRONLY, 0644);
		dup2(fd, STDOUT_FILENO);
		execvp(str[0], str);
	}
	if (father == 0)
	{
		str  = ft_strsplit(argv[2], ' ');
		close(tube[0]);
		fd = open(argv[1], O_CREAT | O_APPEND| O_TRUNC | O_WRONLY, 0644);
		dup2(fd, STDOUT_FILENO);
      	execvp(str[0], str);
	}
	return 0;
}
