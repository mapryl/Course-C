/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 21:40:16 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/01 21:53:48 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_integer_table(int *tab, int size)
{
	int i;
	int j;
	int buf;

	i = 0;
	j = 0;
	buf = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				buf = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = buf;
			}
			j++;
		}
		i++;
	}
}
