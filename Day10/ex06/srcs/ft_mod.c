/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:36:41 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/12 13:59:07 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_mod(int a, int b)
{
	if (b == 0)
		return (0);
	return (a % b);
}
