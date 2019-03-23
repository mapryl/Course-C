/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 21:09:35 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/10 22:31:56 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"
#include <unistd.h>

int		sudoku_atoi(char c)
{
	if (c >= '1' && c <= '9')
	{
		return (c - '0');
	}
	else if (c == '.')
		return (0);
	else
		return (-1);
}

char	sudoku_itoa(int i)
{
	if (i == 0)
		return ('.');
	else
		return ('0' + i);
}

t_bool	parse(t_cell field[][9], int argc, char **argv)
{
	int i;
	int j;
	int casted;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (j == 9)
				return (FALSE);
			casted = sudoku_atoi(argv[i][j]);
			if (casted == -1)
				return (FALSE);
			field[i - 1][j].value = casted;
			field[i - 1][j].set = (casted > 0);
			j++;
		}
		if (j < 9)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	print_field(t_cell field[][9])
{
	int		i;
	int		j;
	char	z;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			z = sudoku_itoa(field[i][j++].value);
			write(1, &z, 1);
			if (j < 9)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_cell field[9][9];
	t_cell solution[9][9];

	if (argc != 10)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	if (!parse(field, argc, argv))
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	if (find_solution(field, solution))
		print_field(solution);
	else
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	return (0);
}
