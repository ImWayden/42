# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/22 14:52:23 by sraccah           #+#    #+#              #
#    Updated: 2014/12/01 02:52:09 by msarr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = raytracer

MAKE = make
CC = gcc
RM = /bin/rm
LDIR = libft/
SDIR = srcs/
LIDIR = srcs/light/
PDIR = srcs/parser/
VDIR = srcs/vector/
RDIR = srcs/ray/
ODIR = srcs/object/

SRC = $(SDIR)main.c $(SDIR)expose.c \
	  $(VDIR)vector.c \
	  $(LIDIR)light.c \
	  $(ODIR)center.c $(ODIR)sphere.c\
	  $(PDIR)init.c $(PDIR)get_cam.c $(PDIR)get_pos.c $(PDIR)get_nbr.c \
	  $(PDIR)get_file.c $(PDIR)get_sphere.c $(PDIR)get_obj.c $(PDIR)get_spot.c\
	  $(RDIR)raytracer.c $(RDIR)color.c $(RDIR)noise.c $(RDIR)shaddow.c $(RDIR)reflection.c

OBJ = $(SRC:.c=.o)
INC = -I includes -I $(LDIR)includes
LIB = ./libft/libft.a
DIR_LIBS = /opt/X11/lib
LDFLAGS += -L$(DIR_LIBS) -lmlx -lXext -lX11 -lm
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