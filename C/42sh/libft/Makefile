# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 20:29:32 by sraccah           #+#    #+#              #
#    Updated: 2014/03/01 15:13:49 by sraccah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_strcpy.c ft_strlen.c ft_strcmp.c ft_strncmp.c ft_memmove.c\
      ft_memchr.c ft_memcmp.c ft_strcat.c ft_strncat.c ft_strlcat.c\
      ft_strchr.c ft_strrchr.c ft_strnstr.c ft_atoi.c ft_isalpha.c\
      ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c\
      ft_tolower.c ft_strstr.c ft_memset.c ft_memcpy.c ft_memccpy.c\
      ft_strdup.c ft_bzero.c ft_strncpy.c ft_memalloc.c ft_memdel.c\
      ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c\
      ft_putchar.c ft_putstr.c ft_putnbr.c ft_putendl.c ft_putnbr_fd.c\
      ft_putchar_fd.c ft_putstr_fd.c ft_linelen.c ft_exit.c ft_malloc.c\
      ft_open.c ft_realloc.c ft_addlink.c ft_addendlink.c ft_size_list.c\
      ft_print_list.c ft_strsub.c ft_strsplit2.c ft_strreverse.c ft_strmapi.c\
      ft_strjoin.c ft_strmap.c ft_strlen_ps.c get_next_line.c ft_strdup_gnl.c \
      ft_strjoin_gnl.c ft_isint.c ft_strtrim.c ft_print_colours.c \
      ft_print_colours2.c ft_error.c ft_strsplit.c ft_free.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@$(CC) -I includes/ $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[1;32m"
	@echo -n '---> DONE ! <---'
	@echo "\033[0m"

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(OBJ) $(NAME)

re: fclean all

.PHONY: all re name clean fclean