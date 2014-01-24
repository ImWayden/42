#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xmachado <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/17 20:21:15 by xmachado          #+#    #+#              #
#    Updated: 2014/01/24 00:11:48 by xmachado         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAGS = -Wall -Wextra -Werror
LIBFT = ./libft
FILES = minishell2.c tools.c
OBJS = $(FILES:.c=.o)
NAME = ft_minishell2

all: $(NAME)

$(NAME):
		make -C $(LIBFT)
		gcc $(FLAGS) -I libft/includes -c $(FILES)
		gcc -o $(NAME) $(OBJS) -L libft/ -lft

clean:
		@(cd $(LIBFT) && make clean)
		@(rm -rf $(OBJS))

fclean: clean
		@(cd $(LIBFT) && make fclean)
		@(rm -rf $(NAME))

re: fclean all