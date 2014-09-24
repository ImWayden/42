/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 15:20:21 by sraccah           #+#    #+#             */
/*   Updated: 2014/06/25 12:46:22 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>

# define BUFF_SIZE 1024
# define BLACK     "\033[1;30m"
# define RED       "\033[1;31m"
# define GREEN     "\033[1;32m"
# define YELLOW    "\033[1;33m"
# define BLUE      "\033[1;34m"
# define PURPLE    "\033[1;35m"
# define CYAN      "\033[1;36m"
# define GREY      "\033[1;37m"

/*
** Lists / Strutures / Trees
*/

typedef struct		s_list
{
	void			*content;
	size_t			*content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_node
{
	char			*data;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

/*
** Functions for Lists / Strutures / Trees and HashTables
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f) (t_list *elem));
void				ft_lstdel(t_list **alst, void (*del) (void *, size_t));
void				ft_print_list(t_list *list);
int					ft_size_list(t_list *list);
t_list				*ft_lstmap(t_list *list, t_list *(*f) (t_list *elem));
int					search_node(t_node *tree, char *data);
void				print_tree(t_node *tree);
void				clear_tree(t_node **tree);
int					ft_hashb(char *str);

/*
** Added for posterity
*/

void				ft_is_not_found(char *cmd);
int					ft_is(char *str, int c);
int					ft_isint(char *str);
int					ft_get_next_line(int const fd, char **line);
char				*ft_strdup_gnl(char *str);
char				*ft_strjoin_gnl(char *s1, char *s2);
void				ft_print_error(char *error);
void				ft_print_gnobs(char *error);
void				ft_print_rnobs(char *error);
void				ft_print_bnobs(char *error);
void				ft_print_pnobs(char *error);
void				ft_print_ynobs(char *error);
void				ft_print_red(char *error);
void				ft_print_green(char *error);
void				ft_print_blue(char *error);
void				ft_print_purple(char *error);
void				ft_print_yellow(char *error);

/*
** Lib C
*/

void				ft_putchar(char c);
int					ft_strlen_ps(char *str);
int					ft_linelen(char const *str);
char				*ft_strreverse(const char *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char *str);
void				ft_putstr_fd(char *str, int fd);
void				ft_putnbr(int nbr);
void				ft_putnbr_fd(int nbr, int fd);
size_t				ft_strlen(const char *str);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
void				ft_putendl(char const *str);
void				ft_putendl_fd(char const *str, int fd);
void				ft_bzero(void *s, size_t n);
char				*ft_strdup(const char *src);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
int					ft_strlcat(char *dest, const char *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f) (char *));
void				ft_striteri(char *s, void (*f) (unsigned int, char *));
char				*strmap(const char *s, char (*f) (char));
char				*strmapi(const char *s, char (*f) (unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
char				*ft_itoa(int n);

#endif
