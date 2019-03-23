/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:54:07 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/02 18:02:52 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int i;
	int result;

	i = 0;
	result = 1;
	if (nb < 0 || nb > 13)
	{
		return (0);
	}
	while (i < nb)
	{
		i++;
		result = result * i;
		if (result < 0)
		{
			return (0);
		}
	}
	return (result);
}
