# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msarr <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/15 15:42:15 by msarr             #+#    #+#              #
#    Updated: 2015/06/15 15:42:17 by msarr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

MAKE = make
CC = clang++
RM = /bin/rm


SRC = main.cpp Contact.class.cpp Phonebook.class.cpp
OBJ = $(SRC:.cpp=.o)
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) -rf $(OBJ)

fclean: clean
	$(RM) -rf $(NAME)

re: fclean all

.PHONY: all name clean fclean re
