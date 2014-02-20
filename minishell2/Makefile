# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msarr <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/26 06:39:16 by msarr             #+#    #+#              #
#    Updated: 2014/01/26 06:39:22 by msarr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
SRC = builtin.c ft_bzero.c ft_memdel.c ft_putendl_fd.c ft_putstr_fd.c \
	  ft_strdup.c ft_strjoin.c ft_strlen.c ft_strnequ.c ft_strnew.c \
	  ft_strtrim.c ft_strsub.c ft_strsplit.c ft_strrealloc.c needed.c \
	  getnextline.c pipe.c termcap.c list.c main.c
HEAD = minishell2.h
OBJS = $(SRC:.c=.o)
NAME = ft_minishell2

all: $(NAME)

$(NAME):
		gcc -o $(NAME) $(FLAGS) $(SRC) -ltermcap

clean:
		@(rm -rf $(OBJS))

fclean: clean
		@(rm -rf $(NAME))

re: fclean all
