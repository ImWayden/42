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
BDIR = srcs/bckgrd/
FDIR = srcs/fractal/
F3DIR = srcs/fractal_3D/
IDIR = srcs/init/
DDIR = srcs/draw/
CDIR = srcs/colors/
EDIR = srcs/exit/

SRC = $(SDIR)main.c \
	  $(MXDIR)expose.c  $(MXDIR)mouse.c \
	  $(CPDIR)ope.c \
	  $(CDIR)color.c $(CDIR)conversion.c $(CDIR)linear.c \
	  $(CDIR)style.c $(CDIR)ope.c $(CDIR)lifted.c\
	  $(IDIR)init.c $(IDIR)thread.c $(IDIR)coeff.c $(IDIR)pixel.c $(IDIR)color.c\
	  $(PDIR)plotpixel.c \
	  $(FDIR)mandel.c $(FDIR)julia.c $(FDIR)buddha.c  $(FDIR)conf.c $(FDIR)render.c \
	  $(F3DIR)pyramid.c \
	  $(BDIR)bckgrd.c $(BDIR)bckgrd1.c $(BDIR)bckgrd2.c $(BDIR)bckgrd3.c $(BDIR)bckgrd4.c \
	  $(BDIR)bckgrd5.c $(BDIR)bckgrd6.c $(BDIR)bckgrd7.c $(BDIR)bckgrd8.c $(BDIR)bckgrd9.c\
	  $(EDIR)exit.c

OBJ = $(SRC:.c=.o)
INC = -I includes -I $(LDIR)includes -I minilibx_macos
LIB = ./libft/libft.a ./minilibx_macos/libmlx.a
DIR_LIBS = ./minilibx_macos
LDFLAGS += -L$(DIR_LIBS) -framework OpenGL -framework AppKit -lpthread
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[31;1m"
	@echo -n '---> Compiling Minilibx... <---'
	@echo "\033[0m"
	$(MAKE) re -C ./minilibx_macos
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