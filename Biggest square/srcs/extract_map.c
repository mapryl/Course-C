/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 19:13:57 by mraymon           #+#    #+#             */
/*   Updated: 2019/03/20 16:17:54 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "fill_map.h"

int					ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if ((s1[i] == '\0' && s2[i] != '\0') || (s2[i] == '\0' && s1[i] != '\0'))
		return (s1[i] - s2[i]);
	return (0);
}

int					ft_atoi(char **str, char *end)
{
	int	result;

	while (*str != end && (**str == ' ' || **str == '\t' ||
				**str == '\r' || **str == '\n'))
		(*str)++;
	result = 0;
	if (**str == '+')
	{
		(*str)++;
	}
	while (*str != end && ((**str >= '0' && **str <= '9')))
	{
		result = (result * 10) + (**str - '0');
		(*str)++;
	}
	return (result);
}

int					get_line_numbers(char **str)
{
	char	*begin;
	int		result;

	begin = *str;
	while (**str != '\0' && **str != '\n')
		(*str)++;
	if (**str == '\0')
		return (-1);
	*str -= 3;
	result = ft_atoi(&begin, *str);
	if (ft_strcmp(begin, *str) != 0)
		return (-1);
	return (result);
}

t_extract_status	get_special_chars(t_map_struct *result_map,
		char **content_str)
{
	int		i;
	char	*check_size_str;

	check_size_str = content_str[0];
	i = 0;
	while (check_size_str[i] != '\n')
	{
		if (check_size_str[i] == '\0')
			return (extract_error);
		i++;
	}
	if (i != 3)
		return (extract_error);
	result_map->empty_char = **content_str;
	(*content_str)++;
	result_map->obstcl_char = **content_str;
	(*content_str)++;
	result_map->full_char = **content_str;
	(*content_str)++;
	if (result_map->empty_char == result_map->full_char ||
			result_map->empty_char == result_map->obstcl_char ||
	result_map->obstcl_char == result_map->full_char)
		return (extract_error);
	(*content_str)++;
	return (extract_ok);
}

t_extract_status	try_extract_map(t_map_struct *result_map, char *content_str)
{
	int line_number;

	if ((line_number = get_line_numbers(&content_str)) <= 0)
		return (extract_error);
	if (get_special_chars(result_map, &content_str) == extract_error)
		return (extract_error);
	if (fill_map_from_str(result_map, line_number,
				content_str) == extract_error)
		return (extract_error);
	return (extract_ok);
}
