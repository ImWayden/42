# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/14 17:38:13 by sraccah           #+#    #+#              #
#    Updated: 2014/05/17 03:48:25 by sraccah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

MAKE = make
CC = gcc
RM = /bin/rm

SRC = ft_strcpy.c\
	  ft_strlen.c\
	  ft_strcmp.c\
	  ft_strncmp.c\
	  ft_memmove.c\
      ft_memchr.c\
      ft_memcmp.c\
      ft_strcat.c\
      ft_strncat.c\
      ft_strlcat.c\
      ft_strchr.c\
      ft_strrchr.c\
      ft_strnstr.c\
      ft_atoi.c\
      ft_isalpha.c\
      ft_isdigit.c\
      ft_isalnum.c\
      ft_isascii.c\
      ft_isprint.c\
      ft_toupper.c\
      ft_tolower.c\
      ft_strstr.c\
      ft_memset.c\
      ft_memcpy.c\
      ft_memccpy.c\
      ft_strdup.c\
      ft_bzero.c\
      ft_strncpy.c\
      ft_memalloc.c\
      ft_memdel.c\
      ft_strnew.c\
      ft_strdel.c\
      ft_strclr.c\
      ft_striter.c\
      ft_striteri.c\
      ft_putchar.c\
      ft_putstr.c\
      ft_putnbr.c\
      ft_putendl.c\
      ft_putnbr_fd.c\
      ft_putchar_fd.c\
      ft_putstr_fd.c\
      ft_linelen.c\
	  ft_size_list.c\
	  ft_print_list.c\
	  ft_strsub.c\
	  ft_strsplit.c\
	  ft_strreverse.c\
	  ft_strequ.c\
	  ft_strmapi.c\
	  ft_strjoin.c\
	  ft_strmap.c\
	  ft_strlen_ps.c\
	  ft_isint.c\
	  ft_strtrim.c\
	  ft_error.c\
	  get_next_line.c\
	  ft_strjoin_gnl.c\
	  ft_strdup_gnl.c\
	  ft_print_red.c\
	  ft_print_green.c\
	  ft_print_yellow.c\
	  ft_print_blue.c\
	  ft_print_purple.c\
	  ft_print_rnobs.c\
	  ft_print_gnobs.c\
	  ft_print_ynobs.c\
	  ft_print_bnobs.c\
	  ft_print_pnobs.c\
	  ft_hashb.c\
	  ft_searchnode.c\
	  ft_print_tree.c\
	  ft_cleartree.c\
	  ft_is.c\
	  ft_itoa.c\
	  ft_lstnew.c\
	  ft_lstdel.c\
	  ft_lstdelone.c\
	  ft_lstmap.c\
	  ft_lstiter.c\
	  ft_lstadd.c

OBJ = $(SRC:.c=.o)
INC = -I includes/
CFLAGS = -Wall -Wextra -Werror
R = \033[31;1m
G = \033[32;1m
Y = \033[33;1m
B = \033[34;1m
P = \033[35;1m
C = \033[36;1m
Z = \033[0m
A = $(R)[$(B)$(NAME)$(R)]----->\033[0m

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC) $(INC)
	@echo "$(A)$(R)[$(Y)Compilation$(R): $(G)DONE$(R)]$(Z)"
	@ar rc $(NAME) $(OBJ)
	@echo "$(A)$(R)[$(Y)AR RC$(R): $(G)DONE$(R)]$(Z)"
	@ranlib $(NAME)
	@echo "$(A)$(R)[$(Y)RanLib$(R): $(G)DONE$(R)]$(Z)"
	@echo "\n$(Y)-----------------------------------$(Z)"
	@echo "$(Y)-------- $(R)[$(B)libft.a $(G)created$(R)]$(Y) --------$(Z)"
	@echo "$(Y)-----------------------------------$(Z)\n"

clean:
	@$(RM) -rf $(OBJ)

fclean: clean
	@$(RM) -rf $(NAME)

re: fclean all

.PHONY: all name clean fclean re