# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/22 14:52:23 by sraccah           #+#    #+#              #
#    Updated: 2014/10/08 19:48:49 by msarr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell1

MAKE = make
CC = gcc
RM = /bin/rm
LDIR = libft/
SDIR = srcs/
BDIR = srcs/builtins/
IDIR = srcs/init/
EDIR = srcs/execution/
FDIR = srcs/free_functions/

SRC = $(SDIR)shell.c \
	  $(EDIR)execution.c \
	  $(BDIR)env_to_list.c $(BDIR)aff_env.c $(BDIR)setenv.c $(BDIR)unsetenv.c\
	  $(BDIR)get_env.c $(BDIR)builtins_center.c $(BDIR)cd.c $(BDIR)env_to_tab.c\
	  $(BDIR)pwd.c\
	  $(BDIR)exit.c\
	  $(IDIR)ft_init.c \
	  $(FDIR)free_env.c $(FDIR)free_shell.c \

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
	$(CC) $(CFLAGS) $(INC) $^ -o $(NAME) $(LIB)
	$(CC) $(CFLAGS) $(INC) $^ -o $(NAME) $(LIB)
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