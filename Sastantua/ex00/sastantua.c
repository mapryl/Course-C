/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 22:54:38 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/03 23:02:08 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		calc_base_length(int n)
{
	int cur_level_hight;
	int cur_hight;
	int cur_length;
	int i;

	cur_level_hight = 3;
	cur_hight = 1;
	cur_length = 1;
	i = 1;
	while (1)
	{
		cur_hight += 1;
		cur_length += 2;
		if (cur_hight == cur_level_hight)
		{
			if (++i > n)
				return (cur_length + 2);
			cur_hight = 1;
			cur_level_hight += 1;
			cur_length += 6;
		}
	}
}

void	put_n_char(char ch, int n)
{
	int i;

	i = 0;
	while (i++ < n)
	{
		ft_putchar(ch);
	}
}

void	print_pyramid_row(int i, int n, int *p)
{
	int door_begin_left;

	if (i == n && p[4] > p[1])
	{
		ft_putchar('/');
		door_begin_left = (p[5] - 2 - p[2]) / 2;
		put_n_char('*', door_begin_left);
		if (n >= 5 && p[4] - p[1] == p[2] / 2 + 1)
		{
			put_n_char('|', p[2] - 2);
			ft_putchar('$');
			ft_putchar('|');
		}
		else
			put_n_char('|', p[2]);
		put_n_char('*', door_begin_left);
		ft_putchar('\\');
	}
	else
	{
		ft_putchar('/');
		put_n_char('*', p[5] - 2);
		ft_putchar('\\');
	}
	ft_putchar('\n');
}

void	init_pyramid(int *pyramid, int n)
{
	pyramid[0] = calc_base_length(n);
	if (n % 2 == 1)
	{
		pyramid[2] = n;
		pyramid[1] = 2;
	}
	else
	{
		pyramid[2] = n - 1;
		pyramid[1] = 3;
	}
	pyramid[3] = 3;
	pyramid[4] = 0;
	pyramid[5] = 1;
}

void	sastantua(int n)
{
	int i;
	int pyramid[6];
	int offset;

	if (n <= 0)
		return ;
	i = 1;
	init_pyramid(pyramid, n);
	while (1)
	{
		pyramid[4]++;
		pyramid[5] += 2;
		offset = (pyramid[0] - pyramid[5]) / 2;
		put_n_char(' ', offset);
		print_pyramid_row(i, n, pyramid);
		if (pyramid[4] == pyramid[3])
		{
			if (++i > n)
				return ;
			pyramid[4] = 0;
			pyramid[5] += 4;
			pyramid[3] += 1;
		}
	}
}
