/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:05:52 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/08 23:31:09 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_par.h"

int						ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i++] != '\0')
		;
	return (i - 1);
}

char					*ft_strdup(const char *str)
{
	int		str_size;
	char	*copy;
	int		i;

	str_size = ft_strlen(str);
	copy = (char*)malloc(sizeof(char) * (str_size + 1));
	i = 0;
	while ((copy[i] = str[i]) != '\0')
		i++;
	return (copy);
}

struct	s_stock_par		*ft_param_to_tab(int ac, char **av)
{
	t_stock_par	*result;
	int			i;

	result = (t_stock_par*)malloc(sizeof(t_stock_par) * (ac + 1));
	i = 0;
	while (i < ac)
	{
		result[i].size_param = ft_strlen(av[i]);
		result[i].str = av[i];
		result[i].copy = ft_strdup(av[i]);
		result[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	result[i].size_param = 0;
	result[i].str = 0;
	result[i].copy = 0;
	result[i].tab = 0;
	return (result);
}
