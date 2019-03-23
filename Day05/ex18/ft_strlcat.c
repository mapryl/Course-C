/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:30:52 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/05 16:58:49 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	res;
	unsigned int	k;

	i = 0;
	while (i < size && dest[i] != '\0')
		i++;
	k = 0;
	while (src[k] != '\0')
		k++;
	if (i == size)
		return (size + k);
	res = i + k;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (res);
}
