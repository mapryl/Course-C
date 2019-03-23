/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:18:28 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/07 23:41:55 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		words_counter(char *str)
{
	int		words_num;
	int		i;
	int		first;

	words_num = 0;
	first = 0;
	while (str[first] != '\0' && (str[first] == ' ' || str[first] == '\t'  || str[first] == '\n'))
		first++;
	i = first;
	while (str[i] != '\0')
	{
		i++;
		if (str[i] != '\0' && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
		{
			i++;
			words_num++;
			while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
				i++;
		}
	}
	if (str[i - 1] != ' ' && str[i - 1] != '\t' && str[i - 1] != '\n')
	{
		words_num += 1;
	}
	return (words_num);
}

char **give_memory(char *str, int words_num)
{
	char	**array;
	int		first;
	int		i;
	int		j;
	int		k;

	array = (char**)malloc(sizeof(char*) * (words_num + 1));
	if (*str == '\0')
		return (array);
	first = 0;
	i = 0;
	while (str[first] != '\0' && (str[first] == ' ' || str[first] == '\t'  || str[first] == '\n'))
		first++;
	i = first;
	j = 0;
	k = 0;
	while(str[i] != '\0')
	{
		if (str[i] != '\0' && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
		{
			j = 1;
			i++;
			while (str[i] != '\0' && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
			{
				i++;
				j++;
			}
			array[k] = (char*)malloc(sizeof(char) * (j + 1));
			k++;
		}
		i++;
		k++;
	}
	array[k] = (char*)malloc(sizeof(char) * 1);
	return (array);
}

char	**ft_split_whitespaces(char *str)
{
	int		words_num;
	char	**array;
	int i = 0;
	int first = 0;
	int j = 0;
	int k = 0;

	words_num = words_counter(str);
	array = give_memory(str, words_num);
	while (str[first] != '\0' && (str[first] == ' ' || str[first] == '\t'  || str[first] == '\n'))
		first++;
	i = first;
	while (str[i] != '\0')
	{
		if (str[i] != '\0' && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
		{
			j = 0;
			array[k][j] = str[i];
			i++;
			while (str[i] != '\0' && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
			{
				j++;
				array[k][j] = str[i];
				i++;
			}
			k++;
		}
		i++;
	}
	return (array);
}
