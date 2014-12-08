# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/22 14:52:23 by msarr             #+#    #+#              #
#    Updated: 2014/12/07 22:36:54 by msarr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = lemin

MAKE = make
CC = gcc
RM = /bin/rm
LDIR = libft/
SDIR = srcs/
FDIR = fdf/

SRC = $(SDIR)link.c $(SDIR)parser.c $(SDIR)room.c $(SDIR)way.c $(SDIR)lemin.c \
	  $(SDIR)lexer.c \
	  $(FDIR)init.c $(FDIR)mlx.c $(FDIR)fdf.c $(FDIR)draw_line.c \
	  $(SDIR)main.c

OBJ = $(SRC:.c=.o)
INC = -I includes -I $(LDIR)/includes
LIB = ./libft/libft.a
DIR_LIBS = /usr/X11/lib 
LDFLAGS += -L$(DIR_LIBS) -lmlx -lXext -lX11 -lm
CFLAGS = -Wall -Wextra -Werror -g 

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