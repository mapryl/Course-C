/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 21:13:41 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/10 22:20:52 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "field.h"

void	set_array(int *array, int size, int value)
{
	int i;

	i = 0;
	while (i < size)
		array[i++] = value;
}

t_bool	check_row(t_cell field[][9], int row_number)
{
	int row[10];
	int i;

	set_array(row, 10, -1);
	i = 0;
	while (i < 9)
	{
		if (field[row_number][i].value != 0 &&
				row[field[row_number][i].value] != -1)
			return (FALSE);
		else
			row[field[row_number][i].value] = 1;
		i++;
	}
	return (TRUE);
}

t_bool	check_column(t_cell field[][9], int column_number)
{
	int column[10];
	int i;

	set_array(column, 10, -1);
	i = 0;
	while (i < 9)
	{
		if (field[i][column_number].value != 0 &&
				column[field[i][column_number].value] != -1)
			return (FALSE);
		else
		{
			column[field[i][column_number].value] = 1;
		}
		i++;
	}
	return (TRUE);
}

t_bool	check_square(t_cell field[][9], int i, int j)
{
	int square[10];
	int ii;
	int jj;

	i /= 3;
	j /= 3;
	set_array(square, 10, -1);
	ii = 0;
	while (ii < 3)
	{
		jj = 0;
		while (jj < 3)
		{
			if (field[i * 3 + ii][j * 3 + jj].value != 0 &&
					square[field[i * 3 + ii][j * 3 + jj].value] != -1)
				return (FALSE);
			else
				square[field[i * 3 + ii][j * 3 + jj].value] = 0;
			jj++;
		}
		ii++;
	}
	return (TRUE);
}

void	copy_field(t_cell source[][9], t_cell destination[][9])
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			destination[i][j] = source[i][j];
			j++;
		}
		i++;
	}
}
