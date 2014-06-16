# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/22 14:52:23 by sraccah           #+#    #+#              #
#    Updated: 2014/06/13 18:33:32 by mozzie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh

MAKE = make
CC = gcc
RM = /bin/rm
LDIR = libft/
SDIR = srcs/
BDIR = srcs/builtins/
FDIR = srcs/free_functions/
PDIR = srcs/lexer_parser/

SRC = $(SDIR)main.c \
	  $(BDIR)env_to_list.c $(BDIR)aff_env.c $(BDIR)my_setenv.c $(BDIR)my_unsetenv.c\
	  $(FDIR)free_env.c \
	  $(PDIR)grammar.c $(PDIR)grammar1.c $(PDIR)redir_syntax.c $(PDIR)syntax_error.c\
	  $(PDIR)lexer.c


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
	$(CC) $(CFLAGS) $(INC) $^ -o $(NAME) $(LIB) -ltermcap
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