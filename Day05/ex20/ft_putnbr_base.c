/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:59:47 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/05 21:57:33 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar (char c);
int		base_length_f(char *base);
void	ft_putnbr_base(int nbr, char *base);

int		base_length_f(char *base)
{
	int base_length;
	int j;

	base_length = 0;
	while (base[base_length] != '\0')
	{
		if ((base[base_length] < '0' || base[base_length] > '9') &&
				(base[base_length] < 'a' || base[base_length] > 'z') &&
				(base[base_length] < 'A' || base[base_length] > 'Z'))
			return (-1);
		j = base_length + 1;
		while (base[j] != '\0')
		{
			if (base[base_length] == base[j])
				return (-1);
			j++;
		}
		base_length++;
	}
	return (base_length);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	nbr_new;
	int			base_length;

	nbr_new = nbr;
	base_length = base_length_f(base);
	if (base_length <= 1)
		return ;
	if (nbr < 0)
	{
		nbr_new *= -1;
		ft_putchar('-');
	}
	if (nbr_new / base_length != 0)
	{
		ft_putnbr_base(nbr_new / base_length, base);
		ft_putnbr_base(nbr_new % base_length, base);
	}
	else
		ft_putchar(base[nbr_new % base_length]);
}
