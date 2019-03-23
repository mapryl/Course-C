/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:42:52 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/13 16:48:18 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int		length;
	t_list	*current;

	current = begin_list;
	length = 0;
	while (current != 0)
	{
		length++;
		current = current->next;
	}
	return (length);
}
