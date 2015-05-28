# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/22 14:52:23 by sraccah           #+#    #+#              #
#    Updated: 2015/05/03 16:38:18 by sraccah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = arkanoid

MAKE = make
CC = clang
GIT = git
RM = rm
RMF = rm -rf
LDIR = libft/
GDIR = glfw/
SDIR = srcs/
SDDIR = srcs/draw/
SIDIR = srcs/init/

SRC = $(SDIR)main.c \
		$(SDDIR)draw.c \
		$(SIDIR)init.c \
		$(SIDIR)callback.c \
		$(SIDIR)render.c

OBJ = $(SRC:.c=.o)
INC = -I includes -I $(LDIR)includes
GINC = -I glfw/include
LIB = ./libft/libft.a
LIBS =  -lglfw  -lglut -lGL -lGLU -lpthread -lm
CFLAGS = -Wall -Wextra -Werror -Wno-deprecated-declarations
R = \033[31;1m
G = \033[32;1m
Y = \033[33;1m
B = \033[34;1m
P = \033[35;1m
C = \033[36;1m
Z = \033[0m
A = $(R)[$(B)$(NAME)$(R)]----->\033[0m

all: $(NAME)

glfw:
	@git submodule add --force https://github.com/glfw/glfw.git glfw

glfw/Makefile:
	@cd glfw ; cmake . ; cd ../

glfw/src/libglfw3.a: glfw glfw/Makefile
	@$(MAKE) -C $(GDIR)

$(NAME): glfw/src/libglfw3.a $(OBJ)
	@$(MAKE) re -C $(LDIR)
	@$(CC) $(CFLAGS) $(INC) $(GINC) $^ -o $(NAME) $(LIB) $(LIBS)
	@echo "$(A)$(R)[$(Y)Compilation$(R):$(G) DONE$(R)] ✅$(Z)"
	@echo "\n$(Y)-----------------------------------"
	@echo "$(Y)------- $(R)[$(B)$(NAME) $(G)created$(R)] 💟$(Y) ------$(Z)"
	@echo "$(Y)-----------------------------------"
	@echo "\n$(Y)------------ $(P)Enjoy $(C);)$(Y) -------------$(Z)"

%.o:%.c
	@$(CC) $(CFLAGS) $(INC) $(GINC) -c $< -o $@

clean:
	@$(RM) -rf $(OBJ)
	@$(MAKE) clean -C $(LDIR)
	@echo "$(R)[$(Y)Clean$(R): $(G)DONE$(R)] ❌$(Z)"

fclean: clean
	@$(RM) -rf $(NAME)
	@$(MAKE) fclean -C $(LDIR)
	@$(RMF) $(GDIR)
	@$(GIT) $(RMF) --ignore-unmatch $(GDIR)
	@echo "$(R)[$(Y)Fclean$(R): $(G)DONE$(R)] ❌$(Z)"

re: fclean all

.PHONY: all name clean fclean re
