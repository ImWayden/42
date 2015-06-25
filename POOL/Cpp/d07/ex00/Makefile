# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msarr <msarr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/25 16:59:32 by msarr             #+#    #+#              #
#    Updated: 2015/06/25 16:59:32 by msarr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00
SRC = ex00.cpp
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
