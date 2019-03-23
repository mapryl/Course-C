/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:30:01 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/12 13:34:26 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	first;
	int	i;
	int	result;
	int	sign;

	first = 0;
	while (str[first] != '\0' && (str[first] == ' ' || str[first] == '\t' ||
				str[first] == '\r' || str[first] == '\n'))
		first++;
	i = first;
	result = 0;
	sign = 1;
	if (str[first] == '-' || str[first] == '+')
	{
		if (str[first] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && ((str[i] >= '0' && str[i] <= '9')))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	result *= sign;
	return (result);
}
