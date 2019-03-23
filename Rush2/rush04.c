#include "rush04.h"
#include "utils.h"

void print_first_line04(int x, char left_angle, char middle, char right_angle)
{
	int j = x;
	ft_putchar(left_angle);
	j--;
	while (j > 1)
	{
		ft_putchar(middle);
		j--;
	}
	if (j > 0)
	{
		ft_putchar(right_angle);
	}
	ft_putchar('\n');
}

void print_middle04(int x, int y, char middle)
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

void rush04(int x, int y)
{
	if (x <= 0 || y <= 0)
		return;
	print_first_line04(x, 'A', 'B', 'C');
	y--;
	if (y > 0)
	{
		print_middle04(x, y, 'B');
	}
	if (y > 0)
	{
		print_first_line04(x, 'C', 'B', 'A');
	}
}
