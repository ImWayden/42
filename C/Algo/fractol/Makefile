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
	  \
	  $(MXDIR)key_hook.c  $(MXDIR)mouse_press.c  $(MXDIR)loop_hook.c $(MXDIR)mouse_motion.c\
	  \
	  $(CPDIR)complex.c $(CPDIR)ope.c $(CPDIR)ope1.c $(CPDIR)ope2.c  $(CPDIR)transform.c \
	  \
	  $(CDIR)color.c $(CDIR)conversion.c $(CDIR)linear.c $(CDIR)orbitrap.c\
	  $(CDIR)style.c $(CDIR)ope.c $(CDIR)lifted.c $(CDIR)basecolor.c $(CDIR)phase.c\
	  \
	  $(IDIR)init.c $(IDIR)thread.c $(IDIR)coeff.c $(IDIR)pixel.c \
	  $(IDIR)color.c $(IDIR)background.c $(IDIR)args.c $(IDIR)img.c\
	  \
	  $(PDIR)plotpixel.c \
	  \
	  $(FDIR)/mandel/mandel.c $(FDIR)/mandel/julia.c $(FDIR)/mandel/buddha.c \
	  $(FDIR)/mandel/newton.c\
	  $(FDIR)render.c $(FDIR)trender.c \
	  $(FDIR)/utils/get_arg.c $(FDIR)/utils/get_color.c \
	  $(FDIR)/burn/burningship.c\
	  $(FDIR)/sierp/sierpinski.c\
	  \
	  $(F3DIR)render_3d.c \
	  \
	  $(BDIR)bckgrd.c $(BDIR)bckgrd1.c $(BDIR)bckgrd2.c $(BDIR)bckgrd3.c \
	  $(BDIR)bckgrd4.c $(BDIR)bckgrd5.c $(BDIR)bckgrd6.c $(BDIR)bckgrd7.c \
	  $(BDIR)bckgrd8.c $(BDIR)bckgrd9.c \
	  \
	  $(EDIR)exit.c

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LDFLAGS += -L$(DIR_LIBS) -lmlx -lXext -lX11 -lm -lpthread
endif
ifeq ($(UNAME_S),Darwin)
	LDFLAGS += -L$(DIR_LIBS) -framework OpenGL -framework AppKit -lpthread
	INC = -I minilibx_macos
	LIB += ./minilibx_macos/libmlx.a
endif
OBJ = $(SRC:.c=.o)
INC += -I includes -I $(LDIR)includes 
LIB += ./libft/libft.a
DIR_LIBS = ./minilibx_macos

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
ifeq ($(UNAME_S),Darwin)
	@echo "\033[31;1m"
	@echo -n '---> Compiling Minilibx... <---'
	@echo "\033[0m"
	$(MAKE) re -C ./minilibx_macos
	@echo "\033[31;1m"
endif
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
	$(RM) -rf ./minilibx_macos/*.o
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