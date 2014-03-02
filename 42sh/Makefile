# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/22 14:52:23 by sraccah           #+#    #+#              #
#    Updated: 2014/02/24 11:55:22 by sraccah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh

MAKE = make
CC = gcc
RM = /bin/rm
LDIR = libft/
SDIR = srcs/

SRC = $(SDIR)main.c $(SDIR)ft_init.c $(SDIR)ft_get.c $(SDIR)env_builtin.c \
<<<<<<< HEAD
		$(SDIR)cd_builtin.c $(SDIR)ft_parselex.c
=======
		$(SDIR)cd_builtin.c $(SDIR)ft_parselex.c $(SDIR)termcap.c \
		$(SDIR)termcap1.c $(SDIR)needed.c\
>>>>>>> fc382db9c32f12bfa015c589a3e35834beacc415

OBJ = $(SRC:.c=.o)
INC = -I includes -I $(LDIR)includes
LIB = ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[31;1m"
	@echo -n '---> Creating the Libft... <---'
	@echo "\033[0m"
	$(MAKE) re -C $(LDIR)
	@echo "\033[31;1m"
	@echo -n '---> Compilation in progress... <---'
	@echo "\033[0m"
<<<<<<< HEAD
	$(CC) $(CFLAGS) $(INC) $^ -o $(NAME) $(LIB)
=======
	$(CC) $(CFLAGS) $(INC) $^ -o $(NAME) $(LIB) -ltermcap
>>>>>>> fc382db9c32f12bfa015c589a3e35834beacc415
	@echo "\033[1;32m"
	@echo -n '---> DONE ! <---'
	@echo "\033[0m"

%.o:%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@echo "\033[31;1m"
	@echo -n '---> Clean : <---'
	@echo "\033[0m"
	$(RM) -rf $(OBJ)
	$(MAKE) clean -C $(LDIR)
	@echo "\033[1;32m"
	@echo -n '---> DONE ! <---'
	@echo "\033[0m"

fclean: clean
	@echo "\033[31;1m"
	@echo -n '---> FClean : <---'
	@echo "\033[0m"
	$(RM) -rf $(NAME)
	$(MAKE) fclean -C $(LDIR)
	@echo "\033[1;32m"
	@echo -n '---> DONE ! <---'
	@echo "\033[0m"

re: fclean all

.PHONY: all name clean fclean re