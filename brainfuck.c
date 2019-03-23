/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:58:41 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/16 19:54:18 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int		main(int argc, char **argv)
{
	if (argc != 2)
		{
			write(1, "\n", 1);
			return (0);
		}
	int i = 0;
	int pointer = 0;
	char point_ar[2048];

	for (int j = 0; j < 2048; j++)
		point_ar[i] = 0;

	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == '>')
			pointer += 1;
		else if (argv[1][i] == '<')
			pointer -= 1;
		else if (argv[1][i] == '+')
			point_ar[pointer] += 1;
		else if (argv[1][i] == '-')
			point_ar[pointer] -= 1;
		else if (argv[1][i] == '.')
			write(1, &point_ar[pointer], 1);
		else if (argv[1][i] == '[')
		{
			if (point_ar[pointer] == 0)
			{
				while (argv[1][i] != ']' && argv[1][i] != '\0')
					i++;
			}
		}
		else if (argv[1][i] == ']')
		{
			if (point_ar[pointer] != 0)
			{
				while (argv[1][i] != '[' && argv[1][i] != '\0')
					i--;
			}
		}
		if (argv[1][i] != '\0')
			i++;
	}
	return (0);
}
