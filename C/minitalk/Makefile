# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleger <aleger@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/07 23:06:32 by aleger            #+#    #+#              #
#    Updated: 2014/02/09 01:28:52 by aleger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1		= serveur
NAME_2		= client

SRC_1		= serveur.c

SRC_2		= client.c

INC			= -I libft/inc/				\
			  -I inc/

LIB			= -L libft/ -lft

CC			= gcc
FLAGS		= -Wall -Werror -Wextra -pedantic -O3
SRC_P		= src/

SRC_F_1		= $(addprefix $(SRC_P),$(SRC_1))
OBJ_1		= $(patsubst %.c,%.o,$(SRC_F_1))

SRC_F_2		= $(addprefix $(SRC_P),$(SRC_2))
OBJ_2		= $(patsubst %.c,%.o,$(SRC_F_2))


$(NAME_1)	: $(OBJ_1)
	$(CC) $(FLAGS) -o $(NAME_1) $^ $(INC) $(LIB)

$(NAME_2)	: $(OBJ_2)
	$(CC) $(FLAGS) -o $(NAME_2) $^ $(INC) $(LIB)

%.o			: %.c
	$(CC) $(FLAGS) -c $^ -o $@ $(INC)

all			: lib $(NAME_1) $(NAME_2)

lib			:
	@make -C libft/

clean		:
	@make clean -C libft/
	@/bin/rm -f $(OBJ_1)
	@/bin/rm -f $(OBJ_2)
	@/bin/rm -f libft.h.gch

fclean		: clean
	@make fclean -C libft/
	@/bin/rm -f libft.h.gch
	@/bin/rm -f $(NAME_1)
	@/bin/rm -f $(NAME_2)

re			: fclean all
.PHONY: all clean fclean re
