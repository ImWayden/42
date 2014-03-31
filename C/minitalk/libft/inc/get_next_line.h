/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <aleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 09:51:23 by aleger            #+#    #+#             */
/*   Updated: 2014/01/26 09:53:03 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32768

int						get_next_line(int const fd, char **line);

typedef struct			s_read
{
	int					size;
	int					index;
	int					fd;
	char				*read;
	struct s_read		*next;
}						t_read;

#endif /* !GET_NEXT_LINE_H */
