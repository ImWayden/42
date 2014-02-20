/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <aleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 09:48:35 by aleger            #+#    #+#             */
/*   Updated: 2014/01/26 09:52:48 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct			s_data
{
	va_list				ptr;
	va_list				ptr2;
	char				**s;
	char				*rest;
	char				*space;
	char				flag;
	int					i;
	int					ret;
	int					fpadd;
	int					padding;
}						t_data;

int						ft_printf(const char *format, ...)
						__attribute__((format(printf, 1, 2)));
t_data					*init(t_data *data, char *s);
char					*format_mod(char *s);
char					*ft_uitoa(unsigned int n);
char					*ft_uotoa(unsigned int n);
char					*ft_xtoa(unsigned int n);
char					*space_case(char **s, t_data *data);
int						s_case(char *s, t_data *data);
int						d_case(int d, t_data *data);
int						c_case(int c, t_data *data);
int						u_case(unsigned int u, t_data *data);
int						o_case(unsigned int o, t_data *data);
int						x_case(int x, t_data *data, char *s);
void					kill_data(t_data *data, char *s);
int						print_spaces(int n, t_data *data);

#endif /* !FT_PRINTF_H */
