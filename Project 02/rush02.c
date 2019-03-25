#include "rush02.h"
#include "utils.h"

void print_first_line02(int x, char angle, char middle)
{
	int j = x;
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

void print_middle02(int x, int y, char middle)
{
	int j = x;
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


void rush02(int x, int y)
{
	if (x <= 0 || y <= 0)
		return;
	print_first_line02(x, 'A', 'B');
	y--;
	if (y > 0)
	{
		print_middle02(x, y, 'B');
	}
	if (y > 0)
	{
		print_first_line02(x, 'C', 'B');
	}
}
