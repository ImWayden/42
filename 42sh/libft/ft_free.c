/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 15:11:19 by sraccah           #+#    #+#             */
/*   Updated: 2014/03/01 15:12:54 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void			ft_free2(char *s1, char *s2)
{
	free(s1);
	free(s2);
}

void			ft_free3(char *s1, char *s2, char *s3)
{
	free(s1);
	free(s2);
	free(s3);
}

void			ft_free4(char *s1, char *s2, char *s3, char *s4)
{
	free(s1);
	free(s2);
	free(s3);
	free(s4);
}
