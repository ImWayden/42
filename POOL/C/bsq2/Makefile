# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msarr <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/07/22 13:02:29 by msarr             #+#    #+#              #
#    Updated: 2014/07/22 13:02:34 by msarr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

MAKE = make
CC = gcc
RM = /bin/rm
LDIR = libft/
SDIR = srcs/
SRC = $(SDIR)parser.c $(SDIR)bsq.c $(SDIR)main.c

INC = -I includes -I $(LDIR)/includes
OBJ = $(SRC:.c=.o)
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
	@echo "\033[1;32m"
	@echo -n '---> DONE ! <---'
	@echo "\033[0m"

%.o:%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all re name clean fclean

