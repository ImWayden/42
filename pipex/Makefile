#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scohen <scohen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/30 12:12:11 by scohen            #+#    #+#              #
#    Updated: 2013/12/30 16:47:17 by scohen           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = pipex

SRC = ft_pipex.c ft_strsub.c ft_strsplit.c ft_strjoin.c \
	  ft_strlen.c ft_bzero.c ft_father.c ft_son.c

OBJECT = $(SRC:.c=.o)

HEAD = ft_pipex.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(HEAD) $(SRC)
	gcc $(FLAGS) -o $(NAME) $(OBJECT)

clean:
	rm -f $(OBJECT)

fclean : clean
	rm -f $(NAME)

re: fclean all
