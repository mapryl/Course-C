/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:59:06 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/05 22:35:00 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi_base(char *str, char *base);
int		base_length_f(char *base);
int		ft_atoi(char *str, char *base, int str_len, int base_length);
int		find(char str, char *base);
int		pw(int nb, int power);
int g_rs = 0;
int g_sign = 1;

int		ft_atoi_base(char *str, char *base)
{
	int base_length;
	int str_len;
	int nbr;

	str_len = 0;
	base_length = base_length_f(base);
	if (base_length <= 1)
		return (0);
	while (str[str_len] != '\0')
	{
		str_len++;
	}
	nbr = ft_atoi(str, base, str_len, base_length);
	return (nbr);
}

int		ft_atoi(char *str, char *base, int str_len, int base_length)
{
	int i;
	int j;

	j = 0;
	while (str[j] != '\0' && (str[j] == ' ' || str[j] == '\t'
				|| str[j] == '\r' || str[j] == '\n'))
		j++;
	i = j;
	if (str[j] == '-' || str[j] == '+')
	{
		if (str[j] == '-')
			g_sign = -1;
		str_len -= 1;
		i++;
	}
	j = 0;
	while (str[i] != '\0' && ((str[i] >= '0' && str[i] <= '9') ||
		(str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
	{
		g_rs = g_rs + find(str[i], base) * pw(base_length, (str_len - 1) - j);
		i++;
		j++;
	}
	return (g_rs * g_sign);
}

int		base_length_f(char *base)
{
	int base_length;
	int j;

	base_length = 0;
	while (base[base_length] != '\0')
	{
		if ((base[base_length] < '0' || base[base_length] > 'Z') &&
				(base[base_length] < 'a' || base[base_length] > 'z'))
			return (-1);
		j = base_length + 1;
		while (base[j] != '\0')
		{
			if (base[base_length] == base[j])
				return (-1);
			j++;
		}
		base_length++;
	}
	return (base_length);
}

int		find(char str, char *base)
{
	unsigned int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == str)
			return (i);
		i++;
	}
	return (-1);
}

int		pw(int nb, int power)
{
	int	i;
	int	result;

	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	i = 1;
	result = nb;
	while (i < power)
	{
		result *= nb;
		i++;
	}
	return (result);
}
