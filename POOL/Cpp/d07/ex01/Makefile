# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msarr <msarr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/25 17:01:29 by msarr             #+#    #+#              #
#    Updated: 2015/06/25 17:01:29 by msarr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01
SRC = iter.cpp
OBJ = $(SRC:.cpp=.o)
FLAG = -Wall -Wextra -Werror
all : $(NAME)
$(NAME) : $(OBJ)
	g++ $(FLAG) $(OBJ) -o $(NAME)
%.o: %.cpp
	g++ $(FLAG) -c $^
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all
