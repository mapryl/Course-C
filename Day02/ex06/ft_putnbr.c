/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 12:49:46 by mapryl            #+#    #+#             */
/*   Updated: 2019/02/28 21:06:20 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	long long nb_new;

	nb_new = nb;
	if (nb_new < 0)
	{
		ft_putchar('-');
		nb_new = -nb_new;
	}
	if (nb_new >= 10)
	{
		ft_putnbr(nb_new / 10);
		ft_putnbr(nb_new % 10);
	}
	else
	{
		ft_putchar(nb_new + '0');
	}
}
