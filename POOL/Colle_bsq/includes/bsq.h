/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/22 13:15:25 by msarr             #+#    #+#             */
/*   Updated: 2014/07/22 13:15:26 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef					BSQ_H
# define				BSQ_H

# include <unistd.h>
# include <stdlib.h>

typedef struct			s_bsq_list
{
	int					i;
	int					j;
	struct s_bsq_list	*next;
	struct s_bsq_list	*prev;
}						t_bsq_list;

typedef struct			s_bsq
{
	char				*str;
	int					l_max;
	int					c_max;
	t_bsq_list			*list;
}						t_bsq;

t_bsq_list				*ft_bsq(int i, int j, int c, t_bsq *bsq);
void					before_bsq(t_bsq **bsq);

#endif
