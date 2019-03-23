/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_answer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 19:41:28 by mraymon           #+#    #+#             */
/*   Updated: 2019/03/19 20:24:32 by mraymon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "struct.h"

void	ft_print_answer(t_map_struct *map, t_square *answer, int h,
		int n)
{
	int		i;
	int		j;
	int		t;
	char	*text;

	j = 0;
	t = 0;
	text = (char*)malloc(sizeof(char) * h * (n + 1));
	while (j < h)
	{
		i = -1;
		while (++i < n)
			if ((i >= answer->i && i <= (answer->i + (answer->size - 1))) &&
					(j >= answer->j && j <= (answer->j + (answer->size - 1))))
				text[t++] = map->full_char;
			else if (map->field[j][i] == 0)
				text[t++] = map->obstcl_char;
			else
				text[t++] = map->empty_char;
		text[t++] = '\n';
		j++;
	}
	write(1, text, (h * (n + 1)));
	free(text);
}
