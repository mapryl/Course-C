/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:23:20 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/07 17:48:35 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	letter(int hour)
{
	char let;

	if (hour >= 12 && hour <= 23)
		let = 'P';
	else
		let = 'A';
	return (let);
}

int		time(int hour)
{
	int tm;

	if (hour % 12 == 0)
		tm = 12;
	else
		tm = hour % 12;
	return (tm);
}

void	ft_takes_place(int hour)
{
	if (hour < 0 || hour > 23)
		return ;
	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	printf("%d.00 %c.M. AND ", time(hour), letter(hour));
	hour++;
	printf("%d.00 %c.M.\n ", time(hour), letter(hour));
}
