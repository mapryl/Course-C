/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 21:27:47 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/01 22:00:09 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while ((str[i] >= '0' && str[i] <= '9') ||
			(i == 0 && (str[i] == '-' || str[i] == '+')))
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		n = 10 * n + (str[i] - '0');
		i++;
	}
	if (str[0] == '-')
		n *= -1;
	return (n);
}
