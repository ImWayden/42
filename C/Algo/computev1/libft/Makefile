# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 20:29:32 by msarr             #+#    #+#              #
#    Updated: 2014/03/08 23:10:59 by msarr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memset.c ft_bzero.c ft_join.c \
	  ft_strlen.c  ft_strdup.c  ft_strcpy.c ft_strncpy.c  ft_strcat.c \
	  ft_strncat.c ft_strchr.c ft_strstr.c ft_strrchr.c ft_strnstr.c \
	  ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
	  ft_isalnum.c ft_isascii.c ft_isprint.c ft_tolower.c ft_strlcat.c \
	  ft_toupper.c ft_putstr.c ft_putchar.c ft_memalloc.c ft_memdel.c \
	  ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	  ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	  ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
	  ft_putstr.c ft_putendl.c ft_putnbr.c ft_swap.c get_next_line.c \
	  ft_deltab.c ft_strndup.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

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