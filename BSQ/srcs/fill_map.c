/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 19:25:23 by mraymon           #+#    #+#             */
/*   Updated: 2019/03/19 19:35:18 by mraymon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdlib.h>

int					get_line_width(const char *content_str)
{
	int i;

	i = 0;
	while (!(content_str[i] == '\n' || content_str[i] == '\0'))
		i++;
	return (i);
}

void				allocate_2d_map(t_map_struct *result_map, int w, int h)
{
	int	i;

	i = 0;
	result_map->field = malloc(sizeof(int*) * h);
	while (i < h)
	{
		result_map->field[i] = malloc(sizeof(int) * w);
		i++;
	}
	result_map->w = w;
	result_map->h = h;
	result_map->need_free = 1;
	return ;
}

t_extract_status	fill_2d_map_from_str(t_map_struct *result_map,
		char *content_str)
{
	char	curr_char;
	int		i;
	int		j;

	i = -1;
	while (++i < result_map->h)
	{
		j = 0;
		while (j < result_map->w)
		{
			curr_char = *(content_str++);
			if (curr_char == result_map->empty_char)
				result_map->field[i][j] = 1;
			else if (curr_char == result_map->obstcl_char)
				result_map->field[i][j] = 0;
			else
				return (extract_error);
			j++;
		}
		if (*(content_str++) != '\n')
			return (extract_error);
	}
	if (*content_str != '\0')
		return (extract_error);
	return (extract_ok);
}

t_extract_status	fill_map_from_str(t_map_struct *result_map,
		int line_number, char *content_str)
{
	int line_with;

	if ((line_with = get_line_width(content_str)) == 0)
		return (extract_error);
	allocate_2d_map(result_map, line_with, line_number);
	if (fill_2d_map_from_str(result_map, content_str) == extract_error)
		return (extract_error);
	return (extract_ok);
}
