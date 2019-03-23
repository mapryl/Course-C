/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative.power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:10:38 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/04 14:34:44 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int ft_iterative_power(int nb, int power);

int main(void)
{
	int a = ft_iterative_power(3,2);
		printf("%d\n", a);
}
int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	i = 1;
	result = nb;
	while (i < power)
	{
		result *= nb;
		i++;
	}
	return (result);
}
