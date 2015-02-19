# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msarr <msarr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/20 14:23:13 by msarr             #+#    #+#              #
#    Updated: 2015/01/20 14:23:13 by msarr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

MAKE = make
CC = gcc
RM = /bin/rm
LDIR = libft/
SDIR = srcs/
CPDIR = srcs/complex/
MXDIR = srcs/mlx/
PDIR = srcs/pixels/
MDIR = srcs/fractal/mandel-julia/
FDIR = srcs/fractal/flame/
F3DIR = srcs/fractal_3D/
IDIR = srcs/init/
DDIR = srcs/draw/
CDIR = srcs/colors/

SRC = $(SDIR)main.c \
	  $(MXDIR)expose.c  $(MXDIR)mouse.c \
	  $(CPDIR)ope.c \
	  $(CDIR)color.c $(CDIR)map.c $(CDIR)conversion.c $(CDIR)linear.c \
	  $(CDIR)style.c $(CDIR)ope.c $(CDIR)lifted.c\
	  $(IDIR)init.c $(IDIR)intervals.c \
	  $(F3DIR)pyramid.c \
	  $(PDIR)plotpixel.c \
	  $(MDIR)mandel.c $(MDIR)julia.c $(MDIR)conf.c $(MDIR)main.c \
	  $(FDIR)funct.c $(FDIR)main.c \

OBJ = $(SRC:.c=.o)
INC = -I includes -I $(LDIR)includes -I /opt/X11/include
LIB = ./libft/libft.a
DIR_LIBS = /opt/X11/lib
LDFLAGS += -L$(DIR_LIBS) -lmlx -lXext -lX11 -lm
CFLAGS = -Wall -Werror -Wextra

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