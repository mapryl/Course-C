# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapryl <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/12 13:45:00 by mapryl            #+#    #+#              #
#    Updated: 2019/03/12 14:15:41 by mapryl           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=do-op
SRCS=srcs/do_op.c srcs/ft_atoi.c srcs/ft_add.c srcs/ft_div.c srcs/ft_mod.c srcs/ft_mul.c srcs/ft_sub.c srcs/ft_power.c
HEADERS=includes

all:
	gcc -Wall -Wextra -Werror $(SRCS) -I$(HEADERS) -o $(NAME)

clean:
	/bin/rm -f $(NAME)

re: clean all
