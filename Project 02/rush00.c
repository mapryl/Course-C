#include "rush00.h"
#include "utils.h"

void print_first_line00(int x, char angle, char middle)
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

void print_middle00(int x, int y, char middle)
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

void rush00(int x, int y)
{
	if (x <= 0 || y <= 0)
		return;
	print_first_line00(x, 'o', '-');
	y--;
	if (y > 0 && x > 0)
	{
		print_middle00(x, y, '|');
	}
	if (y > 0 && x > 0)
	{
		print_first_line00(x, 'o', '-');
	}
}
