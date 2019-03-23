/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:28:03 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/12 18:05:10 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int *array;
	int i;

	i = 0;
	array = (int *)malloc(sizeof(int) * length);
	while (i < length)
	{
		array[i] = (*f)(tab[i]);
		i++;
	}
	return (array);
}
