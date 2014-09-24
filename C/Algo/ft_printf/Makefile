# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msarr <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/22 14:12:32 by msarr             #+#    #+#              #
#    Updated: 2013/12/22 14:12:35 by msarr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_addlist.c ft_isoption.c ft_isalpha.c ft_itoa.c ft_put.c ft_putstr.c \
	  ft_recup.c ft_strnew.c ft_strreverse.c ft_verif.c ft_strlen.c \
	  ft_bzero.c ft_octal.c ft_putnbr.c ft_putchar.c ft_hexa.c ft_strjoin.c \
	  ft_printf.c

HEAD = ft_printf.h

OBJS = $(SRC:.c=.o) 

FLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(HEAD) $(SRC)
	ar rc $(NAME) $(OBJS)

fclean: clean
	/bin/rm -f $(NAME) ft_printf.h.gch

clean:
	/bin/rm -f	$(OBJS)

re: fclean all
