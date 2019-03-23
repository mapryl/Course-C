/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:57:33 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/07 16:38:12 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}

	*range = (int*)malloc(sizeof(int)*(max - min));
	i = 0;
	while (min < max)
	{
		range[0][i] = min;
		i++;
		min++;
	}
	return (max - min);
}
