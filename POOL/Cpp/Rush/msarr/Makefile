
NAME		= ft_retro
SRC			= main.cpp \
				Window.class.cpp \
				Game.class.cpp \
				Character.class.cpp \
				Background.class.cpp

OBJ			= $(SRC:.cpp=.o)
CC			= /usr/bin/clang++
CFLAGS		= -Wall -Wextra -Werror -lncurses
RM			= /bin/rm -f
ECHO			= /bin/echo -e

$(NAME)	:		$(OBJ)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
				@$(ECHO) '> Compiled'

clean	:
				-@$(RM) $(OBJ)
				@$(ECHO) '> Directory cleaned'

all		:		$(NAME)

fclean	:		clean
				-@$(RM) $(NAME)
				@$(ECHO) '> Remove executable'

re		:		fclean all

.PHONY	:		all clean re

debug	:		$(OBJ)
				@$(CC) $(INC) $(CDEBUG) -o $(NAME) $(OBJ)
				@$(ECHO) '> Mode Debug: done'

.c.o	:
				$(CC) $(CFLAGS) -o $@ -c $<
