# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msarr <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/21 13:57:19 by msarr             #+#    #+#              #
#    Updated: 2013/11/21 13:57:22 by msarr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libft.a

SRC 	=	./includes/*.c

HEAD	=	./includes/libft.h

OBJS 	=	ft_memset.o ft_bzero.o ft_memcpy.o  ft_memccpy.o  ft_memmove.o \
	 		ft_strlen.o  ft_strdup.o ft_strcpy.o ft_strncpy.o ft_strcat.o \
	 		ft_strncat.o ft_strchr.o ft_strstr.o ft_strrchr.o ft_strnstr.o \
	 		ft_strcmp.o ft_strncmp.o ft_atoi.o ft_isalpha.o ft_isdigit.o \
	 		ft_isalnum.o ft_isascii.o ft_isprint.o ft_tolower.o ft_memchr.o \
	 		ft_memcmp.o ft_strlcat.o ft_toupper.o ft_putstr.o ft_putchar.o\
	 		ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o ft_strclr.o \
			ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o	\
			ft_strnequ.o ft_strsub.o ft_strjoin.o ft_strtrim.o ft_strsplit.o \
			ft_itoa.o ft_putchar.o ft_putstr.o ft_putendl.o	ft_putnbr.o \
			ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o\
			ft_strrealloc.o

FLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): 
	gcc $(FLAGS) -c $(HEAD) $(SRC)
	ar rc $(NAME) $(OBJS)

fclean: clean
	/bin/rm -f $(NAME) ./includes/libft.h.gch

clean:
	/bin/rm -f	$(OBJS)

re: fclean all
	