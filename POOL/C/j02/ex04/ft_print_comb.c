/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/03 12:44:33 by msarr             #+#    #+#             */
/*   Updated: 2014/07/03 12:44:35 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

void		ft_write(void)
{
	ft_putchar(',');
	ft_putchar(' ');
}

void		ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = 0;
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				ft_putchar(a);
				ft_putchar(b);
				ft_putchar(c);
				if (a != '7' || b != '8' || c != '9')
					ft_write();
				c++;
			}
			b++;
		}
		a++;
	}
}
