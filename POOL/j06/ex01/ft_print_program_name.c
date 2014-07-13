/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/10 16:00:56 by msarr             #+#    #+#             */
/*   Updated: 2014/07/10 16:00:59 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void				ft_putchar(char c);

void				ft_putstr(char *str)
{
	while (str && *str)
	{
		ft_putchar(*str);
		str++;
	}
}

int					main(int argc, char **argv)
{
	if (argc)
		ft_putstr(*argv);
	ft_putchar('\n');
	return (0);
}
