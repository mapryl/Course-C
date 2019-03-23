/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:59:46 by mapryl            #+#    #+#             */
/*   Updated: 2019/03/13 17:03:15 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list *node;

	if (begin_list == 0)
		return (0);
	node = begin_list;
	while (node->next != 0)
	{
		node = node->next;
	}
	return (node);
}
