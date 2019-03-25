/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 18:54:18 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/03 19:22:33 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);
void	ft_putchar(char c);

void	print_first_line(int x, char angle, char middle)
{
	int j;

	j = x;
	ft_putchar(angle);
	j--;
	while (j > 1)
	{
		ft_putchar(middle);
		j--;
	}
	if (j > 0)
	{
		ft_putchar(angle);
	}
	ft_putchar('\n');
}

void	print_middle(int x, int y, char middle)
{
	int j;

	j = x;
	while (y > 1)
	{
		j = x;
		ft_putchar(middle);
		j--;
		while (j > 1)
		{
			ft_putchar(' ');
			j--;
		}
		if (j > 0)
		{
			ft_putchar(middle);
		}
		ft_putchar('\n');
		y--;
	}
}

void	rush(int x, int y)
{
	print_first_line(x, 'A', 'B');
	y--;
	if (y > 0)
	{
		print_middle(x, y, 'B');
	}
	if (y > 0)
	{
		print_first_line(x, 'C', 'B');
	}
}
