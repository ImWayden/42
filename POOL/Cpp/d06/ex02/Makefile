# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msarr <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/24 15:30:51 by msarr             #+#    #+#              #
#    Updated: 2015/06/24 15:30:53 by msarr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex02
SRC = main.cpp \
	BClass.cpp \
	AClass.cpp \
	CClass.cpp \
	baseClass.cpp
OBJ = $(SRC:.cpp=.o)
FLAG = -Wall -Werror -Wextra
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
