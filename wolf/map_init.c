/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 15:00:04 by xmachado          #+#    #+#             */
/*   Updated: 2014/01/09 19:44:23 by xmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void    ft_stock_value(t_env *e)
{
    char    **tmp;
    int     i;
    int     j;

    i = 0;
    j = 0;
    e->tab = (int **)malloc(sizeof(int *) * (e->nbr_line + 1));
    e->tab[e->nbr_line] = '\0';
    while (i < e->nbr_line)
    {
        e->tab[i] = (int *)malloc(sizeof(int) * (e->nbr_col + 1));
        e->tab[i][e->nbr_col] = '\0';
        i++;
    }
    e->fd = open(e->argv[1], O_RDONLY);
    while (ft_get_next_line(e->fd, &e->line))
    {
        i = 0;
        tmp = ft_strsplit(e->line, ' ');
        while (i < e->nbr_col)
        {
            e->tab[j][i] = ft_atoi(tmp[i]);
            ft_putnbr(e->tab[j][i]);
            i++;
        }
        j++;
        ft_putchar('\n');
    }
}

void    ft_nbr_line_col(t_env *e)
{
    int     i;
    char    **tmp;

    e->nbr_line = 0;
    e->nbr_col = 0;
    e->fd = open(e->argv[1], O_RDONLY);
    while (ft_get_next_line(e->fd, &e->line))
    {
        i = 0;
        tmp = ft_strsplit(e->line, ' ');
        ft_putstr(e->line);
        ft_putchar('\n');
        while (tmp[i])
            i++;
        e->nbr_line++;
    }
    e->nbr_col = (i - 1);
}
