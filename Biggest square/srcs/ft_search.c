/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:08:19 by mraymon           #+#    #+#             */
/*   Updated: 2019/03/19 19:44:18 by mraymon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int		min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	else
		return (c);
}

void	ft_check_zero(int **field, t_square *answer, int h, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (answer->size < field[0][i])
		{
			answer->size = field[0][i];
			answer->i = i;
			answer->j = 0;
		}
		i++;
	}
	i = 0;
	while (i < h)
	{
		if (answer->size < field[i][0])
		{
			answer->size = field[i][0];
			answer->i = 0;
			answer->j = i;
		}
		i++;
	}
}

void	ft_search(int **field, t_square *answer, int h, int n)
{
	int i;
	int j;

	j = 1;
	answer->size = 0;
	ft_check_zero(field, answer, h, n);
	while (j < h)
	{
		i = 1;
		while (i < n)
		{
			if (field[j][i] != 0)
				field[j][i] += min(field[j][i - 1],
						field[j - 1][i], field[j - 1][i - 1]);
			if (answer->size < field[j][i])
			{
				answer->size = field[j][i];
				answer->i = (i - (answer->size - 1));
				answer->j = (j - (answer->size - 1));
			}
			i++;
		}
		j++;
	}
}
