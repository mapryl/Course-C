/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 23:50:21 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/08 00:00:57 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base != 1)
	{
		if (base % 2 == 0)
			return (1 + ft_collatz_conjecture(base / 2));
		else
			return (1 + ft_collatz_conjecture(3 * base + 1));
	}
	return (0);
}
