#include <unistd.h>
#include "utils.h"

void	ft_putnbr(int nb)
{
	long long nb_new;

	nb_new = nb;
	if (nb_new < 0)
	{
		ft_putchar('-');
		nb_new = -nb_new;
	}
	if (nb_new >= 10)
	{
		ft_putnbr(nb_new / 10);
		ft_putnbr(nb_new % 10);
	}
	else
	{
		ft_putchar(nb_new + '0');
	}
}

void ft_putchar (char c)
{
    write(1, &c, 1);
}

void ignore_whitespace(char** str)
{
	while (**str != '\0' && (**str == ' ' || **str == '\t' || **str == '\r' || **str == '\n'))
		(*str)++;
}

int	ft_atoi(char **str)
{
	int	result;
	int	sign;

	ignore_whitespace(str);
	result = 0;
	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	while (**str != '\0' && ((**str >= '0' && **str <= '9')))
	{
		result = (result * 10) + (**str - '0');
		(*str)++;
	}
	return (result*sign);
}
