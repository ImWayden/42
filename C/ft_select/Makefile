# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msarr <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/15 19:55:50 by msarr             #+#    #+#              #
#    Updated: 2013/12/15 19:55:52 by msarr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

HEAD =	ft_select.h

SRC = ft_config.c ft_init.c ft_recup.c ft_strcmp.c ft_defconfig.c \
		  ft_memdel.c ft_strdup.c ft_effect.c ft_putlist.c ft_strlen.c \
		  ft_addlist.c ft_effect2.c ft_putstr.c ft_setlist.c main.c

FLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): 
	gcc -o  $(NAME) $(FLAGS) $(SRC) -ltermcap


fclean: clean
	/bin/rm -f $(NAME)

clean:

re: fclean all
 