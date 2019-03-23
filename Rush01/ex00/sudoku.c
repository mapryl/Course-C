/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 21:05:38 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/10 22:21:41 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"
#include "field.h"

t_bool			check(t_cell field[][9], int i, int j)
{
	return (check_column(field, j) && check_row(field, i) &&
			check_square(field, i, j));
}

typedef enum	e_fill_result
{
	fill_ok,
	fill_error,
	fill_complete
}				t_fill_result;

t_fill_result	fill_cell(t_cell field[][9], int *i, int *j)
{
	while (TRUE)
	{
		field[*i][*j].value += 1;
		if (field[*i][*j].value > 9)
		{
			field[*i][*j].value = 0;
			return (fill_error);
		}
		if (check(field, *i, *j))
		{
			*j += 1;
			return (fill_ok);
		}
	}
}

t_fill_result	fill(t_cell field[][9], int *i, int *j)
{
	while (*i < 9)
	{
		while (*j < 9)
		{
			if (field[*i][*j].set)
			{
				*j += 1;
				continue;
			}
			return (fill_cell(field, i, j));
		}
		*i += 1;
		*j = 0;
	}
	return (fill_complete);
}

t_bool			unfill(t_cell field[][9], int *i, int *j)
{
	*j -= 1;
	while (*i >= 0)
	{
		while (*j >= 0)
		{
			if (field[*i][*j].set)
			{
				*j -= 1;
				continue;
			}
			else
			{
				return (TRUE);
			}
		}
		*i -= 1;
		*j = 8;
	}
	return (FALSE);
}

t_bool			find_solution(t_cell field[][9], t_cell solution[][9])
{
	t_bool			solution_found;
	int				i;
	int				j;
	t_fill_result	fill_result;

	solution_found = FALSE;
	i = 0;
	j = 0;
	while (TRUE)
	{
		while ((fill_result = fill(field, &i, &j)) == fill_ok)
			;
		if (fill_result == fill_complete)
		{
			if (solution_found)
				return (FALSE);
			solution_found = TRUE;
			copy_field(field, solution);
		}
		if (!unfill(field, &i, &j))
			return (solution_found);
	}
	return (FALSE);
}
