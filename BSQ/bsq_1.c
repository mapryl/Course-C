/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSQ_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 19:04:40 by mraymon           #+#    #+#             */
/*   Updated: 2019/03/19 20:19:09 by mraymon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
//#include <unistd.h>
#include <fcntl.h>
#include "struct.h"
#include "test.h"
#include "extract_map.h"
#include "utils.h"
 

char	*get_file_content(FILE* file_desc)
{
	const int	buffer_size = 1024;
	char		*buffer;
	char		*result;
	int			chars_read;

	chars_read = 0;
	buffer = malloc(sizeof(char) * buffer_size + 1);
	result = malloc(sizeof(char));
	result[0] = '\0';
	//while ((chars_read = read(file_desc, buffer, buffer_size)))
	while (chars_read = fread(buffer, sizeof(char), buffer_size, file_desc))
	{
		buffer[chars_read] = '\0';
		result = concat(result, buffer);
	}
	free(buffer);
	return (result);
}

void	deallocate_2d_map(t_map_struct *result_map)
{
	int i;

	i = 0;
	while (i < result_map->h)
	{
		free(result_map->field[i]);
		i++;
	}
	free(result_map->field);
	result_map->need_free = 0;
	return ;
}

void	try_solve(char *file_content)
{
	t_map_struct	map;
	t_square		*answer;

	map.need_free = 0;
	if (try_extract_map(&map, file_content) == extract_ok)
	{
		answer = ft_create_answer();
		ft_search(map.field, answer, map.h, map.w);
		ft_print_answer(&map, answer, map.h, map.w);
	}
	else
		print_error();
	if (map.need_free)
		deallocate_2d_map(&map);
	return ;
}

void	input_from_stdin(void)
{
	char *content;

	content = get_file_content(0);
	try_solve(content);
	free(content);
	return ;
}

int		main(int argc, char **argv)
{
	FILE*		fd;
	char	*content;
	int		i;

	i = 1;
	if (argc == 1)
	{
		input_from_stdin();
	}
	while (i < argc)
	{
		if ((fd = fopen(argv[i], "r")) == 0)
		//if ((fd = open(argv[i], O_RDONLY)) == -1)
		{
			print_error();
			i++;
			continue ;
		}
		content = get_file_content(fd);
		try_solve(content);
		free(content);
		fclose(fd);
		i++;
	}
	return (0);
}
