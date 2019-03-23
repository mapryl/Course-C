/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:11:05 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/08 23:31:48 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_par.h"

void	ft_putchar(char c);

void	ft_putstr(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i++]);
	}
}

void	ft_putnbr(int nbr)
{
	if (nbr > 10)
	{
		ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
	else
		ft_putchar(nbr % 10 + '0');
}

void	ft_show_tab(struct s_stock_par *par)
{
	int i;
	int j;

	i = 0;
	while (par[i].str != '\0')
	{
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		ft_putnbr(par[i].size_param);
		ft_putchar('\n');
		j = 0;
		while (par[i].tab[j] != 0)
		{
			ft_putstr(par[i].tab[j]);
			ft_putchar('\n');
			j++;
		}
		i++;
	}
}
