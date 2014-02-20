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

NAME 	= ft_ls

HEAD	=	./includes/libft.h

OBJS 	=	ft_arsortlist.o	ft_ls ft_putdir.o ft_putlist.o ft_action.o \
			ft_asortlist.o ft_ls.o ft_putends.o	ft_recupdir.o ft_addlistdir.o \
			ft_error.o ft_lsroption.o ft_putilist.o	ft_rsortlist.o \
			ft_arecupdir.o ft_listswap.o ft_putattr.o ft_putinfos.o	\
			ft_sortlist.o main.o

FLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): 
	make -C libft/ fclean
	make -C libft/
	gcc -Wall -Wextra -Werror -I libft/includes/ -c *.c
	gcc -o  $(NAME) *.o -L libft/ -lft


fclean: clean
	/bin/rm -f $(NAME) lsft.h.gch

clean:
	/bin/rm -f	$(OBJS)

re: fclean all
 