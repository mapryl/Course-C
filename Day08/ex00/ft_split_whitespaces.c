/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 16:52:32 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/08 23:40:40 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_space(char ch)
{
	return (ch == ' ' || ch == '\t' || ch == '\n');
}

int		next_word(char *str, int pos)
{
	while (is_space(str[pos]))
		pos++;
	if (str[pos] != '\0')
		return (pos);
	else
		return (-1);
}

int		read_word(char *str, int pos)
{
	while (str[pos] != '\0' && !is_space(str[pos]))
		pos++;
	return (pos);
}

int		count_words(char *str)
{
	int pos;
	int words;

	pos = 0;
	words = 0;
	while ((pos = next_word(str, pos)) != -1)
	{
		words++;
		pos = read_word(str, pos);
	}
	return (words);
}

char	**ft_split_whitespaces(char *str)
{
	int		cur_word;
	int		pos;
	int		word_end;
	int		j;
	char	**words;

	j = count_words(str);
	words = (char**)malloc(sizeof(char*) * (j + 1));
	cur_word = 0;
	pos = 0;
	while ((pos = next_word(str, pos)) != -1)
	{
		word_end = read_word(str, pos);
		words[cur_word] = (char*)malloc(sizeof(char) * (word_end - pos + 1));
		j = 0;
		while (pos != word_end)
			words[cur_word][j++] = str[pos++];
		words[cur_word++][j] = '\0';
	}
	words[cur_word] = (char*)malloc(sizeof(char) * (1));
	words[cur_word] = 0;
	return (words);
}
