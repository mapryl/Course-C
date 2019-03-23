/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 21:07:19 by mapryl            #+#    #+#             */
/*   Updated: 2019/02/28 23:06:33 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const char g_set[] = {'0' , '1', '2', '3', '4', '5', '6' , '7' , '8' , '9'};
const :int g_set_size = 10;
char g_buf[10];
int g_buf_cur_pos = 0;

void	print_buf()
{
	int i;

	i = 0;

	while( i < g_buf_cur_pos )
	{
		ft_putchar( g_buf[i++] );
	}
}

int	is_last_one()
{
	int i;

	i = g_buf_cur_pos - 1;
	if (g_buf[i] != g_set[g_set_size - 1])
	{
		return (0);
	}
	while (i > 0)
	{
		if (g_buf[i] - g_buf[i - 1] != 1)
		{
			return (0);
		}
		--i;
	}
	return (1);
}

void	take_one(int left_bound, int chars_to_take)
{
	while( left_bound < g_set_size )
	{
		g_buf[g_buf_cur_pos++] = g_set[left_bound];
		if( chars_to_take - 1 > 0 )
		{
			take_one( left_bound + 1, chars_to_take - 1);
		}
		else
		{
			print_buf();
			if (!is_last_one())
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
		++left_bound;
		--g_buf_cur_pos;
		if(chars_to_take - 1 > g_set_size - left_bound)
		{
			return();
		}
	}
}

void	ft_print_comb(int n)
{
	int left_bound = 0;
	take_one(left_bound, n);
}
