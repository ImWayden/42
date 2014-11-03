/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:14:37 by msarr             #+#    #+#             */
/*   Updated: 2014/10/11 21:14:49 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define WHITE     0xFFFFF0
# define RED       0xCC0000
# define GREEN     0x00CC00
# define YELLOW    0xCCFF00
# define BLUE      0x000066
# define PURPLE    0x330000
# define CYAN      0x00FFFF
# define GREY      0x808080

typedef	struct	s_env
{
	void		*ptr;
	void		*win;
}				t_env;

#endif
