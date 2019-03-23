#include "rush01.h"
#include "utils.h"

void print_first_line01(int x, char left_angle, char middle, char right_angle)
{
	int j;

	j = x;
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

void print_middle01(int x, int y, char middle)
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

void rush01(int x, int y)
{
	if (x <= 0 || y <= 0)
		return;
	print_first_line01(x, '/', '*', '\\');
	y--;
	if (y > 0)
	{
		print_middle01(x, y, '*');
	}
	if (y > 0)
	{
		print_first_line01(x, '\\', '*', '/');
	}
}
