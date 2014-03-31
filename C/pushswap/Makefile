# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msarr <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/21 13:57:19 by msarr             #+#    #+#              #
#    Updated: 2013/11/21 13:57:22 by msarr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = ft_addlist.c ft_atoi.c ft_isdigit.c ft_issort.c ft_merge.c \
	  ft_p.c ft_putchar.c ft_putlist.c ft_putnbr.c ft_r.c ft_rr.c ft_s.c \
	  ft_listlen.c ft_sortlist.c ft_pushswap.c main.c

OBJS = $(SRC:.c=.o)

HEAD = ft_pushswap.h

FLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): 
	gcc $(FLAGS) -c $(HEAD) $(SRC)
	gcc  -o $(NAME) $(OBJS)

fclean: clean
	/bin/rm -f $(NAME) ft_pushswap.h.gch

clean:
	/bin/rm -f	$(OBJS)

re: fclean all