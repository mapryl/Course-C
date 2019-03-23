# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapryl <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 16:39:20 by mapryl            #+#    #+#              #
#    Updated: 2019/03/11 16:56:06 by mapryl           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SOURCE=srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
BINARY=ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
HEADERS=includes

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -I$(HEADERS) -c $(SOURCE)
	ar rc $(NAME) $(BINARY)
	ranlib $(NAME)

clean:
	/bin/rm -f $(BINARY)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
