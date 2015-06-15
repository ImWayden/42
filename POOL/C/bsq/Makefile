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

SDIR = srcs/
SRC = $(SDIR)ft_put.c $(SDIR)get_next_line.c $(SDIR)ft_strjoin.c \
	  $(SDIR)ft_strnew.c $(SDIR)ft_strsub.c $(SDIR)parser.c $(SDIR)ft_atoi.c \
	  $(SDIR)bsq.c $(SDIR)main.c

INC = -I includes
OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[31;1m"
	@echo -n '---> Compilation in progress... <---'
	@echo "\033[0m"
	$(CC) $(CFLAGS) $(INC) $^ -o $(NAME)
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

