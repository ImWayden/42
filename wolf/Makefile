#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xmachado <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/17 20:21:15 by xmachado          #+#    #+#              #
#    Updated: 2014/01/09 15:46:13 by xmachado         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAGS = -Wall -Wextra -Werror
LIBFT = ./libft
FILES = wolf3d.c map_init.c
OBJS = $(FILES:.c=.o)
NAME = wolf3d

all: $(NAME)

$(NAME):
		make -C $(LIBFT)
		gcc $(FLAGS) -I libft/includes -c $(FILES)
		gcc -o $(NAME) $(OBJS) -L libft/ -lft -L/usr/X11/lib -lmlx -lXext -lX11

clean:
		@(cd $(LIBFT) && make clean)
		@(rm -rf $(OBJS))

fclean: clean
		@(cd $(LIBFT) && make fclean)
		@(rm -rf $(NAME))

re: fclean all