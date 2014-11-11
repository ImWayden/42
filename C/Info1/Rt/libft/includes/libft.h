/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouzeau <atouzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 17:54:39 by atouzeau          #+#    #+#             */
/*   Updated: 2014/04/25 18:11:55 by atouzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

long	ft_atoi_long(char *str);

size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *s1, const char *s2, size_t n);

char	**ft_strssplit(char *s);
char	**ft_strsplit(char *s, char c);

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, int n);
int		ft_strequ(char *s1, char *s2);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strnequ(char *s1, char *s2, size_t n);

void	ft_putnbr(int a);
void	ft_putchar(char c);
void	ft_strclr(char *s);
void	ft_putstr(char *str);
void	ft_memdel(void **ap);
void	ft_strdel(char **as);
void	ft_puterror(char *str);
void	ft_putunbr(unsigned int i);
void	ft_bzero(void *s, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_sort_int_tab(int *tab, unsigned int size);
void	ft_putstr_fd(const char *s1, int fd);
void	ft_striter(char *s, void (*f)(char*));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	*ft_memalloc(size_t size);
void	*ft_memset(void *s, int i, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n);

char	*ft_itoa(int n);
char	*ft_strnew(size_t size);
char	*ft_strdup(const char *s);
char	*ft_uitoa(unsigned int n);
char	*ft_strtrim(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strcpy(char *s1, char *s2);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strstr(char *s1, char *s2);
char	*ft_strmap(const char *s, char (*f)(char));
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *s1, char *s2, int n);
char	*ft_strsub(char *s, unsigned int start, size_t len);
char	*ft_strnstr(char *s1, char *s2, size_t n);

#endif
