#include <unistd.h>
#include "utils.h"
#include "calculator.h"

int eval_expr(char* str)
{
	return (eval_expr_recursive(&str));
}

int main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}

	return (0);
}