/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 12:24:30 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/12 18:09:11 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "../includes/ft_util.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long long nb_new;

	nb_new = nb;
	if (nb_new < 0)
	{
		ft_putchar('-');
		nb_new = -nb_new;
	}
	if (nb_new >= 10)
	{
		ft_putnbr(nb_new / 10);
		ft_putnbr(nb_new % 10);
	}
	else
	{
		ft_putchar(nb_new + '0');
	}
}

int		choose_operation(char *operator)
{
	if (operator[0] == '+' && operator[1] == '\0')
		return (0);
	if (operator[0] == '-' && operator[1] == '\0')
		return (1);
	if (operator[0] == '*')
	{
		if (operator[1] == '*')
			return (5);
		return (2);
	}
	if (operator[0] == '/' && operator[1] == '\0')
		return (3);
	if (operator[0] == '%' && operator[1] == '\0')
		return (4);
	return (-1);
}

int		calculate(int a, int b, int operation)
{
	int (*operations[6])(int, int);

	operations[0] = &ft_add;
	operations[1] = &ft_sub;
	operations[2] = &ft_mul;
	operations[3] = &ft_div;
	operations[4] = &ft_mod;
	operations[5] = &ft_power;
	return ((*operations[operation])(a, b));
}

int		main(int argc, char **argv)
{
	int result;
	int operator;

	if (argc != 4)
		return (-1);
	operator = choose_operation(argv[2]);
	if (operator == -1)
	{
		write(1, "0\n", 2);
		return (-1);
	}
	else if (operator == 3 && ft_atoi(argv[3]) == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (-1);
	}
	else if (operator == 4 && ft_atoi(argv[3]) == 0)
	{
		write(1, "Stop: modulo by zero\n", 22);
		return (-1);
	}
	result = calculate(ft_atoi(argv[1]), ft_atoi(argv[3]), operator);
	ft_putnbr(result);
	ft_putchar('\n');
	return (0);
}
