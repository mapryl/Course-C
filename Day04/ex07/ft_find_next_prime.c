/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 20:40:01 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/02 22:39:01 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime(int nb);
int	ft_find_next_prime(int nb);

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
	{
		return (2);
	}
	while (!(is_prime(nb)))
	{
		nb += 1;
	}
	return (nb);
}

int	is_prime(int nb)
{
	int i;

	i = 2;
	while (i <= nb / 2)
	{
		if (nb % i == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
