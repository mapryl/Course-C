/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:47:51 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/05 21:51:32 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	j;
	unsigned int	i;

	j = 0;
	while (src[j] != '\0')
		j++;
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (j);
}
