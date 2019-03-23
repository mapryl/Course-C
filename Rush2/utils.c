#include "utils.h"

#include "stream.h"
char *ft_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;
	char *s1_n;
	char *s2_n;

	s1_n = s1;
	s2_n = s2;
	i = 0;
	while (s1_n[i] != '\0' && s2_n[i] != '\0')
	{
		if (s1_n[i] != s2_n[i])
			return (s1_n[i] - s2_n[i]);
		i++;
	}
	if ((s1_n[i] == '\0' && s2_n[i] != '\0') || (s2_n[i] == '\0' && s1_n[i] != '\0'))
		return (s1_n[i] - s2_n[i]);
	return (0);
}

#include <iostream>
void ft_putchar(char c)
{
	if (g_output_stream == 0)
		std::cout.put(c); 	//write(1, &c, 1);
	else
		stream_put(g_output_stream, c);
}

void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

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