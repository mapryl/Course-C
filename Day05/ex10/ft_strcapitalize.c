/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:56:59 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/05 21:08:25 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_alpha(char str)
{
	if ((str >= 'a' && str <= 'z') || (str >= 'A' && str <= 'Z'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	unsigned int i;

	i = 1;
	while (str[i] != '\0')
	{
		if (is_alpha(str[i]))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= ('a' - 'A');
			i++;
		}
		while (is_alpha(str[i]) || (str[i] >= '0' && str[i] <= '9'))
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += ('a' - 'A');
			i++;
		}
		i++;
	}
	return (str);
}
