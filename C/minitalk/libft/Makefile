# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleger <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 02:37:43 by aleger            #+#    #+#              #
#    Updated: 2014/02/07 02:41:13 by aleger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRC			= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			  ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c \
			  ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
			  ft_lstsplit.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
			  ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
			  ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
			  ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
			  ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
			  ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
			  ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
			  ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
			  ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c \
			  ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
			  ft_wordcount.c ft_realloc.c get_next_line.c pcase.c pcase2.c \
			  printf_utils.c ft_printf.c ft_strnjoin.c ft_nbrlen.c \
			  ft_tablen.c ft_abs.c ft_dump_tab.c ft_strpos.c

INC			= -I inc/

CC			= gcc
FLAGS		= -Wall -Werror -Wextra -pedantic
SRC_P		= src/
SRC_F		= $(addprefix $(SRC_P),$(SRC))
OBJ			= $(patsubst %.c,%.o,$(SRC_F))



%.o			: %.c
	$(CC) -c $^ -o $@ $(FLAGS) $(INC)

$(NAME)		: $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@rm -f $(OBJ)

all			: $(NAME)

clean		:
	@rm -f $(OBJ)

fclean		: clean
	@rm -f $(NAME)

re			: fclean all

.PHONY: all fclean clean re
