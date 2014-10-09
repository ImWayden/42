/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/09 16:54:09 by msarr             #+#    #+#             */
/*   Updated: 2014/10/09 16:54:11 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int						ft_get_file(char *file, t_list **list)
{
	int					fd;
	t_list				*lst;
	int					i;
	char				*str;
	i = 0;
	if ((fd = open(file, O_RDONLY) != -1))
	{
		while((get_next_line(fd, &str)))
		{
			if ((lst = (t_list *)malloc(sizeof(t_list))))
			{
				lst->content = str;
				lst->content_size = ft_strlen(str);
				lst->next = *list;
				*list = lst;
				str = NULL;
				i++;
			}
		}
	}
	return (i);
}

int			int main(int argc, char *argv[])
{
	return 0;
}