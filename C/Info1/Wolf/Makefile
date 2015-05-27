# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/22 14:52:23 by sraccah           #+#    #+#              #
#    Updated: 2014/11/06 21:44:36 by msarr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

MAKE = make
CC = gcc
RM = /bin/rm
LDIR = libft/
SDIR = srcs/

SRC = $(SDIR)main.c $(SDIR)draw.c $(SDIR)draw_floor.c $(SDIR)draw_sky.c \
	  $(SDIR)get_tex.c $(SDIR)get_map.c $(SDIR)moove.c $(SDIR)raycaster.c \
	  $(SDIR)key.c \

OBJ = $(SRC:.c=.o)
INC = -I includes -I $(LDIR)includes
LIB = ./libft/libft.a ./minilibx_macos/libmlx.a
DIR_LIBS = ./minilibx_macos
CFLAGS = -Wall -Wextra -Werror

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LDFLAGS += -L$(DIR_LIBS) -lmlx -lXext -lX11 -lm -lpthread
endif
ifeq ($(UNAME_S),Darwin)
	LDFLAGS += -L$(DIR_LIBS) -framework OpenGL -framework AppKit -lpthread
	INC += -I minilibx_macos
endif

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[31;1m"
	@echo -n '---> Creating the Libft... <---'
	@echo "\033[0m"
	$(MAKE) re -C $(LDIR)
	@echo "\033[31;1m"
	@echo -n '---> Compilation in progress... <---'
	@echo "\033[0m"
	$(CC) $(CFLAGS) $(INC) $^ -o $(NAME) $(LDFLAGS) $(LIB)
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