/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:04:17 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/02 18:10:03 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if ((nb < 0) || (nb > 13))
	{
		return (0);
	}
	if (nb < 2)
	{
		return (1);
	}
	return (nb * ft_recursive_factorial(nb - 1));
}
